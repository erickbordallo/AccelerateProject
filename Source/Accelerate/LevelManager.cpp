// Fill out your copyright notice in the Description page of Project Settings.

#include "LevelManager.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerStart.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Runtime/Engine/Classes/GameFramework/GameModeBase.h"
#include "Runtime/Engine/Classes/Engine/Player.h"
#include "Runtime/Engine/Classes/GameFramework/GameModeBase.h"

#include "AcceleratePlayer.h"
#include "LaserBlaster.h"
#include "FlameThrower.h"

#include "CarController.h"
#include "GameManager.h"

// Sets default values
ALevelManager::ALevelManager()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ALevelManager::BeginPlay()
{
	Super::BeginPlay();

	mGameManager = Cast<UGameManager>(GetGameInstance());

	UWorld* world{ GetWorld() };

	UE_LOG(LogTemp, Warning, TEXT("Number of Players are: %d\n"), mGameManager->GetNumberOfPlayers());

	TArray<int32> ids;
	mGameManager->GetSelectedWeapons().GetKeys(ids);

	for (uint32 i{ 0 }; i < static_cast<uint32>(mGameManager->GetNumberOfPlayers()); ++i)
	{
		mGameManager->mPlayerControllers[i] = Cast<ACarController>(UGameplayStatics::GetPlayerController(world, i));
		Cast<ACarController>(mGameManager->mPlayerControllers[i])->CreateHUD();

		controllerIDs.Add(ids[i]);

		//UE_LOG(LogTemp, Warning, TEXT("ControllerID is: %u"), controllerIDs[0]);
		mGameManager->mPlayers.Add(Cast<AAcceleratePlayer>(mGameManager->mPlayerControllers[i]->GetPawn()));

		//Create Weapon here

		InstantiateWeapon(mGameManager->mPlayers[i], mGameManager->GetSelectedWeapons().FindRef(ids[i]));

		UE_LOG(LogTemp, Warning, TEXT("PawnName is: %s"), *mGameManager->mPlayers[i]->GetName());
	}
}

// Called every frame
void ALevelManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

const TArray<AAcceleratePlayer*>& ALevelManager::GetPlayers() const
{
	return mGameManager->mPlayers;
}

AActor* ALevelManager::ChoosePlayerStart_Implementation(AController* Player)
{
	UWorld* const world{ GetWorld() };
	if (playerStartAssignCode == 0)
	{
		UGameplayStatics::GetAllActorsOfClass(world, APlayerStart::StaticClass(), playerStarts);
	}
	return playerStarts[playerStartAssignCode++];
}

void ALevelManager::InstantiateWeapon(AAcceleratePlayer* player, EPrimaryWeaponTypes primaryWeaponType)
{
	player->CreatePrimaryWeapon(primaryWeaponType);
}