// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplay/SGHUD.h"
#include "SGMainMenuHUD.generated.h"

/**
 * 
 */
UCLASS()
class SHOWGAME_API ASGMainMenuHUD : public ASGHUD
{
	GENERATED_BODY()


protected:

	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TSubclassOf<UUserWidget> MainMenuClass;
	
private:
	TObjectPtr<UUserWidget> MainMenuWidget;	
};
