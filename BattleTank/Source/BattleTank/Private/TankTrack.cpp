// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTrack.h"

UTankTrack::UTankTrack() {

}

void UTankTrack::SetThrottle(float Throttle)
{
	auto Name = GetName();
	//UE_LOG(LogTemp, Warning, TEXT("%s throttle : %f"),*Name, Throttle);
	// TODO clamp throttle to +/-1
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied,ForceLocation);

}
