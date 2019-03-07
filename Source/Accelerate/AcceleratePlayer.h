// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Car.h"
#include "PrimaryWeaponTypes.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "FlameThrower.h"
#include "LaserBlaster.h"
#include "HomingWeapon.h"
#include "PickupTypes.h"
#include "AcceleratePlayer.generated.h"

DECLARE_LOG_CATEGORY_EXTERN(LogAcceleratePlayer, Log, All);

class APrimaryWeapon;
class ASecondaryWeapon;
class UBoxComponent;
/**
 *
 */
UCLASS()
class ACCELERATE_API AAcceleratePlayer : public ACar
{
	GENERATED_BODY()

public:
	AAcceleratePlayer();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION(BlueprintCallable, Category = "AcceleratePlayer")
	void ReceiveDamage(float damage);

	UFUNCTION(BlueprintCallable, Category = "AcceleratePlayer")
	void ReduceBoost(float boost);

	UFUNCTION(BlueprintCallable, Category = "AcceleratePlayer")
	void IncreaseBoost(float boost);

	UFUNCTION(BlueprintCallable, Category = "AcceleratePlayer")
	void IncreaseHealth(float health);

	UFUNCTION(BlueprintCallable, Category = "AcceleratePlayer")
	void FirePrimaryWeapon(float value);

	UFUNCTION(BlueprintCallable, Category = "AcceleratePlayer")
	void FireSecondaryWeapon();

	void Respawn() { Health = 0.0f; }

	UFUNCTION(BlueprintCallable, Category = "AcceleratePlayer")
	void CreatePrimaryWeapon(EPrimaryWeaponTypes weaponType);

	void CreateSecondaryWeapon(EPickupTypes secondaryType, uint32_t ammo);

	void CreateWeaponPickupTest();

	void SetBoostFromPickup(float boost);

	void SetHealthFromPickup(float health);

	//Move this function to BattleManager
	UFUNCTION(BlueprintCallable, Category = "Points System")
	void AddPoints(float points);

	UFUNCTION(BlueprintCallable, Category = "Points System")
	float GetPlayerPoints();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerBase")
	float Health;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerBase")
	float MaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerBase")
	float Boost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerBase")
	float MaxBoost;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerBase")
	USceneComponent* mBaseWeaponLoc;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerBase")
	APrimaryWeapon* mPrimaryWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerBase")
	ASecondaryWeapon* mSecondaryWeapon;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* rammingCollision;

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "RammingProperties")
	float rammingCooldown{ 3.0f };

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "RammingProperties")
	float rammingBoostReward{ 10.0f };

	UPROPERTY(EditAnywhere, BluePrintReadWrite, Category = "RammingProperties")
	float rammingHealthMaxDamage{ 50.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerBase")
	bool isShieldActive = false;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ALaserBlaster> laserBlasterRef;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AFlameThrower> flameThrowerRef;

	//Secondary Weapons refs
	UPROPERTY(EditAnywhere)
	TSubclassOf<class AHomingWeapon> homingWeaponRef;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AHomingWeapon> MineRef;

private:	
	float mPlayerPoints = 0.0f;
};