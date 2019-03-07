// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PrimaryDefensiveWeapon.generated.h"

/**
 *
 */

UCLASS()
class ACCELERATE_API APrimaryDefensiveWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APrimaryDefensiveWeapon();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void FireDefensive();
	
	UFUNCTION(BlueprintCallable, Category = "Deffensive Weapon Callable Function")
	void SetCanShoot(bool canShoot);

	UFUNCTION(BlueprintCallable, Category = "Deffensive Weapon Callable Function")
	void SetIsActive(bool isactive);

private:
	void CoolDownRecharge();

public:
	float currentCooldown;
	float maxCooldown;

private:
	bool mCanShoot;
	bool mIsActive;
};
