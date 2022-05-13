// Fill out your copyright notice in the Description page of Project Settings.


#include "MoonOrbit.h"
#define PI 3.14159265358979323846  
#include <math.h>       /* cos */

// Sets default values for this component's properties
UMoonOrbit::UMoonOrbit()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMoonOrbit::BeginPlay()
{
	Super::BeginPlay();
	moonLocation.X = planetLocation.X;
	moonLocation.Y = planetLocation.Y;
	moonLocation.Z = planetLocation.Z;
	// ...
	
}


float keepToRadius(float planet, float moon, float radius) {
	float diff = planet - moon;

	if (abs(diff) > radius) {
		if (diff < 0) {
			return planet + radius;
		}
		else {
			return planet - radius;
		}
	}

	return moon;
}

// Called every frame
void UMoonOrbit::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	moonLocation.Z = planetLocation.Z;

	int speed = 5;
	int radius = 600;

	float planetX = planetLocation.X;
	float planetY = planetLocation.Y;

	float moonX = moonLocation.X;
	float moonY = moonLocation.Y;


	moonX = keepToRadius(planetX, moonX, radius);
	moonY = keepToRadius(planetY, moonY, radius);

	// Make be zero origined.
	moonX -= planetX;
	moonY -= planetY;

	// Calculate new coordinate (rotate one degree);
	float x = (moonX * cos(speed * PI / 180))  - (moonY * sin(speed * PI / 180));
	float y = (moonY * cos(speed * PI / 180)) + (moonX * sin(speed * PI / 180));

	// Re-set the variables
	moonLocation.X = x;
	moonLocation.Y = y;

	// Move back to planet origined.
	moonLocation.X += planetX;
	moonLocation.Y += planetY;
}

