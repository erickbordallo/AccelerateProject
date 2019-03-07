// Fill out your copyright notice in the Description page of Project Settings.

#include "MenuController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

#include "GameManager.h"

//Sets default values
AMenuController::AMenuController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMenuController::BeginPlay()
{
	Super::BeginPlay();

	mGameManager = Cast<UGameManager>(GetGameInstance());
}

// Called every frame
void AMenuController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

UMainMenu* AMenuController::GetMainMenu() const
{
	return mMainMenu;
}

void AMenuController::CreateMenu()
{
	if (mainMenuRef != nullptr)
	{
		mMainMenu = Cast<UMainMenu>(CreateWidget(this, mainMenuRef));

		if (mMainMenu != nullptr)
		{
			mMainMenu->AddToPlayerScreen();
			bShowMouseCursor = true;

			mMainMenu->singleplayerButton->SetUserFocus(this);

			BindDelegates();
			SetID();
		}
	}
}

void AMenuController::HideMainMenu()
{
	//The order of the appearance of these menus might change, leading to the change in code here
	if (mMainMenu != nullptr)
	{
		mMainMenu->menu->SetVisibility(ESlateVisibility::Collapsed);
		mMainMenu->mapSelectionPanel->SetVisibility(ESlateVisibility::Collapsed);

		mMainMenu->carCustomizationPanel->SetVisibility(ESlateVisibility::Visible);

		mMainMenu->car1Button->SetUserFocus(this);
	}
}

EPrimaryWeaponTypes AMenuController::GetSelectedPrimaryWeapon() const
{
	return mSelectedPrimaryWeapon;
}

int32 AMenuController::GetID() const
{
	return mID;
}

void AMenuController::ChooseLaserBlaster()
{
	mSelectedPrimaryWeapon = EPrimaryWeaponTypes::LaserBlaster;

	mGameManager->SetSelectedPrimaryWeapon(mID, mSelectedPrimaryWeapon);
}
void AMenuController::ChooseFlamethrower()
{
	mSelectedPrimaryWeapon = EPrimaryWeaponTypes::Flamethrower;

	mGameManager->SetSelectedPrimaryWeapon(mID, mSelectedPrimaryWeapon);
}
void AMenuController::ChooseRailgun()
{
	mSelectedPrimaryWeapon = EPrimaryWeaponTypes::Railgun;

	mGameManager->SetSelectedPrimaryWeapon(mID, mSelectedPrimaryWeapon);
}

void AMenuController::BindDelegates()
{
	mMainMenu->primaryWeapon1Button->OnClicked.AddDynamic(this, &AMenuController::ChooseLaserBlaster);
	mMainMenu->primaryWeapon2Button->OnClicked.AddDynamic(this, &AMenuController::ChooseFlamethrower);
	mMainMenu->primaryWeapon3Button->OnClicked.AddDynamic(this, &AMenuController::ChooseRailgun);

	mMainMenu->twoPlayerButton->OnClicked.AddDynamic(this, &AMenuController::OnPressedtwoPlayerButton);
	mMainMenu->threePlayerButton->OnClicked.AddDynamic(this, &AMenuController::OnPressedthreePlayerButton);
	mMainMenu->fourPlayerButton->OnClicked.AddDynamic(this, &AMenuController::OnPressedfourPlayerButton);
	mMainMenu->audioButton->OnClicked.AddDynamic(this, &AMenuController::OnPressedaudioButton);
	mMainMenu->audioBackButton->OnClicked.AddDynamic(this, &AMenuController::OnPressedaudioBackButton);
	mMainMenu->primaryWeapon1Button->OnClicked.AddDynamic(this, &AMenuController::OnPressedprimaryWeapon1Button);
	mMainMenu->primaryWeapon2Button->OnClicked.AddDynamic(this, &AMenuController::OnPressedprimaryWeapon2Button);
	mMainMenu->primaryWeapon3Button->OnClicked.AddDynamic(this, &AMenuController::OnPressedprimaryWeapon3Button);
	mMainMenu->primaryWeaponBackButton->OnClicked.AddDynamic(this, &AMenuController::OnPressedprimaryWeaponBackButton);
	mMainMenu->car1Button->OnClicked.AddDynamic(this, &AMenuController::OnPressedcar1Button);
	mMainMenu->car2Button->OnClicked.AddDynamic(this, &AMenuController::OnPressedcar2Button);
	mMainMenu->car3Button->OnClicked.AddDynamic(this, &AMenuController::OnPressedcar3Button);
	mMainMenu->car4Button->OnClicked.AddDynamic(this, &AMenuController::OnPressedcar4Button);
	mMainMenu->carColor1Button->OnClicked.AddDynamic(this, &AMenuController::OnPressedcarColor1Button);
	mMainMenu->carColor2Button->OnClicked.AddDynamic(this, &AMenuController::OnPressedcarColor2Button);
	mMainMenu->carColor3Button->OnClicked.AddDynamic(this, &AMenuController::OnPressedcarColor3Button);
	mMainMenu->carColor4Button->OnClicked.AddDynamic(this, &AMenuController::OnPressedcarColor4Button);
	mMainMenu->tyreStyle1Button->OnClicked.AddDynamic(this, &AMenuController::OnPressedtyreStyle1Button);
	mMainMenu->tyreStyle2Button->OnClicked.AddDynamic(this, &AMenuController::OnPressedtyreStyle2Button);
	mMainMenu->tyreStyle3Button->OnClicked.AddDynamic(this, &AMenuController::OnPressedtyreStyle3Button);
	mMainMenu->tyreStyle4Button->OnClicked.AddDynamic(this, &AMenuController::OnPressedtyreStyle4Button);
	mMainMenu->carBackButton->OnClicked.AddDynamic(this, &AMenuController::OnPressedcarBackButton);
	mMainMenu->displayBackButton->OnClicked.AddDynamic(this, &AMenuController::OnPresseddisplayBackButton);
	mMainMenu->videoButton->OnClicked.AddDynamic(this, &AMenuController::OnPressedvideoButton);
	mMainMenu->easyButton->OnClicked.AddDynamic(this, &AMenuController::OnPressedeasyButton);
	mMainMenu->normalButton->OnClicked.AddDynamic(this, &AMenuController::OnPressednormalButton);
	mMainMenu->hardButton->OnClicked.AddDynamic(this, &AMenuController::OnPressedhardButton);
	mMainMenu->map1Button->OnClicked.AddDynamic(this, &AMenuController::OnPressedmap1Button);
	mMainMenu->map2Button->OnClicked.AddDynamic(this, &AMenuController::OnPressedmap2Button);
	mMainMenu->map3Button->OnClicked.AddDynamic(this, &AMenuController::OnPressedmap3Button);
	mMainMenu->map4Button->OnClicked.AddDynamic(this, &AMenuController::OnPressedmap4Button);
	mMainMenu->mapBackButton->OnClicked.AddDynamic(this, &AMenuController::OnPressedmapBackButton);
	mMainMenu->singleplayerButton->OnClicked.AddDynamic(this, &AMenuController::OnPressedsingleplayerButton);
	mMainMenu->singleplayerBackButton->OnClicked.AddDynamic(this, &AMenuController::OnPressedsingleplayerBackButton);
	mMainMenu->multiplayerBackButton->OnClicked.AddDynamic(this, &AMenuController::OnPressedmultiplayerBackButton);
	mMainMenu->multiplayerButton->OnClicked.AddDynamic(this, &AMenuController::OnPressedmultiplayerButton);
	mMainMenu->noQuitButton->OnClicked.AddDynamic(this, &AMenuController::OnPressednoQuitButton);
	mMainMenu->yesQuitButton->OnClicked.AddDynamic(this, &AMenuController::OnPressedyesQuitButton);
	mMainMenu->quitButton->OnClicked.AddDynamic(this, &AMenuController::OnPressedquitButton);
	mMainMenu->optionsBackButton->OnClicked.AddDynamic(this, &AMenuController::OnPressedoptionsBackButton);
	mMainMenu->optionsButton->OnClicked.AddDynamic(this, &AMenuController::OnPressedoptionsButton);
}

void AMenuController::SetID()
{
	mID = UGameplayStatics::GetPlayerControllerID(this);
}

void AMenuController::OnPressedtwoPlayerButton()
{
	mGameManager->SetNumberOfPlayers(2);
	mMainMenu->multiplayerMenu->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->mapSelectionPanel->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->map1Button->SetUserFocus(this);
}

void AMenuController::OnPressedthreePlayerButton()
{
	mGameManager->SetNumberOfPlayers(3);
	mMainMenu->multiplayerMenu->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->mapSelectionPanel->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->map1Button->SetUserFocus(this);
}

void AMenuController::OnPressedfourPlayerButton()
{
	mGameManager->SetNumberOfPlayers(4);
	mMainMenu->multiplayerMenu->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->mapSelectionPanel->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->map1Button->SetUserFocus(this);
}

void AMenuController::OnPressedaudioButton()
{
	mMainMenu->optionsMenu->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->audioMenu->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->masterVolumeSlider->SetUserFocus(this);
}

void AMenuController::OnPressedaudioBackButton()
{
	mMainMenu->audioMenu->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->optionsMenu->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->videoButton->SetUserFocus(this);
}

void AMenuController::OnPressedprimaryWeapon1Button()
{
	mMainMenu->weaponSelectionPanel->SetVisibility(ESlateVisibility::Collapsed);
}

void AMenuController::OnPressedprimaryWeapon2Button()
{
	mMainMenu->weaponSelectionPanel->SetVisibility(ESlateVisibility::Collapsed);

}

void AMenuController::OnPressedprimaryWeapon3Button()
{
	mMainMenu->weaponSelectionPanel->SetVisibility(ESlateVisibility::Collapsed);

}

void AMenuController::OnPressedprimaryWeaponBackButton()
{
	mMainMenu->weaponSelectionPanel->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->carCustomizationPanel->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->car1Button->SetUserFocus(this);
}

void AMenuController::OnPressedcar1Button()
{
	mMainMenu->hasSelectedCar = true;
	mMainMenu->carColor1Button->SetUserFocus(this);
}

void AMenuController::OnPressedcar2Button()
{
	mMainMenu->hasSelectedCar = true;
	mMainMenu->carColor1Button->SetUserFocus(this);
}

void AMenuController::OnPressedcar3Button()
{
	mMainMenu->hasSelectedCar = true;
	mMainMenu->carColor1Button->SetUserFocus(this);
}

void AMenuController::OnPressedcar4Button()
{
	mMainMenu->hasSelectedCar = true;
	mMainMenu->carColor1Button->SetUserFocus(this);
}

void AMenuController::OnPressedcarColor1Button()
{
	mMainMenu->hasSelectedColor = true;
	mMainMenu->tyreStyle1Button->SetUserFocus(this);
}

void AMenuController::OnPressedcarColor2Button()
{
	mMainMenu->hasSelectedColor = true;
	mMainMenu->tyreStyle1Button->SetUserFocus(this);
}

void AMenuController::OnPressedcarColor3Button()
{
	mMainMenu->hasSelectedColor = true;
	mMainMenu->tyreStyle1Button->SetUserFocus(this);
}

void AMenuController::OnPressedcarColor4Button()
{
	mMainMenu->hasSelectedColor = true;
	mMainMenu->tyreStyle1Button->SetUserFocus(this);
}

void AMenuController::OnPressedtyreStyle1Button()
{
	if (mMainMenu->hasSelectedCar && mMainMenu->hasSelectedColor)
	{
		mMainMenu->carCustomizationPanel->SetVisibility(ESlateVisibility::Collapsed);
		mMainMenu->weaponSelectionPanel->SetVisibility(ESlateVisibility::Visible);
		mMainMenu->primaryWeapon1Button->SetUserFocus(this);
	}
}

void AMenuController::OnPressedtyreStyle2Button()
{
	if (mMainMenu->hasSelectedCar && mMainMenu->hasSelectedColor)
	{
		mMainMenu->carCustomizationPanel->SetVisibility(ESlateVisibility::Collapsed);
		mMainMenu->weaponSelectionPanel->SetVisibility(ESlateVisibility::Visible);
		mMainMenu->primaryWeapon1Button->SetUserFocus(this);
	}
}

void AMenuController::OnPressedtyreStyle3Button()
{
	if (mMainMenu->hasSelectedCar && mMainMenu->hasSelectedColor)
	{
		mMainMenu->carCustomizationPanel->SetVisibility(ESlateVisibility::Collapsed);
		mMainMenu->weaponSelectionPanel->SetVisibility(ESlateVisibility::Visible);
		mMainMenu->primaryWeapon1Button->SetUserFocus(this);
	}
}

void AMenuController::OnPressedtyreStyle4Button()
{
	if (mMainMenu->hasSelectedCar && mMainMenu->hasSelectedColor)
	{
		mMainMenu->carCustomizationPanel->SetVisibility(ESlateVisibility::Collapsed);
		mMainMenu->weaponSelectionPanel->SetVisibility(ESlateVisibility::Visible);
		mMainMenu->primaryWeapon1Button->SetUserFocus(this);
	}
}

void AMenuController::OnPressedcarBackButton()
{
	mMainMenu->carCustomizationPanel->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->mapSelectionPanel->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->map1Button->SetUserFocus(this);
}

void AMenuController::OnPresseddisplayBackButton()
{
	mMainMenu->videoMenu->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->optionsMenu->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->videoButton->SetUserFocus(this);
}

void AMenuController::OnPressedvideoButton()
{
	mMainMenu->optionsMenu->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->videoMenu->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->fullScreenCheckBox->SetUserFocus(this);
}

void AMenuController::OnPressedeasyButton()
{
	mMainMenu->singleplayerMenu->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->mapSelectionPanel->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->map1Button->SetUserFocus(this);
}

void AMenuController::OnPressednormalButton()
{
	mMainMenu->singleplayerMenu->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->mapSelectionPanel->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->map1Button->SetUserFocus(this);
}

void AMenuController::OnPressedhardButton()
{
	mMainMenu->singleplayerMenu->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->mapSelectionPanel->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->map1Button->SetUserFocus(this);
}

void AMenuController::OnPressedmap1Button()
{
	mMainMenu->mapSelectionPanel->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->carCustomizationPanel->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->car1Button->SetUserFocus(this);
}

void AMenuController::OnPressedmap2Button()
{
	mMainMenu->mapSelectionPanel->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->carCustomizationPanel->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->car1Button->SetUserFocus(this);
}

void AMenuController::OnPressedmap3Button()
{
	mMainMenu->mapSelectionPanel->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->carCustomizationPanel->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->car1Button->SetUserFocus(this);
}

void AMenuController::OnPressedmap4Button()
{
	mMainMenu->car1Button->SetUserFocus(this);
}

void AMenuController::OnPressedmapBackButton()
{
	mMainMenu->mapSelectionPanel->SetVisibility(ESlateVisibility::Collapsed);
	if (!mMainMenu->multiplayerMode)
	{
		mMainMenu->singleplayerMenu->SetVisibility(ESlateVisibility::Visible);
		mMainMenu->easyButton->SetUserFocus(this);
	}
	else if(mMainMenu->multiplayerMode)
	{
		mMainMenu->multiplayerMenu->SetVisibility(ESlateVisibility::Visible);
		mMainMenu->twoPlayerButton->SetUserFocus(this);
	}
}

void AMenuController::OnPressedsingleplayerButton()
{
	mMainMenu->multiplayerMode = false;
	mGameManager->SetNumberOfPlayers(1);
	mMainMenu->menu->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->singleplayerMenu->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->easyButton->SetUserFocus(this);
}

void AMenuController::OnPressedsingleplayerBackButton()
{
	mMainMenu->singleplayerMenu->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->menu->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->singleplayerButton->SetUserFocus(this);
}

void AMenuController::OnPressedmultiplayerBackButton()
{
	mMainMenu->multiplayerMode = false;
	mMainMenu->multiplayerMenu->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->menu->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->singleplayerButton->SetUserFocus(this);
}

void AMenuController::OnPressedmultiplayerButton()
{
	mMainMenu->multiplayerMode = true;
	mMainMenu->menu->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->multiplayerMenu->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->twoPlayerButton->SetUserFocus(this);
}

void AMenuController::OnPressednoQuitButton()
{
	mMainMenu->quitMenu->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->menu->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->singleplayerButton->SetUserFocus(this);
}

void AMenuController::OnPressedyesQuitButton()
{
}

void AMenuController::OnPressedquitButton()
{
	mMainMenu->menu->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->quitMenu->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->yesQuitButton->SetUserFocus(this);
}

void AMenuController::OnPressedoptionsBackButton()
{
	mMainMenu->optionsMenu->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->menu->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->singleplayerButton->SetUserFocus(this);
}

void AMenuController::OnPressedoptionsButton()
{
	mMainMenu->menu->SetVisibility(ESlateVisibility::Collapsed);
	mMainMenu->optionsMenu->SetVisibility(ESlateVisibility::Visible);
	mMainMenu->videoButton->SetUserFocus(this);
}
