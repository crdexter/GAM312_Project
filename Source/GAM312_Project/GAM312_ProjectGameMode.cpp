// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GAM312_ProjectGameMode.h"
#include "GAM312_ProjectHUD.h"
#include "GAM312_ProjectCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "UObject/ConstructorHelpers.h"


AGAM312_ProjectGameMode::AGAM312_ProjectGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AGAM312_ProjectHUD::StaticClass();
}


void AGAM312_ProjectGameMode::BeginPlay()
{
	Super::BeginPlay();

	SetCurrentState(EGamePlayState::EPlaying);

	MyCharacter = Cast<AGAM312_ProjectCharacter>(UGameplayStatics::GetPlayerPawn(this, 0));
}

void AGAM312_ProjectGameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GetWorld()->GetMapName();

}

EGamePlayState AGAM312_ProjectGameMode::GetCurrentState() const
{
	return CurrentState;
}

void AGAM312_ProjectGameMode::SetCurrentState(EGamePlayState NewState)
{
	CurrentState = NewState;
	HandleNewState(CurrentState);
}

void AGAM312_ProjectGameMode::HandleNewState(EGamePlayState NewState)
{
	switch (NewState)
	{
	case EGamePlayState::EPlaying:
	{
		// do nothing
	}
	break;
	// Unknown/default state
	case EGamePlayState::EGameOver:
	{
		UGameplayStatics::OpenLevel(this, FName(*GetWorld()->GetName()), false);
	}
	break;
	// Unknown/default state
	default:
	case EGamePlayState::EUnknown:
	{
		// do nothing
	}
	break;
	}
}