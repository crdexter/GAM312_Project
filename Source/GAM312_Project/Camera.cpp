// Fill out your copyright notice in the Description page of Project Settings.


#include "Camera.h"
#include "Kismet/GameplayStatics.h"
#include "Engine.h"



// Sets default values
ACamera::ACamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACamera::BeginPlay()
{
	Super::BeginPlay();
	
    APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);
    const float SmoothBlendTime = 1.5f;
    int count = 2;

    // added to only allow two camera changes for intro camera move
    while (count > 0)
    {
        count--;

        if ((OurPlayerController->GetViewTarget() != CameraOne) && (CameraOne != nullptr))
        {
            //Cut instantly to camera one.
            OurPlayerController->SetViewTarget(CameraOne);
        }
        else if ((OurPlayerController->GetViewTarget() != CameraTwo) && (CameraTwo != nullptr))
        {
            //Blend smoothly to camera two.
            OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
        }
    }
}

// old function scrapped. the constant switching not needed for the intro function
 /*void ACamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

    const float TimeBetweenCameraChanges = 2.0f;
    const float SmoothBlendTime = 0.75f;

    TimeToNextCamera -= DeltaTime;

    int count = 2;


    if (TimeToNextCamera <= 0.0f)
    {
        TimeToNextCamera += TimeBetweenCameraChanges;

        //Find the actor that handles control for the local player.
        APlayerController* OurPlayerController = UGameplayStatics::GetPlayerController(this, 0);

        if (count > 0)
        {
            count--;

            if ((OurPlayerController->GetViewTarget() != CameraOne) && (CameraOne != nullptr))
            {
                //Cut instantly to camera one.
                OurPlayerController->SetViewTarget(CameraOne);
            }
            else if ((OurPlayerController->GetViewTarget() != CameraTwo) && (CameraTwo != nullptr))
            {
                //Blend smoothly to camera two.
                OurPlayerController->SetViewTargetWithBlend(CameraTwo, SmoothBlendTime);
            }
        }
    
    }
}*/


