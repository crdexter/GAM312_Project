// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GAM312_ProjectCharacter.h"
#include "GAM312_ProjectGameMode.generated.h"



UENUM()
enum class EGamePlayState
{
	EPlaying,
	EGameOver,
	EUnknown
};

UCLASS(minimalapi)
class AGAM312_ProjectGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGAM312_ProjectGameMode();
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	AGAM312_ProjectCharacter* MyCharacter;

	/** Returns the current playing state */
	UFUNCTION(BlueprintPure, Category = "Health")
		EGamePlayState GetCurrentState() const;

	/** Sets a new playing state */
	void SetCurrentState(EGamePlayState NewState);

private:
	/**Keeps track of the current playing state */
	EGamePlayState CurrentState;

	/**Handle any function calls that rely upon changing the playing state of our game */
	void HandleNewState(EGamePlayState NewState);
};



