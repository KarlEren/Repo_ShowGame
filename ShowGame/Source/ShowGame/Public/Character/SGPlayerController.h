// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "SGPlayerController.generated.h"


class UInputMappingContext;
class UInputAction;


/**
 * 
 */
UCLASS()
class SHOWGAME_API ASGPlayerController : public APlayerController
{
	GENERATED_BODY()


protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:
	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputMappingContext> SGInputContext;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UInputAction> LookAction;

	void Move(const FInputActionValue& InputActionValue);

	void Jump(const FInputActionValue& InputActionValue);

	void StopJump(const FInputActionValue& InputActionValue);

	void Look(const FInputActionValue& InputActionValue);
	
};
