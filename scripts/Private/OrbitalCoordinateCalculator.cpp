// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitalCoordinateCalculator.h"

bool forward = true;
float EllipseStep = 0;

// Sets default values for this component's properties
UOrbitalCoordinateCalculator::UOrbitalCoordinateCalculator()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
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

