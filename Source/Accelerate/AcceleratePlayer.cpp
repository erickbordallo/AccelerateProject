// Fill out your copyright notice in the Description page of Project Settings.

#include "AcceleratePlayer.h"
#include "SecondaryWeapon.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "Components/BoxComponent.h"
#include "Engine/Classes/Components/InputComponent.h"
#include "Engine/Classes/Components/SceneComponent.h"
#include "Kismet/KismetMathLibrary.h"

DEFINE_LOG_CATEGORY(LogAcceleratePlayer);

AAcceleratePlayer::AAcceleratePlayer()
	: Health(100.0f)
	, Boost(100.0f)
	, MaxHealth(100.0f)
	, MaxBoost(100.0f)
	, mPrimaryWeapon(nullptr)
	, mSecondaryWeapon(nullptr)
{
	rammingCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("RammingCollider"));
	rammingCollision->SetSimulatePhysics(false);
	rammingCollision->SetNotifyRigidBodyCollision(true);
	rammingCollision->BodyInstance.SetCollisionProfileName(TEXT("OverlapAll"));

	mBaseWeaponLoc = CreateDefaultSubobject<USceneComponent>(TEXT("BaseWeaponLoc"));
}

// Called to bind functionality to input
void AAcceleratePlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	InputComponent->BindAxis("FirePrimaryWeapon", this, &AAcceleratePlayer::FirePrimaryWeapon);
	InputComponent->BindAction("FireSecondaryWeapon", EInputEvent::IE_Pressed, this, &AAcceleratePlayer::FireSecondaryWeapon);
	InputComponent->BindAction("Respawn", EInputEvent::IE_Pressed, this, &AAcceleratePlayer::Respawn);
	InputComponent->BindAction("SpawnSecondaryWeaponTest", EInputEvent::IE_Pressed, this, &AAcceleratePlayer::CreateWeaponPickupTest);
}

void AAcceleratePlayer::BeginPlay()
{
	Super::BeginPlay();
	//Ty's code should be moved to a ramming class------------------------------------------------
	rammingCollision->SetEnableGravity(false);
	rammingCollision->bHiddenInGame = true;
	rammingCollision->OnComponentBeginOverlap.AddDynamic(this, &AAcceleratePlayer::OnOverlapBegin);
	//---------------------------------------------------------------------------------------------
}

void AAcceleratePlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//Ty's code should be moved to a ramming class------------------------------------------------
	FTransform rammingCollisionTransform = GetActorTransform();
	FVector rammingCollisionLocation = rammingCollisionTransform.GetLocation();
	rammingCollisionLocation.Z += 30.0f;
	FVector carFowardDirection = GetActorForwardVector();
	carFowardDirection.Normalize();
	rammingCollisionLocation += carFowardDirection * 50.0f;
	rammingCollisionTransform.SetLocation(rammingCollisionLocation);
	rammingCollisionTransform.SetScale3D(FVector(8.0f, 3.0f, 2.0f));
	rammingCollision->SetWorldTransform(rammingCollisionTransform);
	//---------------------------------------------------------------------------------------------
}

void AAcceleratePlayer::ReceiveDamage(float damage)
{
	//Check if the shield is not active
	if (!isShieldActive)
	{
		Health -= damage;
		if (Health < 0.0f)
		{
			Health = 0.0f;
		}
	}
	//--------------------------------------
}

void AAcceleratePlayer::ReduceBoost(float boost)
{
	//Max's code should be moved to a different class
	Boost -= boost;
	if (Boost < 0.0f)
	{
		Boost = 0.0f;
	}
	//----------------------------------------------
}

void AAcceleratePlayer::IncreaseHealth(float health)
{
	Health += health;
	if (Health > MaxHealth)
	{
		Health = MaxHealth;
	}
}

void AAcceleratePlayer::IncreaseBoost(float boost)
{
	Boost += boost;
	if (Boost > MaxBoost)
	{
		Boost = MaxBoost;
	}
}

void AAcceleratePlayer::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(AAcceleratePlayer::StaticClass()) && OtherActor != this)
	{
		AAcceleratePlayer* otherCar = (AAcceleratePlayer*)OtherActor;
		if (otherCar->GetRammingColor() == GetRammingColor() && GetCanRam())
		{
			FVector player1Foward, player2Forward;
			player1Foward = GetActorForwardVector();
			player2Forward = OtherActor->GetActorForwardVector();
			player1Foward.Normalize();
			player2Forward.Normalize();
			FVector aD = (player1Foward + player2Forward) / 2.0f;
			aD *= 100.0f;
			FVector tempLocation = GetActorLocation();
			//Calculate Distance of each car to the foward direction
			float thisCarsDistance = abs(FMath::Sqrt(FMath::Square(aD.X - tempLocation.X) +
				FMath::Square(aD.Y - tempLocation.Y) + FMath::Square(aD.Z - tempLocation.Z)));

			tempLocation = OtherActor->GetActorLocation();
			float otherCarsDistance = abs(FMath::Sqrt(FMath::Square(aD.X - tempLocation.X) +
				FMath::Square(aD.Y - tempLocation.Y) + FMath::Square(aD.Z - tempLocation.Z)));

			if (thisCarsDistance > otherCarsDistance)
			{
				//This car does damage and takes boost
				IncreaseBoost(rammingBoostReward);
			}
			else
			{
				//car takes damage and other car gets boost
				float damage = (abs(otherCar->GetCurrentSpeedOfCar() - mCurrentSpeed) / mMaxSpeed) * rammingHealthMaxDamage;
				ReceiveDamage(damage);
			}

			SetCanRam(false);

			FTimerDelegate SetRamDelegate = FTimerDelegate::CreateUObject(this, &AAcceleratePlayer::SetCanRam, true);
			FTimerHandle TimerHandle;

			GetWorldTimerManager().SetTimer(TimerHandle, SetRamDelegate, 1.0f, false, rammingCooldown);
		}
	}
}

void AAcceleratePlayer::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}


void AAcceleratePlayer::FirePrimaryWeapon(float value)
{
	//Fires any primary weapon holded by the player
	if (mPrimaryWeapon)
	{
		mPrimaryWeapon->Fire(value);
	}
	//---------------------------------------------
}

void AAcceleratePlayer::FireSecondaryWeapon()
{
	//Fires any pickup weapon holded by the player
	if (mSecondaryWeapon)
	{
		mSecondaryWeapon->Fire();
	}
	//--------------------------------------------
}

//Creates the main weapon passed by the manager---------------------------------------------
void AAcceleratePlayer::CreatePrimaryWeapon(EPrimaryWeaponTypes weaponType)
{
	FActorSpawnParameters params;
	params.Owner = this;

	switch (weaponType)
	{
	case EPrimaryWeaponTypes::LaserBlaster:
	{
		mPrimaryWeapon = GetWorld()->SpawnActor<ALaserBlaster>(laserBlasterRef->GetAuthoritativeClass(), params);
		break;
	}
	case EPrimaryWeaponTypes::Flamethrower:
	{
		mPrimaryWeapon = GetWorld()->SpawnActor<AFlameThrower>(flameThrowerRef->GetAuthoritativeClass(), params);
		break;
	}
	default:
	{
		break;
	}
	}

	FAttachmentTransformRules rules{ EAttachmentRule::SnapToTarget, true };
	mPrimaryWeapon->AttachToComponent(Mesh, rules, TEXT("SK_PrimaryWeapon"));
}
//-----------------------------------------------------------------------------------------------------------

//Creates a pickup to player---------------------------------------------------------------------------------
void AAcceleratePlayer::CreateSecondaryWeapon(EPickupTypes secondaryType, uint32_t ammo)
{
	FActorSpawnParameters params;
	params.Owner = this;
	switch (secondaryType)
	{
	case EPickupTypes::Missle:
		//Destroy the current weapon-------
		if (mSecondaryWeapon)
		{
			mSecondaryWeapon->Destroy();
		}
		//---------------------------------
		//Creates a new one
		mSecondaryWeapon = GetWorld()->SpawnActor<AHomingWeapon>(homingWeaponRef->GetAuthoritativeClass(), params);
		if (mSecondaryWeapon)
		{
			mSecondaryWeapon->SetAmmo(ammo);
		}
		mSecondaryWeapon->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform, TEXT("SK_HomingWeapon"));

		break;
	case EPickupTypes::Hook:
		break;
	case EPickupTypes::Mine:
		/*if (mSecondaryWeapon)
		{
			mSecondaryWeapon->Destroy();
		}
		mSecondaryWeapon = GetWorld()->SpawnActor<AMine>(homingWeaponRef->GetAuthoritativeClass(), params);
		if (mSecondaryWeapon)
		{
			mSecondaryWeapon->SetAmmo(ammo);
		}
		mSecondaryWeapon->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform, TEXT("SK_Mine"));
*/

		break;
	case EPickupTypes::EMP:
		break;
	default:
		break;
	}
}
//---------------------------------------------------------------------------------------------------------------

void AAcceleratePlayer::SetBoostFromPickup(float boost)
{
	if (boost <= this->mBoostMax)
	{
		this->mBoostCurrent += boost;
		if (this->mBoostCurrent >= this->mBoostMax)
		{
			this->mBoostCurrent = this->mBoostMax;
		}
	}
}

void AAcceleratePlayer::SetHealthFromPickup(float health)
{
	if (health <= MaxHealth)
	{
		Health += health;
		if (Boost >= MaxHealth)
		{
			Boost = MaxHealth;
		}
	}
}

//Test functions - Remove on post production
void AAcceleratePlayer::CreateWeaponPickupTest()
{
	CreateSecondaryWeapon(EPickupTypes::Missle, 3);
}


//Going to the battle manager
void AAcceleratePlayer::AddPoints(float points)
{
	mPlayerPoints += points;
}

//Batte manager
float AAcceleratePlayer::GetPlayerPoints()
{
	return mPlayerPoints;
}