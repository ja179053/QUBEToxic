// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Red.generated.h"

UCLASS()
class QUBE03_API ARed : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARed();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int32 movedPositions = 0;
	UBoxComponent* _collision;
	FVector targetPos;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void Move();

	UPROPERTY(EditAnywhere)
		TArray<int32> positions;
	UPROPERTY(EditAnywhere)
		int32 distanceMultiplier = 100;

	
	
};
