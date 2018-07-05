// Fill out your copyright notice in the Description page of Project Settings.

#include "Blue.h"


// Sets default values
ABlue::ABlue()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	_collision = CreateDefaultSubobject<UBoxComponent>(TEXT("RootComponent"));
	_collision->OnComponentBeginOverlap.AddDynamic(this, &ABlue::OnBlueOverlapBegin);
	RootComponent = _collision;
//	positions = new int[1];
//	positions[0] = 1;
}

// Called when the game starts or when spawned
void ABlue::BeginPlay()
{
	Super::BeginPlay();
}

void ABlue::OnBlueOverlapBegin(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) {
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Triggered"));
	//OtherActor->GetRootComponent()->ComponentVelocity = FVector(0.0f, 100.0f, 0.0f);
	OtherComp->AddImpulseAtLocation(GetVelocity() * force, GetActorLocation()); 
}
