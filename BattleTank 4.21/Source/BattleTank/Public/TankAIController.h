#pragma once
#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class ATank;

/**
 * 
 */
UCLASS()
class BATTLETANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(EditDefaultsOnly, Category= "Setup")
		float AcceptanceRadius = 8000;

private:
	virtual void BeginPlay() override;

	virtual void SetPawn(APawn* InPawn) override;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnPossessedTankDeath();
	
};
