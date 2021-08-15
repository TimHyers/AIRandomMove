// Copyright Epic Games, Inc. All Rights Reserved.

#include "AIRandomMoveGameMode.h"
#include "AIRandomMoveCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAIRandomMoveGameMode::AAIRandomMoveGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
