// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainMenu.h"

#include "PrimaryWeaponTypes.h"

#include "MenuController.generated.h"

class UGameManager;

/**
 * 
 */
UCLASS()
class ACCELERATE_API AMenuController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMenuController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UMainMenu* GetMainMenu() const;

	void CreateMenu();

	void HideMainMenu();

	EPrimaryWeaponTypes GetSelectedPrimaryWeapon() const;
	int32 GetID() const;

	UFUNCTION()
	void ChooseLaserBlaster();

	UFUNCTION()
	void ChooseFlamethrower();

	UFUNCTION()
	void ChooseRailgun();

	UPROPERTY(EditAnywhere, Category = "Main Menu")
	TSubclassOf<UMainMenu> mainMenuRef;

private:
	void BindDelegates();
	void SetID();

	UFUNCTION()
	void OnPressedtwoPlayerButton();

	UFUNCTION()
	void OnPressedthreePlayerButton();

	UFUNCTION()
	void OnPressedfourPlayerButton();

	UFUNCTION()
	void OnPressedaudioButton();

	UFUNCTION()
	void OnPressedaudioBackButton();

	UFUNCTION()
	void OnPressedprimaryWeapon1Button();

	UFUNCTION()
	void OnPressedprimaryWeapon2Button();

	UFUNCTION()
	void OnPressedprimaryWeapon3Button();

	UFUNCTION()
	void OnPressedprimaryWeaponBackButton();

	UFUNCTION()
	void OnPressedcar1Button();

	UFUNCTION()
	void OnPressedcar2Button();

	UFUNCTION()
	void OnPressedcar3Button();

	UFUNCTION()
	void OnPressedcar4Button();

	UFUNCTION()
	void OnPressedcarColor1Button();

	UFUNCTION()
	void OnPressedcarColor2Button();

	UFUNCTION()
	void OnPressedcarColor3Button();

	UFUNCTION()
	void OnPressedcarColor4Button();

	UFUNCTION()
	void OnPressedtyreStyle1Button();

	UFUNCTION()
	void OnPressedtyreStyle2Button();

	UFUNCTION()
	void OnPressedtyreStyle3Button();

	UFUNCTION()
	void OnPressedtyreStyle4Button();

	UFUNCTION()
	void OnPressedcarBackButton();

	UFUNCTION()
	void OnPresseddisplayBackButton();

	UFUNCTION()
	void OnPressedvideoButton();

	UFUNCTION()
	void OnPressedeasyButton();

	UFUNCTION()
	void OnPressednormalButton();

	UFUNCTION()
	void OnPressedhardButton();

	UFUNCTION()
	void OnPressedmap1Button();

	UFUNCTION()
	void OnPressedmap2Button();

	UFUNCTION()
	void OnPressedmap3Button();

	UFUNCTION()
	void OnPressedmap4Button();

	UFUNCTION()
	void OnPressedmapBackButton();

	UFUNCTION()
	void OnPressedsingleplayerButton();

	UFUNCTION()
	void OnPressedsingleplayerBackButton();

	UFUNCTION()
	void OnPressedmultiplayerBackButton();

	UFUNCTION()
	void OnPressedmultiplayerButton();

	UFUNCTION()
	void OnPressednoQuitButton();

	UFUNCTION()
	void OnPressedyesQuitButton();

	UFUNCTION()
	void OnPressedquitButton();

	UFUNCTION()
	void OnPressedoptionsBackButton();

	UFUNCTION()
	void OnPressedoptionsButton();

private:
	UMainMenu* mMainMenu;

	EPrimaryWeaponTypes mSelectedPrimaryWeapon{ EPrimaryWeaponTypes::None };

	UGameManager* mGameManager;

	int32 mID;

};
