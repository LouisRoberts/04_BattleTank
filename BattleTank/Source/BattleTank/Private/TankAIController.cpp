// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	//UE_LOG(LogTemp, Warning, TEXT("PlayerController Begin Play"));

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("AITankController cant find player tank"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AITankController found player tank: %s"), *PlayerTank->GetName());
	}
}


// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	
	if (PlayerTank) {
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		
		// Fire if ready
		ControlledTank->Fire();
	}
}

