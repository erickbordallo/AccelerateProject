// Fill out your copyright notice in the Description page of Project Settings.

#include "MainMenuManager.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

#include "GameManager.h"

#include "MenuController.h"
#include "CarController.h"

#include "MainMenu.h"
//#include "LoadingModule.h"

AMainMenuManager::AMainMenuManager()
{
	PrimaryActorTick.bCanEverTick = true;
}


void AMainMenuManager::BeginPlay()
{
	Super::BeginPlay();

	mGameManager = Cast<UGameManager>(GetGameInstance());

	const UWorld* world{ GetWorld() };

	mGameManager->mPlayerControllers.Add(Cast<AMenuController>(world->GetFirstPlayerController()));
	Cast<AMenuController>(mGameManager->mPlayerControllers.Last())->CreateMenu();

	Cast<AMenuController>(mGameManager->mPlayerControllers[0])->GetMainMenu()->map1Button->OnClicked.AddDynamic(this, &AMainMenuManager::AddAdditionalPlayers);
	Cast<AMenuController>(mGameManager->mPlayerControllers[0])->GetMainMenu()->map2Button->OnClicked.AddDynamic(this, &AMainMenuManager::AddAdditionalPlayers);
	Cast<AMenuController>(mGameManager->mPlayerControllers[0])->GetMainMenu()->map3Button->OnClicked.AddDynamic(this, &AMainMenuManager::AddAdditionalPlayers);
	Cast<AMenuController>(mGameManager->mPlayerControllers[0])->GetMainMenu()->map4Button->OnClicked.AddDynamic(this, &AMainMenuManager::AddAdditionalPlayers);

	Cast<AMenuController>(mGameManager->mPlayerControllers[0])->GetMainMenu()->primaryWeapon1Button->OnClicked.AddDynamic(this, &AMainMenuManager::CheckAndUpdateLevel);
	Cast<AMenuController>(mGameManager->mPlayerControllers[0])->GetMainMenu()->primaryWeapon2Button->OnClicked.AddDynamic(this, &AMainMenuManager::CheckAndUpdateLevel);
	Cast<AMenuController>(mGameManager->mPlayerControllers[0])->GetMainMenu()->primaryWeapon3Button->OnClicked.AddDynamic(this, &AMainMenuManager::CheckAndUpdateLevel);
}

void AMainMenuManager::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMainMenuManager::BindDelegates(uint32 index)
{
	Cast<AMenuController>(mGameManager->mPlayerControllers[index])->GetMainMenu()->map1Button->OnClicked.AddDynamic(this, &AMainMenuManager::AddAdditionalPlayers);
	Cast<AMenuController>(mGameManager->mPlayerControllers[index])->GetMainMenu()->map2Button->OnClicked.AddDynamic(this, &AMainMenuManager::AddAdditionalPlayers);
	Cast<AMenuController>(mGameManager->mPlayerControllers[index])->GetMainMenu()->map3Button->OnClicked.AddDynamic(this, &AMainMenuManager::AddAdditionalPlayers);
	Cast<AMenuController>(mGameManager->mPlayerControllers[index])->GetMainMenu()->map4Button->OnClicked.AddDynamic(this, &AMainMenuManager::AddAdditionalPlayers);
	Cast<AMenuController>(mGameManager->mPlayerControllers[index])->GetMainMenu()->primaryWeapon1Button->OnClicked.AddDynamic(this, &AMainMenuManager::CheckAndUpdateLevel);
	Cast<AMenuController>(mGameManager->mPlayerControllers[index])->GetMainMenu()->primaryWeapon2Button->OnClicked.AddDynamic(this, &AMainMenuManager::CheckAndUpdateLevel);
	Cast<AMenuController>(mGameManager->mPlayerControllers[index])->GetMainMenu()->primaryWeapon3Button->OnClicked.AddDynamic(this, &AMainMenuManager::CheckAndUpdateLevel);
}

void AMainMenuManager::CheckAndUpdateLevel()
{
	mPlayerIterator++;
	
	if (mPlayerIterator == mGameManager->mPlayerControllers.Num())
	{
		UWorld* const world { GetWorld() };

		UGameplayStatics::OpenLevel(world, levelName);
	}
}

void AMainMenuManager::AddAdditionalPlayers()
{
	const UWorld* world{ GetWorld() };
	if (mGameManager->GetNumberOfPlayers() > 1)
	{
		for (uint32 i{ 1 }; i < static_cast<uint32>(mGameManager->GetNumberOfPlayers()); ++i)
		{
			mGameManager->mPlayerControllers.Add(Cast<AMenuController>(UGameplayStatics::CreatePlayer(world))); //Calling BeginPlay before creating the new menu
			Cast<AMenuController>(mGameManager->mPlayerControllers[i])->CreateMenu();
			BindDelegates(i);
		}

		for (uint32 i{ 0 }; i < static_cast<uint32>(mGameManager->GetNumberOfPlayers()); ++i)
		{
			Cast<AMenuController>(mGameManager->mPlayerControllers[i])->HideMainMenu();
		}
	}
}