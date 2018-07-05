// Fill out your copyright notice in the Description page of Project Settings.

#include "Raycast.h"


// Sets default values
ARaycast::ARaycast()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARaycast::BeginPlay()
{
	Super::BeginPlay();
}
void ARaycast::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent){
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &ARaycast::Raycast);
}

// Called every frame
void ARaycast::Raycast()
{
	FHitResult RV_Hit(ForceInit);
	FCollisionQueryParams RV_TraceParams = FCollisionQueryParams(FName(TEXT("RV_Trace")), true, this);
	if (FindCube(&RV_Hit, &RV_TraceParams)) {
		cube = (ARed*)RV_Hit.GetActor();
		if (cube) {
			cube->Move();
		}
	}
}
bool ARaycast::FindCube(FHitResult* RV_Hit, FCollisionQueryParams* RV_TraceParams) {
	FVector cameraLoc;
	FRotator cameraRot;
	GetActorEyesViewPoint(cameraLoc, cameraRot);
	FVector start = cameraLoc;
	FVector end = cameraLoc + (cameraRot.Vector() * CubeDistance);

	RV_TraceParams->bTraceComplex = true;
	RV_TraceParams->bTraceAsyncScene = true;
	RV_TraceParams->bReturnPhysicalMaterial = true;

	bool trace = GetWorld()->LineTraceSingleByChannel(
		*RV_Hit,
		start,
		end,
		ECC_Pawn,
		*RV_TraceParams
	);

	if (trace) {
		return true;
	}
	return false;
}

