// Copyright Epic Games, Inc. All Rights Reserved.

#include "KarundaRaiderGameMode.h"
#include "KarundaRaiderCharacter.h"
#include "UObject/ConstructorHelpers.h"

AKarundaRaiderGameMode::AKarundaRaiderGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
