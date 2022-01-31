// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"


void AMyAIController::BeginPlay()
{
	Super::BeginPlay();

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ATargetPoint::StaticClass(), Waypoints);

	GoToRandomWaypoint();
}
// used to select random waypoint using the FMath function within Unreal.
//  NOTE: look into way to select closer waypoints only so ai doesnt run full length of maze in one go.
ATargetPoint* AMyAIController::GetRandomWaypoint()
{

	auto index = FMath::RandRange(0, Waypoints.Num() - 1);
	return Cast<ATargetPoint>(Waypoints[index]);
}

// moves pawn to selected waypoint. 
// NOTE: more testing needed to see if AI can get stuck in maze.
void AMyAIController::GoToRandomWaypoint()
{

	MoveToActor(GetRandomWaypoint());

}

void AMyAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result)
{
	Super::OnMoveCompleted(RequestID, Result);

	// added to include delay before moving to next location.
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AMyAIController::GoToRandomWaypoint, 1.0f, false);
}