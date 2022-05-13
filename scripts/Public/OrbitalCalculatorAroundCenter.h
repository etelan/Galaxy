// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "OrbitalCalculatorAroundCenter.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GALAXYPROJECT_API UOrbitalCalculatorAroundCenter : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOrbitalCalculatorAroundCenter();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 x;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 y;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 stepSpeed;


	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int32 orbitRadius;
		
};
