// Fill out your copyright notice in the Description page of Project Settings.


#include "SwitchButton.h"
#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"


// Sets default values
ASwitchButton::ASwitchButton()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	LightIntensity = 3000.f;

	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	PointLight->Intensity = LightIntensity;
	PointLight->bVisible = false;
	RootComponent = PointLight;

	LightSphere = CreateDefaultSubobject<USphereComponent>(TEXT("Light Sphere"));
	LightSphere->InitSphereRadius(300.f);
	LightSphere->SetCollisionProfileName(TEXT("Trigger"));
	LightSphere->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	LightSphere->SetupAttachment(RootComponent);

}

// Called when the game starts or when spawned
void ASwitchButton::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASwitchButton::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// used to turn light on and off by toggling visibility
void ASwitchButton::ToggleLight()
{
	PointLight->ToggleVisibility();
}