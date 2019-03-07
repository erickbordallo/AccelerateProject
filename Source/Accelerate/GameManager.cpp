// Fill out your copyright notice in the Description page of Project Settings.

#include "GameManager.h"
#include "Ticker.h"
#include "PrimaryWeaponTypes.h"

//#include "LoadingScreenModule.h"

//#include "LoadingScreenWidget.h"
#include "Geometry.h"

UGameManager::UGameManager()
{
	
}

void UGameManager::Init()
{
	mTickDelegateHandle = FTicker::GetCoreTicker().AddTicker(FTickerDelegate::CreateUObject(this, &UGameManager::Tick));

	Super::Init();

	//mLoadingScreenModule = NewObject<ULoadingScreenModule>(this, loadingScreenModuleRef->GetAuthoritativeClass());
	//mLoadingScreenModule->Startup();

	//SAssignNew(mLoadingScreenWidget, SLoadingScreenWidget, mLoadingScreenModule->settings->defaultScreen, this);
	//mLoadingScreenWidget->Construct(mLoadingScreenModule->settings->defaultScreen);
}

void UGameManager::Shutdown()
{
	FTicker::GetCoreTicker().RemoveTicker(mTickDelegateHandle);

	Super::Shutdown();

	//mLoadingScreenModule->Shutdown();
}

bool UGameManager::Tick(float DeltaTime)
{
	//mLoadingScreenWidget->Tick(, 0.0, DeltaTime);

	return true;
}

const TArray<AAcceleratePlayer*> UGameManager::GetPlayers() const
{
	return mPlayers;
}

int32 UGameManager::GetNumberOfPlayers() const
{
	return mNumberOfPlayers;
}

AAcceleratePlayer* UGameManager::GetPlayer(int32 index) const
{
	return mPlayers[index];
}

void UGameManager::SetNumberOfPlayers(int32 numberOfPlayers)
{
	mNumberOfPlayers = numberOfPlayers;
}

APlayerController* UGameManager::GetPlayerController(int32 index) const
{
	return mPlayerControllers[index];
}

void UGameManager::SetSelectedPrimaryWeapon(int32 index, EPrimaryWeaponTypes selectedWeapon)
{
	mSelectedWeapons.Add(index, selectedWeapon);
}

const TMap<int32, EPrimaryWeaponTypes>& UGameManager::GetSelectedWeapons() const
{
	return mSelectedWeapons;
}
//
//ULoadingScreenModule* UGameManager::GetLoadingScreenModule() const
//{
//	return mLoadingScreenModule;
//}
