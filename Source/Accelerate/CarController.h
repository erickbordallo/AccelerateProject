// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CarController.generated.h"

class UUserWidget;
/**
 * 
 */
UCLASS()
class ACCELERATE_API ACarController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ACarController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void CreateHUD();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	TSubclassOf<UUserWidget> hudRef;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player")
	UUserWidget* mHud;
private:
};
