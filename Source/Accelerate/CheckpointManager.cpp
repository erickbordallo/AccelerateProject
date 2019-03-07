// Fill out your copyright notice in the Description page of Project Settings.

#include "CheckpointManager.h"
#include "EngineUtils.h"
#include "Engine/Engine.h"
#include "LevelManager.h"
#include "Components/StaticMeshComponent.h"
#include "AIPlayer.h"
#include "EngineGlobals.h"


// Sets default values
ACheckpointManager::ACheckpointManager()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACheckpointManager::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ACheckpointManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!mInitialized)
	{
		Init();
		mInitialized = true;
	}

	for (auto& player : mPlayers)
	{
		if (player->Health <= 0.0f || player->GetActorLocation().Z <= HeightToRespawn)
		{
			FVector newLocation = mLastCheckpoints[player]->GetActorLocation();
			newLocation.Z += 100.0f;
			player->SetActorLocationAndRotation(newLocation, mLastCheckpoints[player]->GetActorRotation());
			player->Health = 100.0f;
			player->Mesh->SetPhysicsLinearVelocity(FVector(0.0f));
			if (player->IsA(AAIPlayer::StaticClass()))
			{
				Cast<AAIPlayer>(player)->SetCurrentCheckpoint
				(mLastCheckpoints[player]->nextAICheckpoints[Cast<AAIPlayer>(player)->pathNumber]);
			}
		}
	}
}

void ACheckpointManager::Init()
{
	for (TActorIterator<ACheckpoint> checkpoint(GetWorld()); checkpoint; ++checkpoint)
	{
		mCheckpoints.Add(*checkpoint);
	}
	int i, j;
	for (i = 0; i < mCheckpoints.Num() - 1; i++)
	{
		for (j = 0; j < mCheckpoints.Num() - i - 1; j++)
		{
			if (mCheckpoints[j]->checkpointNumber > mCheckpoints[j + 1]->checkpointNumber)
			{
				ACheckpoint* temp = mCheckpoints[j];
				mCheckpoints[j] = mCheckpoints[j + 1];
				mCheckpoints[j + 1] = temp;
			}
		}
	}

	for (TActorIterator<AAcceleratePlayer> player(GetWorld()); player; ++player)
	{
		mPlayers.Add(*player);
	}


	PlayerStats defaultPlayerStats;
	
	for (auto& checkpoint : mCheckpoints)
	{
		defaultPlayerStats.Add(checkpoint, 0);
	}

	for (auto& player : mPlayers)
	{
		mPlayerStats.Add(player, defaultPlayerStats);
		mLastCheckpoints.Add(player, mCheckpoints[0]);
		mNextCheckpoints.Add(player, mCheckpoints[0]);
	}
}

void ACheckpointManager::SetCheckpoint(AAcceleratePlayer* player, ACheckpoint* checkpoint)
{

	if (mNextCheckpoints[player]->checkpointNumber == checkpoint->checkpointNumber)
	{
		mPlayerStats[player][checkpoint]++;
		if (checkpoint->checkpointNumber == mCheckpoints.Num() - 1)
		{
			mNextCheckpoints[player] = mCheckpoints[0];
			if (mPlayerStats[player][checkpoint] == LapCount)
			{
				//Win
				FString winMessage = *player->GetName();
				winMessage += " has won the game!";
				//GEngine->AddOnScreenDebugMessage(0, 10.0f, FColor::Green, winMessage);
			}
		}
		else
		{
			mNextCheckpoints[player] = mCheckpoints[checkpoint->checkpointNumber + 1];
		}

		mLastCheckpoints[player] = checkpoint;
		//UE_LOG(LogTemp, Display, TEXT("Player %s has reached checkpoint %s %d times"), *player->GetName(), *checkpoint->GetName(), mPlayerStats[player][checkpoint]);
	}
	else
	{
		//UE_LOG(LogTemp, Display, TEXT("Player %s is cheating. -10 points"), *player->GetName());
	}
}

void ACheckpointManager::SetPlayers(TArray<APawn*> players)
{
	for (auto& player : players)
	{
		if (player->IsA(AAcceleratePlayer::StaticClass()))
		{
			mPlayers.Add(static_cast<AAcceleratePlayer*>(player));
		}
	}
}