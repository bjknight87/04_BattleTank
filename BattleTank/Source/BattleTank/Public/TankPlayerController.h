// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "../Public/Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"  // Must be last include

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
	bool GetSightRayHitLocation(FVector& HitLocation) const;

private:
	ATank* GetControlledTank() const;

	// Start the tank moving the barrell so that a shot would hit where
	// the crosshair hits the world
	void AimTowardsCrosshair();

UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;

UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;

UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
};
