// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AICheckpoint.h"
#include <vector>
#include "AIPlayerController.generated.h"


constexpr int MAX_AI = 11;

UENUM()
enum class AIPlayerActions
{
	Left	UMETA(DisplayName = "Left"),
	Right	UMETA(DisplayName = "Right"),
	Nothing	UMETA(DisplayName = "Nothing"),
};

/**
 *
 */

UCLASS()
class ACCELERATE_API AAIPlayerController : public AActor
{
	GENERATED_BODY()
	
public:	

	// Sets default values for this actor's properties
	AAIPlayerController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Init();

	AAICheckpoint* Update(FVector playerLocation, AAICheckpoint* currentCheckpoint);

	AIPlayerActions GetAction(FVector direction, FVector location, AAICheckpoint* currentCheckpoint) const;

	AAICheckpoint* GetCheckpoint(uint32 path, uint32 checkpoint);

	UPROPERTY(EditAnywhere, Category = "Designer Tools")
	float checkpointCollideDistance{ 1500.0f };

private:
	bool mInit{ false };
	std::vector<std::vector<AAICheckpoint*>> mCheckpoints;
};
