// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "Blue.generated.h"

UCLASS()
class ABlue : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlue();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UFUNCTION()
		void OnBlueOverlapBegin(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UBoxComponent* _collision;
	UPROPERTY(EditAnywhere)
	int32 force = 100;
	
	
};
