// Copyright Epic Games, Inc. All Rights Reserved.

#include "TreasureRetrievalGameMode.h"
#include "TreasureRetrievalCharacter.h"
#include "UObject/ConstructorHelpers.h"

ATreasureRetrievalGameMode::ATreasureRetrievalGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
