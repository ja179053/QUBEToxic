// Fill out your copyright notice in the Description page of Project Settings.

#include "Red.h"


// Sets default values
ARed::ARed()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	_collision = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));

}

// Called when the game starts or when spawned
void ARed::BeginPlay()
{
	Super::BeginPlay();
	targetPos = GetActorLocation();
	positions = { 1,1,1 };
}

// Called every frame
void ARed::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SetActorLocation(targetPos);
}

// Called every frame
void ARed::Move()
{
		FVector moveTo = GetActorForwardVector();
	movedPositions++;
	if (movedPositions > positions.Max()) {
		movedPositions = 0;
		int32 total = 0;
		for (int32 i = 0; i < positions.Max(); i++) {
			total += positions[i];
		}
		moveTo *= -total * distanceMultiplier;
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, TEXT("Moving Back"));
	}
	else {
		moveTo *= positions[movedPositions - 1] * distanceMultiplier;
		GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Blue, TEXT("Moving forward"));
	}
	targetPos = moveTo + targetPos;

}

