// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/BoxComponent.h"
#include "AutoDoor.generated.h"

UCLASS()
class AAutoDoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AAutoDoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	UFUNCTION()
		void OnDoorOverlapBegin(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UBoxComponent* _collision;

	
	
};
