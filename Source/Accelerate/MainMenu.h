// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"

#include "Runtime/UMG/Public/Components/Button.h"
#include "Runtime/UMG/Public/Components/VerticalBox.h"
#include "Runtime/UMG/Public/Components/EditableTextBox.h"
#include "Runtime/UMG/Public/Components/Image.h"
#include "Runtime/UMG/Public/Components/CheckBox.h"
#include "Runtime/UMG/Public/Components/CanvasPanel.h"
#include "Runtime/UMG/Public/Components/Border.h"
#include "Runtime/UMG/Public/Components/HorizontalBox.h"
#include "Runtime/UMG/Public/Components/Slider.h"

#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class ACCELERATE_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//virtual void NativeConstruct() override;

	//virtual bool Initialize() override;

	//virtual void NativeConstruct() override;

	

public:
	UCanvasPanel* root;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "MainMenu")
	UVerticalBox* menu;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "MainMenu")
	UImage* mainMenuBackgroundImage;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Player")
	UButton* twoPlayerButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Player")
	UButton* threePlayerButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Player")
	UButton* fourPlayerButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Audio")
	UButton* audioButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Audio")
	UButton* audioBackButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Audio")
	UVerticalBox* audioMenu;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Audio")
	USlider* masterVolumeSlider;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Audio")
	USlider* musicVolumeSlider;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Audio")
	USlider* sfxVolumeSlider;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Weapon")
	UCanvasPanel* weaponSelectionPanel;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Primary Weapon")
	UButton* primaryWeapon1Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Primary Weapon")
	UButton* primaryWeapon2Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Primary Weapon")
	UButton* primaryWeapon3Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Primary Weapon")
	UButton* primaryWeaponBackButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Primary Weapon")
	UEditableTextBox* primaryWeaponDescription;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Primary Weapon")
	UImage* primaryWeaponImage;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Car")
	UCanvasPanel* carCustomizationPanel;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Car")
	UButton* car1Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Car")
	UButton* car2Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Car")
	UButton* car3Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Car")
	UButton* car4Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Car")
	UButton* carColor1Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Car")
	UButton* carColor2Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Car")
	UButton* carColor3Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Car")
	UButton* carColor4Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Car")
	UButton* tyreStyle1Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Car")
	UButton* tyreStyle2Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Car")
	UButton* tyreStyle3Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Car")
	UButton* tyreStyle4Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Car")
	UButton* carBackButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Car")
	UImage* carImage;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Display")
	UButton* displayBackButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Video")
	UVerticalBox* videoMenu;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Video")
	UCheckBox* fullScreenCheckBox;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Video")
	USlider* brightnessSlider;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Video")
	USlider* textureQualitySlider;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Video")
	UButton* videoButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Difficulty")
	UButton* easyButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Difficulty")
	UButton* normalButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Difficulty")
	UButton* hardButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Map")
	UCanvasPanel* mapSelectionPanel;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Map")
	UButton* map1Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Map")
	UButton* map2Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Map")
	UButton* map3Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Map")
	UButton* map4Button;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Map")
	UButton* mapBackButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Map")
	UImage* mapImage;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Map")
	UImage* mapTitleImage;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Map")
	UEditableTextBox* mapDescription;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Singleplayer")
	UButton* singleplayerButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Singleplayer")
	UButton* singleplayerBackButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Singleplayer")
	UVerticalBox* singleplayerMenu;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Multiplayer")
	UButton* multiplayerBackButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Multiplayer")
	UButton* multiplayerButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Multiplayer")
	UVerticalBox* multiplayerMenu;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Quit")
	UButton* noQuitButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Quit")
	UButton* yesQuitButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Quit")
	UButton* quitButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Quit")
	UVerticalBox* quitMenu;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Quit")
	UBorder* quitBackground;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Quit")
	UHorizontalBox* quitChoices;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Options")
	UButton* optionsBackButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Options")
	UButton* optionsButton;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget), Category = "Options")
	UVerticalBox* optionsMenu;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Booleans")
	bool hasSelectedCar;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Booleans")
	bool hasSelectedColor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Booleans")
	bool multiplayerMode;
};
