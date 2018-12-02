// Fill out your copyright notice in the Description page of Project Settings.

//#include "BattleTank.h"
#include "../Public/TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing tank."));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing tank %s."), *(ControlledTank->GetName()));
	}

}

// Tick
// Called every frame
void ATankPlayerController::Tick(float DeltaTime)
{
	// Super
	Super::Tick( DeltaTime );
	// AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const 
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair() 
{
	if (!GetControlledTank()) { return; }

	// Get world location through linetrace crosshair 
	// If it hits the landscape
		// Tell controlled tank to aim at this point
}


