// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * Tank Barrel
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UTankBarrel();

	// -1 is max downward movement
	// +1 is max upward movement
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly)
		float MaxDegreesPerSecond = 10;
	
	UPROPERTY(EditDefaultsOnly)
		float MaxElevationDegrees = 40;

	UPROPERTY(EditDefaultsOnly)
		float MinElevationDegrees = 0;
};
