// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"

#include "GameManager.generated.h"

class AAcceleratePlayer;
class ULoadingScreenModule;
class SLoadingScreenWidget;
enum class EPrimaryWeaponTypes : uint8;

/**
 * 
 */
UCLASS()
class ACCELERATE_API UGameManager : public UGameInstance
{
	GENERATED_BODY()
	
public:
	// Sets default values
	UGameManager();

protected:
	//Init can be used to set up what gamemanager needs
	virtual void Init() override;

	//Shutdown can be used to do cleanup when shutting down
	virtual void Shutdown() override;

	bool Tick(float DeltaTime);

public:
	UFUNCTION(BlueprintCallable, Category = "Player")
	const TArray<AAcceleratePlayer*> GetPlayers() const;

	UFUNCTION(BlueprintCallable, Category = "Player")
	int32 GetNumberOfPlayers() const;

	UFUNCTION(BlueprintCallable, Category = "Player")
	void SetNumberOfPlayers(int32 numberOfPlayers);

	UFUNCTION(BlueprintCallable, Category = "Player")
	AAcceleratePlayer* GetPlayer(int32 index) const;

	UFUNCTION(BlueprintCallable, Category = "Player")
	APlayerController* GetPlayerController(int32 index) const;

	void SetSelectedPrimaryWeapon(int32 index, EPrimaryWeaponTypes selectedWeapon);

	UFUNCTION(BlueprintCallable, Category = "Player")
	const TMap<int32, EPrimaryWeaponTypes>& GetSelectedWeapons() const;

	/*UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSubclassOf<ULoadingScreenModule> loadingScreenModuleRef;*/

	//ULoadingScreenModule* GetLoadingScreenModule() const;

protected:

private:
	friend class AMainMenuManager;
	friend class ALevelManager;

	TArray<AAcceleratePlayer*> mPlayers;
	TArray<APlayerController*> mPlayerControllers;

	uint32 mNumberOfPlayers{ 0 };

	TMap<int32, EPrimaryWeaponTypes> mSelectedWeapons;

	//ULoadingScreenModule* mLoadingScreenModule;
	//TSharedPtr<SLoadingScreenWidget> mLoadingScreenWidget;

	FDelegateHandle mTickDelegateHandle;
};
