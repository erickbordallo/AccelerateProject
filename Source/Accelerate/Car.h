// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Components/SphereComponent.h"
#include "Materials/Material.h"
#include "PrimaryWeapon.h"
#include "Car.generated.h"


class UCurveFloat;
class USuspensionComponent;
class UStaticMeshComponent;
class USpringArmComponent;
class UCameraComponent;
class USuspensionComponent;
class UMaterial;


//START RAMMING CODE================================================
UENUM()
enum RammingColor
{
	Blue	UMETA(DisplayName = "Blue"),
	Red		UMETA(DisplayName = "Red")
};
//END RAMMING CODE================================================

/**
 *
 */

UCLASS()
class ACCELERATE_API ACar : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACar();

	//Functions--------------------------------------
	void Accelerate(float value);
	void RammingColorSwap();
	void BreakAndDrift();
	void TurnOfDrift();
	void Turn(float value);
	void Boost();
	void BoostTrueorFalse();
	void PitchCar(float value);
	void ActivateFlash();
	UFUNCTION()
	RammingColor GetRammingColor() { return mRammingColor; }

	UFUNCTION()
	bool GetCanRam() { return mCanRam; }

	UFUNCTION()
	void SetCanRam(bool canRam) { mCanRam = canRam; }


	UFUNCTION()
		void EnableDamage() { mCanTakeDamage = true; }

	UFUNCTION(BlueprintCallable, Category = "CarToWeapon")
	float GetCurrentSpeedOfCar();

	UFUNCTION(BlueprintCallable, Category = "Fog Weapon")
	void SlowCar(bool activate, float mod);

	UFUNCTION(BlueprintCallable, Category = "Phase Weapon")
	void ActivatePhase(float timer);

	UFUNCTION(BlueprintCallable, Category = "Phase Weapon")
	bool GetIsPhasing() const { return mIsPhasing; }

	UFUNCTION(BlueprintCallable, Category = "Phase Weapon")
	void SetIsPhasing(bool isphasing) { mIsPhasing = isphasing; }

	USceneComponent* GetRoot() { return RootComponent; }
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	void OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
		UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
	void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor,
			UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);
	//-----------------------------------------------------------------------------------

	//Variables--------------------------------------------------------------------------
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* Mesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* RLMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* RRMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* FLMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UStaticMeshComponent* FRMesh;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	UCameraComponent* Camera;

	UPROPERTY(Category = "Suspension", EditAnywhere)
	USuspensionComponent* FrontLeft;

	UPROPERTY(Category = "Suspension", EditAnywhere)
	USuspensionComponent* FrontRight;

	UPROPERTY(Category = "Suspension", EditAnywhere)
	USuspensionComponent* RearLeft;

	UPROPERTY(Category = "Suspension", EditAnywhere)
	USuspensionComponent* RearRight;

	UPROPERTY(Category = "PhysicsEnvironment", EditAnywhere)
	float gravity{ 4000.0f };

	UPROPERTY(Category = "Engine", EditAnywhere)
	UCurveFloat* Curve;

	UPROPERTY(Category = "Engine", EditAnywhere)
	UCurveFloat* TurnCurve;

	UPROPERTY(Category = "Flash Effect", EditAnywhere)
	UCurveFloat* flashCurve;

	UPROPERTY(Category = "Flash Effect", EditAnywhere)
	float maxFlashTimeEffect{ 3.0f };

	UPROPERTY(Category = "Engine", EditAnywhere)
	float Throtle{ 0.0f };

	UPROPERTY(Category = "Engine", EditAnywhere)
	float Acceleration{ 5.0f };

	UPROPERTY(EditAnywhere, Category = "Engine")
	float MaxBackwardsPower{ 4000.0f };

	UPROPERTY(EditAnywhere, Category = "Engine")
	float MaxPower{ 7500.0f };

	UPROPERTY(EditAnywhere, Category = "Engine")
	float BreakForce{ -6000.0f };

	UPROPERTY(EditAnywhere, Category = "Engine")
	float TurnForce{ 500000.0f };

	UPROPERTY(EditAnywhere, Category = "Engine")
	float LateralFriction{ 100.0f };

	UPROPERTY(EditAnywhere, Category = "Engine")
	FVector EngineLinearVelocity;

	UPROPERTY(EditAnywhere, Category = "Engine")
	float CurrentSpeed{ 0.0f };

	UPROPERTY(EditAnywhere, Category = "Engine")
	float MaxSpeed{ 30000.0f };

	UPROPERTY(EditAnywhere, Category = "Track")
	float TrackFriction{ 0.4f };

	UPROPERTY(EditAnywhere, Category = "Steering")
	FVector Heading;

	UPROPERTY(EditAnywhere, Category = "Engine")
	float PitchForce{ 500000.0f };

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Boost")
	float BoostCurrent = 69;

	UPROPERTY(EditAnywhere, Category = "Boost")
	float BoostMax = 100;

	UPROPERTY(EditAnywhere, Category = "Boost")
	float boostGaugeDelay = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Boost")
	float Timer = 0.0f;

	UPROPERTY(EditAnywhere, Category = "Boost")
	float BoostGain = 1.0f;

	UPROPERTY(EditAnywhere, Category = "Boost")
	bool BoostTrue = false;

	UPROPERTY(EditAnywhere, Category = "Boost")
	float ForceOnGround = 200;

	UPROPERTY(EditAnywhere, Category = "Boost")
	float ForceInAir = 25;

	UPROPERTY(EditAnywhere, Category = "Boost")
	float MaxBoostSpeed = 40000;

	UPROPERTY(EditAnywhere, Category = "Boost")
	float BoostUsed = 0.5f;

	UPROPERTY(EditAnywhere, Category = "CameraProperties")
	float lagStep = 2.0f;

	UPROPERTY(EditAnywhere, Category = "CameraProperties")
	float lagDistanceModifier = 100.0f;

	UPROPERTY(EditAnywhere, Category = "CameraProperties")
	float lagMaxDistance = 500.0f;

	UPROPERTY(EditAnywhere, Category = "CameraProperties")
	float lagMinDistance = 50.0f;

	UPROPERTY(EditAnywhere, Category = "CameraProperties")
	float lagCurrentDistance = 100.0f;
		
	UPROPERTY(EditAnywhere, Category = "Car Stability")
	float Stability = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Car Stability")
	float StabilizingSpeed = 0.5f;

	UPROPERTY(EditAnywhere, Category = "Car Stability")
	float rollBackForce = 15000.0f;

	UPROPERTY(EditAnywhere, Category = "Phase Effect")
	float phaseTimer = 3.0f;



private:
	//Variable------------------------------------------
	UStaticMeshComponent* mRammingSphere;
	TEnumAsByte<RammingColor> mRammingColor;
	
	UMaterial* mBlueMaterial;
	UMaterial* mRedMaterial;

	bool mCanRam;
	bool mIsCameraLagging;

	float flashTimer;

	bool mIsPhasing{ false };
	bool mMeshIsOverlaping{ false };

	float mTempMaxSpeed;

	FString displayText;
	bool mCanTakeDamage{ true };
	float mCurrentLateralFriction{ 100.0f };
	//----------------------------------------------------

	//Functions-------------------------------------------
	void BalanceCar();
	void ApplyGravity();
	void SolveSuspension();
	FVector CalculateSuspensionForce(USuspensionComponent* suspension, FHitResult hit);
	bool OnGround();
	void LagOnBoost();
	void ActivateRearCamera();
	void ActivateRotationLag();
	void TestJump();
	bool IsUpsideDown();
	void ApplyCounterTorque();
	void PhaseMaterialEffect(bool active);
	void PhasePhysicsEffect(bool active);
	//----------------------------------------------------
};