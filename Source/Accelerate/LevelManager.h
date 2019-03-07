// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"

#include "PrimaryWeaponTypes.h"

#include "LevelManager.generated.h"

class UGameManager;
class ACarController;
class AAcceleratePlayer;
/**
 *
 */
UCLASS()
class ACCELERATE_API ALevelManager : public AGameModeBase
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ALevelManager();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	const TArray<AAcceleratePlayer*>& GetPlayers() const;

	UPROPERTY(EditAnywhere, Category = "VehicleBlueprint")
		TSubclassOf<APawn> vehicleBlueprint;

private:
	virtual AActor* ChoosePlayerStart_Implementation(AController* Player) override;

	void InstantiateWeapon(AAcceleratePlayer* player, EPrimaryWeaponTypes primaryWeaponType);

private:
	TArray<AActor*> playerStarts;

	TArray<uint32> controllerIDs;

	UGameManager* mGameManager;

	uint32 playerStartAssignCode{ 0 };
};
