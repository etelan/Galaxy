// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitalCoordinateCalculator.h"

// This is not best practice! Should move it into the .h class, to make it more readable and reduce scope of the variables.
bool forward = true;
float EllipseStep = 0;

// Sets default values for this component's properties
UOrbitalCoordinateCalculator::UOrbitalCoordinateCalculator()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOrbitalCoordinateCalculator::BeginPlay()
{
	Super::BeginPlay();

	PrimaryComponentTick.bCanEverTick = true;
	x = 0;
	y = 0;
	
}

float getX(float t) {
	return 900 * cos(t);
}

float getY(float t) {
	return 350 * sin(t);
}


// Called every frame
void UOrbitalCoordinateCalculator::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	EllipseStep += 0.01f;

	x = getX(EllipseStep);
	y = getY(EllipseStep);
}

