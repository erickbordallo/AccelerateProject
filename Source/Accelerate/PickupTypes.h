// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PickupTypes.generated.h"

UENUM(BlueprintType)
enum class EPickupCategories : uint8
{
	DefensiveWeapon	UMETA(DisplayName = "DefensiveWeapon"),
	OffensiveWeapon	UMETA(DisplayName = "OffensiveWeapon"),
	Boost	UMETA(DisplayName = "Boost"),
	Health	UMETA(DisplayName = "Health")
};

// Once the Pickup is finished add it to the list.
UENUM(BlueprintType)
enum class EPickupTypes : uint8
{
	none,
	//Utility Pickups
	Boost UMETA(DisplayName = "Boost"),
	Health UMETA(DisplayName = "Health"),

	//Defensive Pickups
	Mine UMETA(DisplayName = "Mine"),
	// Put new Defense Weapons in this space


	EMP UMETA(DisplayName = "EMP"),

	//Offensive Pickups
	Missle UMETA(DisplayName = "Missle"),
	// Put new Offensive Weapons in this space



	Hook UMETA(DisplayName = "Hook")

};