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

	moonLocation.Z = planetLocation.Z + 200;

	int speed = 5;
	int radius = 600;

	moonLocation.X = keepToRadius(planetLocation.X, moonLocation.X, radius);
	moonLocation.Y = keepToRadius(planetLocation.Y, moonLocation.Y, radius);

	// Make be zero origined.
	moonLocation.X -= planetLocation.X;
	moonLocation.Y -= planetLocation.Y;

	// Calculate new coordinate (rotate one degree);
	float x = (moonLocation.X * cos(speed * PI / 180))  - (moonLocation.Y * sin(speed * PI / 180));
	float y = (moonLocation.Y * cos(speed * PI / 180)) + (moonLocation.X * sin(speed * PI / 180));

	// Re-set the variables
	moonLocation.X = x;
	moonLocation.Y = y;

	// Move back to planet origined.
	moonLocation.X += planetLocation.X;
	moonLocation.Y += planetLocation.Y;
}

