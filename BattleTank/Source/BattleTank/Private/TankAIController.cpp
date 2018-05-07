// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "BattleTank.h"
#include "Engine/World.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}


// Called every frame
void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	
	if (PlayerTank) {

		MoveToActor(PlayerTank, AcceptanceRadius);
		ControlledTank->AimAt(PlayerTank->GetActorLocation());
		
		// Fire if ready
		ControlledTank->Fire();
	}
}

