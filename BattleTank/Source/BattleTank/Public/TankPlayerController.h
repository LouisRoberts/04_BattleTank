#pragma once

//#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimingComponent;

/**
 * AIms the tank
 */
UCLASS()
class BATTLETANK_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	UFUNCTION(BlueprintImplementableEvent, Category = "Setup")
		void FoundAimingComponent(UTankAimingComponent* AimCompRef);
	
	UFUNCTION()
		void OnPossessedTankDeath();

private:
	void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Move tank barrel towards crosshair
	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& HitLocation) const;

	bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;

	// The following are in the HUD
	UPROPERTY(EditDefaultsOnly)
	float CrossHairXLocation = 0.5;
	
	UPROPERTY(EditDefaultsOnly)
	float CrossHairYLocation = 0.3333;

	UPROPERTY(EditDefaultsOnly)
	float LineTraceRange = 1000000.0; // 10KM

	

};
