//// Fill out your copyright notice in the Description page of Project Settings.
//
//#include "Hook.h"
//#include "AcceleratePlayer.h"
//
//AHook::AHook()
//{
//	PrimaryActorTick.bCanEverTick = true;
//	mHookCollider = CreateDefaultSubobject<UBoxComponent>(TEXT("HookCollider"));
//	mHookCollider->DetachFromComponent(FDetachmentTransformRules::KeepWorldTransform);
//	mHookCollider->SetNotifyRigidBodyCollision(true);
//	mHookCollider->SetHiddenInGame(true);
//	mHookCollider->SetWorldScale3D(FVector(2.0f));
//	mHookCollider->SetNotifyRigidBodyCollision(true);
//	mHookCollider->BodyInstance.SetCollisionProfileName(TEXT("OverlapAll"));
//	mHookCollider->OnComponentBeginOverlap.AddDynamic(this, &AHook::OnOverlapBegin);
//}
//
//void AHook::BeginPlay()
//{
//	Super::BeginPlay();
//}
//
//void AHook::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//	FVector newHookLocation{ 0.0f };
//	if (mIsActive)
//	{
//		newHookLocation = mHookCollider->GetComponentLocation();
//		newHookLocation += mFireDirection * hookTravelSpeed * DeltaTime;
//		mHookCollider->SetRelativeLocation(newHookLocation);
//	}
//}
//
//void AHook::Fire()
//{
//	if (mIsActive)//Retract
//	{
//		mIsActive = false;
//		mHookCollider->SetHiddenInGame(true);
//		if (mHookedPlayer)
//		{
//			mHookedPlayer->EndHook();
//		}
//		mHookedPlayer = nullptr;
//		FVector oldScale = mHookCollider->GetRelativeTransform().GetScale3D();
//		mHookCollider->SetWorldTransform(GetActorTransform());
//		mHookCollider->SetWorldScale3D(oldScale);
//		mHookCollider->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepWorldTransform);
//	}
//	else//Fire
//	{
//		mIsActive = true;
//		mHookCollider->SetHiddenInGame(false);
//		mFireDirection = mHookCollider->GetForwardVector();
//		mHookCollider->DetachFromParent(true);
//		FVector newHookPos = mHookCollider->GetComponentLocation();
//		newHookPos += mFireDirection * 400.0f;
//		mHookCollider->SetWorldLocation(newHookPos);
//	}
//}
//
//void AHook::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
//	class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	if (OtherActor->IsA(AAcceleratePlayer::StaticClass()) && mIsActive)
//	{
//		mHookedPlayer = static_cast<AAcceleratePlayer*>(OtherActor);
//		mHookedPlayer->StartHook(hookPullSpeed, hookPullDuration);
//		mHookCollider->SetHiddenInGame(true);
//	}
//}