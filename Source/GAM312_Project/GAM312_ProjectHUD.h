// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once 

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "GAM312_ProjectHUD.generated.h"

UCLASS()
class AGAM312_ProjectHUD : public AHUD
{
	GENERATED_BODY()

public:
	AGAM312_ProjectHUD();

	/** Primary draw call for the HUD */
	virtual void DrawHUD() override;

	virtual void BeginPlay() override;


private:
	/** Crosshair asset pointer */
	class UTexture2D* CrosshairTex;

	// added for health ui elements
	UPROPERTY(EditAnywhere, Category = "Health")
		TSubclassOf<class UUserWidget> HUDWidgetClass;

	UPROPERTY(EditAnywhere, Category = "Health")
		class UUserWidget* CurrentWidget;
};

