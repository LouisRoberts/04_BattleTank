// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimingComponent.h"
#include "TankTurret.h"
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
	//bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}

void UTankAimingComponent::Initialise(UTankBarrel * BarrelToSet, UTankTurret * TurretToSet)
{
	UE_LOG(LogTemp, Warning, TEXT("AimAt : 0 %s,%s"), *BarrelToSet->GetName(),*TurretToSet->GetName());
	Barrel = BarrelToSet;
	Turret = TurretToSet;
}

void UTankAimingComponent::AimAt(FVector HitLocation,float LaunchSpeed) {
	UE_LOG(LogTemp, Warning, TEXT("AimAt : 1"));
	if (!ensure(Barrel)) {
		UE_LOG(LogTemp, Warning, TEXT("AimAt : 2"));
		return;
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("AimAt : 3"));
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
			UE_LOG(LogTemp, Warning, TEXT("bHaveAimSolution : true"));
			auto AimDirection = OutLaunchVelocity.GetSafeNormal();
			MoveBarrelTowards(AimDirection);
		}
	}

}

void UTankAimingComponent::MoveBarrelTowards(FVector AimDirection) {
	UE_LOG(LogTemp, Warning, TEXT("MoveBarrelTowards : true"));
	if (!ensure(Barrel) || !ensure(Turret)) { return; }
	// Work out difference between curren barrel and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	//UE_LOG(LogTemp, Warning, TEXT("AimAsRotator : %s"), *AimAsRotator.ToString());

	Barrel->Elevate(DeltaRotator.Pitch);
	Turret->Rotate(DeltaRotator.Yaw);

}



