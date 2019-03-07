// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PrimaryWeaponTypes.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class EPrimaryWeaponTypes : uint8
{
	None	        UMETA(DisplayName = "None"),
	LaserBlaster	UMETA(DisplayName = "LaserBlaster"),
	Flamethrower	UMETA(DisplayName = "Flamethrower"),
	Railgun     	UMETA(DisplayName = "Railgun")
};
