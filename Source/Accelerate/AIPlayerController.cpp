// Fill out your copyright notice in the Description page of Project Settings.

#include "AIPlayerController.h"
#include "EngineUtils.h"
#include "Runtime/Engine/Public/TimerManager.h"
#include "AICheckpoint.h"
#include "Runtime/Engine/Public/DrawDebugHelpers.h"
#include "time.h"

// Sets default values
AAIPlayerController::AAIPlayerController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AAIPlayerController::BeginPlay()
{
	Super::BeginPlay();
	srand(time(0));
}


// Called every frame
void AAIPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	
}

void AAIPlayerController::Init()
{
	//Collect checkpoint objects into an unsorted array and set mNumberOfCheckpoints
	uint32 amount = 0;
	TArray<AAICheckpoint*> tempArray;

	for (TActorIterator<AAICheckpoint> checkpoint(GetWorld()); checkpoint; ++checkpoint)
	{
		tempArray.Add(*checkpoint);
		amount++;
	}

	for (int index = 0; index < MAX_AI; ++index)
	{
		mCheckpoints.push_back(std::vector<AAICheckpoint*>());
	}

	

	//Sort checkpoints and assign mCurrentCheckpoint to the first
	for (auto c : tempArray)
	{
		if (c->pathNumber < mCheckpoints.size())
		{
			mCheckpoints[c->pathNumber].push_back(c);
		}
	}
	

	//***************BETTER SORT! - Brayden
	for (int checkpoint = 0; checkpoint < mCheckpoints.size(); ++checkpoint)
	{
		if (checkpoint < mCheckpoints.size())
		{
			if (mCheckpoints[checkpoint].size() > 0)
			{
				int i, j;
				for (i = 0; i < mCheckpoints[checkpoint].size() - 1; i++)
				{
					for (j = 0; j < mCheckpoints[checkpoint].size() - i - 1; j++)
					{
						if (mCheckpoints[checkpoint][j]->orderNumber > mCheckpoints[checkpoint][j + 1]->orderNumber)
						{
							AAICheckpoint* temp = mCheckpoints[checkpoint][j];
							mCheckpoints[checkpoint][j] = mCheckpoints[checkpoint][j + 1];
							mCheckpoints[checkpoint][j + 1] = temp;
						}
					}
				}
			}
		}
	}
}

AAICheckpoint* AAIPlayerController::Update(FVector playerLocation, AAICheckpoint* currentCheckpoint)
{
	if (!mInit)
	{
		Init();
		mInit = true;
	}

	if (currentCheckpoint && mCheckpoints.size() > 0)
	{
		//Check distance to current checkpoint
		FVector checkpointLocation = currentCheckpoint->GetActorLocation();
		float currentDistance = FVector::DistSquared(playerLocation, checkpointLocation);
		if (currentDistance < (checkpointCollideDistance * checkpointCollideDistance))
		{
			//If the distance is less than the collide distance, increment the checkpoint
			uint32 next;
			if (currentCheckpoint->orderNumber == mCheckpoints[currentCheckpoint->pathNumber].size() - 1)
			{
				next = 1;
			}
			else
			{
				next = currentCheckpoint->orderNumber + 1;
			}
			if (currentCheckpoint->orderNumber == 2)
			{
				//UE_LOG(LogTemp, Warning, TEXT("TEST"));
			}
			currentCheckpoint = mCheckpoints[currentCheckpoint->pathNumber][next];
		}
		return currentCheckpoint;
	}
	return nullptr;
}

AIPlayerActions AAIPlayerController::GetAction(FVector direction, FVector playerLocation,
	AAICheckpoint* currentCheckpoint) const
{
	if (currentCheckpoint && mCheckpoints.size() > 0)
	{
		FVector checkpointLocation = currentCheckpoint->GetActorLocation();

		float distanceToCheckpoint = FVector::Dist(playerLocation, checkpointLocation);
		FVector trajectory = playerLocation + (direction * distanceToCheckpoint * 2);

		//DrawDebugSphere(GetWorld(), checkpointLocation, 200.0f, 10, FColor::Green);

		float result = ((checkpointLocation.X - playerLocation.X) *
			(trajectory.Y - playerLocation.Y)) - ((checkpointLocation.Y - playerLocation.Y) *
			(trajectory.X - playerLocation.X));


		if (result < 0)
		{
			return AIPlayerActions::Right;
		}
		else if (result > 0)
		{
			return AIPlayerActions::Left;
		}
		else
		{
			return AIPlayerActions::Nothing;
		}
	}
	else
	{
		return AIPlayerActions::Nothing;
	}
}

AAICheckpoint * AAIPlayerController::GetCheckpoint(uint32 path, uint32 checkpoint)
{
	if (!mInit)
	{
		Init();
		mInit = true;
	}
	if (static_cast<int>(path) < mCheckpoints.size() && static_cast<int>(checkpoint) < mCheckpoints[path].size())
	{
		return mCheckpoints[path][checkpoint];
	}
	return nullptr;
}
