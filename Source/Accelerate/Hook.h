//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "CoreMinimal.h"
//#include "SecondaryWeapon.h"
//#include "Components/BoxComponent.h"
//#include "Hook.generated.h"
//
///**
// * 
// */
//UCLASS()
//class ACCELERATE_API AHook : public ASecondaryWeapon
//{
//	GENERATED_BODY()
//public:
//
//	AHook();
//
//	void BeginPlay() override;
//
//	void Tick(float DeltaTime) override;
//
//	void Fire() override;
//
//	UFUNCTION()
//	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor,
//		class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
//
//	UPROPERTY(EditAnywhere, Category = "HookProperties")
//	float hookPullSpeed{ 10.0f };
//
//	UPROPERTY(EditAnywhere, Category = "HookProperties")
//	float hookPullDuration{ 3.0f };
//
//	UPROPERTY(EditAnywhere, Category = "HookProperties")
//	float hookTravelSpeed{ 8000.0f };
//
//private:
//	bool mIsActive{ false };
//	UPROPERTY(EditAnywhere)
//	UBoxComponent* mHookCollider{ nullptr };
//	FVector mFireDirection{ 0.0f };
//	class AAcceleratePlayer* mHookedPlayer{ nullptr };
//};
