// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SecondaryWeapon.h"
#include "PhaseWeapon.generated.h"

/**
 * 
 */
UCLASS()
class ACCELERATE_API APhaseWeapon : public ASecondaryWeapon
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	APhaseWeapon();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Phase Weapon")
	void Fire() override;
	
public:
	UPROPERTY(EditAnywhere, Category = "PhaseTimer")
	float mTimer{ 3.0f };
};
