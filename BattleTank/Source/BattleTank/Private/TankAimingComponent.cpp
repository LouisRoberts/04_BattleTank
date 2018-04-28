// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankBarrel.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UTankAimingComponent::UTankAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UTankAimingComponent::AimAt(FVector HitLocation,float LaunchSpeed) {
	if (!Barrel) {
		return;
	}
	else {
		auto BarrelLocation = Barrel->GetComponentLocation().ToString();
		FVector OutLaunchVelocity;
		FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
		// calculate the out launch velocity
		bool bHaveAimSolution = UGameplayStatics::SuggestProjectileVelocity(
			this,
			OutLaunchVelocity,
			StartLocation,
			HitLocation,
			LaunchSpeed,
			false,
			0,
			0,
			ESuggestProjVelocityTraceOption::DoNotTrace);
		if(bHaveAimSolution) {
			auto AimDirection = OutLaunchVelocity.GetSafeNormal();
			auto OutTankName = GetOwner()->GetName();
			auto Time = GetWorld()->GetTimeSeconds();
			UE_LOG(LogTemp, Warning, TEXT("%f Aim Solution found with "), Time, *AimDirection.ToString());
			MoveBarrelTowards(AimDirection);
		}
		else {
			UE_LOG(LogTemp, Warning, TEXT("No Aim Solution found"));
		}
	}

}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {
	// Work out difference between curren barrel and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotatir = AimAsRotator - BarrelRotator;
	UE_LOG(LogTemp, Warning, TEXT("AimAsRotator : %s"), *AimAsRotator.ToString());

	Barrel->Elevate(5);

}

void UTankAimingComponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel = BarrelToSet;
}

