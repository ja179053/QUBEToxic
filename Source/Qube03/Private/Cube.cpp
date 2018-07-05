// Fill out your copyright notice in the Description page of Project Settings.

#include "Cube.h"


// Sets default values
ACube::ACube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACube::BeginPlay()
{
	Super::BeginPlay();
	targetPos = GetActorLocation();
	
}
void ACube::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
	SetActorLocation(targetPos * DeltaTime);
}

// Called every frame
void ACube::Move()
{
	movedPositions++;
	FVector moveTo;
	if (movedPositions > positions.Max()) {
		movedPositions = 0;
		int32 total = 0;
		for (int32 i = 0; i < positions.Max(); i++) {
			total += i;
		}
		moveTo = (GetActorForwardVector() * -total);
	}
	else {
		moveTo = (GetActorForwardVector() * positions[movedPositions - 1]);
	}
	targetPos = moveTo + targetPos;
}

