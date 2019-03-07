// Fill out your copyright notice in the Description page of Project Settings.

#include "PhaseWeapon.h"
#include "AcceleratePlayer.h"

APhaseWeapon::APhaseWeapon()
{

}

void APhaseWeapon::BeginPlay()
{
	Super::BeginPlay();
}

void APhaseWeapon::Tick(float DeltaTime)
{
	Super::BeginPlay();
}

void APhaseWeapon::Fire()
{
	GetOwningPlayer()->ActivatePhase(mTimer);
}