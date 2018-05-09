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
	
private:
	ATank* GetControlledTank() const;
	
	void BeginPlay() override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Move tank barrel towards crosshair
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	// The following are in the HUD
	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.3333;
	
	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.5;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0; // 10KM

};
