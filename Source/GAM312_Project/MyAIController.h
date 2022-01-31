// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Runtime/Engine/Classes/Engine/TargetPoint.h"
#include "MyAIController.generated.h"



/**
 * 
 */
UCLASS()
class GAM312_PROJECT_API AMyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
    void BeginPlay() override;

private:  // creating array for the waypoints
    UPROPERTY()
        TArray<AActor*> Waypoints;

    UFUNCTION() 
        ATargetPoint* GetRandomWaypoint();

    UFUNCTION()
        void GoToRandomWaypoint();
// included to prompt AI to find new location 
public:
    void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;

private:
    FTimerHandle TimerHandle;

};


