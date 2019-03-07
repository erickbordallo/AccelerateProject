// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainMenuManager.generated.h"

class UGameManager;
class AMenuController;
class UMainMenu;
/**
 * 
 */
UCLASS()
class ACCELERATE_API AMainMenuManager : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AMainMenuManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, Category = "Level")
	FName levelName;

private:

	void BindDelegates(uint32 index);

	UFUNCTION()
	void CheckAndUpdateLevel();

	UFUNCTION()
	void AddAdditionalPlayers();

private:
	UGameManager* mGameManager;

	uint32 mPlayerIterator{ 0 };
};
