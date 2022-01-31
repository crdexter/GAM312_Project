// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SwitchButton.generated.h"

UCLASS()
class GAM312_PROJECT_API ASwitchButton : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASwitchButton();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	// value for pointlight actor
	UPROPERTY(VisibleAnywhere, Category = "Switch")
		class UPointLightComponent* PointLight;

	UPROPERTY(VisibleAnywhere, Category = "Switch")
		class USphereComponent* LightSphere;

	UPROPERTY(VisibleAnywhere, Category = "Switch")
		float LightIntensity;

	UFUNCTION(BlueprintCallable, Category = "Switch")
		void ToggleLight();


};
