// Fill out your copyright notice in the Description page of Project Settings.

#include "AutoDoor.h"


// Sets default values
AAutoDoor::AAutoDoor()
{
	_collision = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
	_collision->OnComponentBeginOverlap.AddDynamic(this, &AAutoDoor::OnDoorOverlapBegin);
	RootComponent = _collision;

}

// Called when the game starts or when spawned
void AAutoDoor::BeginPlay()
{
	Super::BeginPlay();
	SetActorHiddenInGame(false);
	
}
void AAutoDoor::OnDoorOverlapBegin(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Triggered"));
	SetActorHiddenInGame(true);
}

