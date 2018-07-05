// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Blue.h"
#include "Red.h"
#include "Components/InputComponent.h"
#include "Raycast.generated.h"

UCLASS(config=Game)
class ARaycast : public ACharacter
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARaycast();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:	
	// Called every frame
	void Raycast();
	bool FindCube(FHitResult* RV_Hit, FCollisionQueryParams* RV_TraceParams);
private:
	ABlue* blue;
	ARed* cube;
	UPROPERTY()
		float CubeDistance = 10;	
};
