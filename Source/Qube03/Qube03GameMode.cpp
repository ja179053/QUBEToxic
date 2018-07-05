// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#include "Qube03GameMode.h"
#include "Qube03HUD.h"
#include "Qube03Character.h"
#include "UObject/ConstructorHelpers.h"

AQube03GameMode::AQube03GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AQube03HUD::StaticClass();
}
