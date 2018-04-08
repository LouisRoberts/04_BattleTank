// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "Tank.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;
	
	void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Move tank barrel towards crosshair
	void AimTowardsCrosshair();

private:
	bool GetSightRayHitLocation(FVector& HitLocation) const;
};
