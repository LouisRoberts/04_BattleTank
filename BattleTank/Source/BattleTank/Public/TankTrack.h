// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

/**
 * Tank track is used to set maximum driving force to the tank
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
		UTankTrack();
		
		UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);

		// This is max force in Newtons
		UPROPERTY(EdiTDefaultsOnly)
			float TrackMaxDrivingForce = 40000000; // 40 tonne tank 1g acceleration

};