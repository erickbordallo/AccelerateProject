// Fill out your copyright notice in the Description page of Project Settings.

#include "CarController.h"
#include "UserWidget.h"

//Sets default values
ACarController::ACarController()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACarController::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ACarController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ACarController::CreateHUD()
{
	if (hudRef != nullptr)
	{
		mHud = CreateWidget(this, hudRef);

		if (mHud != nullptr)
		{
			mHud->AddToPlayerScreen();
		}
	}
}
