// Fill out your copyright notice in the Description page of Project Settings.


#include "OrbitalCalculatorAroundCenter.h"
#include <math.h> 
#define PI 3.14159265


// This is not best practice! Should move it into the .h class, to make it more readable.
bool circleForward = true;
int radius = 750;
float Step;

// Sets default values for this component's properties
UOrbitalCalculatorAroundCenter::UOrbitalCalculatorAroundCenter()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	// ...
}



float setX(float t) {
	return radius * cos(t);
}

float setY(float t) {
	return radius * sin(t);
}


// Called when the game starts
void UOrbitalCalculatorAroundCenter::BeginPlay()
{
	Super::BeginPlay();
	Step = 0;
	x = 0;
	y = 0;	
}


// Called every frame
void UOrbitalCalculatorAroundCenter::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{

	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	Step += 0.01f;

	x = setX(Step);
	y = setY(Step);

}

