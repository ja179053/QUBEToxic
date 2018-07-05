// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Cube.generated.h"

UCLASS()
class ACube : public ACharacter
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACube();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	int32 movedPositions = 0;

public:
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void Move();
	FVector targetPos;

	UPROPERTY(EditAnywhere)
		TArray<int32> positions;
};
