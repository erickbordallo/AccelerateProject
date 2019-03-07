// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Checkpoint.h"
#include "vector"
#include "map"
#include "AcceleratePlayer.h"
#include "CheckpointManager.generated.h"


using PlayerStats = TMap<ACheckpoint*, int>;

/**
 *
 */

UCLASS()
class ACCELERATE_API ACheckpointManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACheckpointManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Init();

	void SetCheckpoint(AAcceleratePlayer* player, ACheckpoint* checkpoint);

	void SetPlayers(TArray<APawn*> players);

	UPROPERTY(EditAnywhere, Category="CheckpointManagerProperties")
	int LapCount{3};

	UPROPERTY(EditAnywhere, Category = "CheckpointManagerProperties")
	float HeightToRespawn{ 0.0f };


private:
	TArray<ACheckpoint*> mCheckpoints;
	TArray<AAcceleratePlayer*> mPlayers;
	TMap<AAcceleratePlayer*, PlayerStats> mPlayerStats;
	TMap<AAcceleratePlayer*, ACheckpoint*> mLastCheckpoints;
	TMap<AAcceleratePlayer*, ACheckpoint*> mNextCheckpoints;
	bool mInitialized{ false };


	uint32_t test;
};
