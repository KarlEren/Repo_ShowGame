// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "SGAIController.generated.h"

/**
 * 
 */
UCLASS()
class SHOWGAME_API ASGAIController : public AAIController
{
	GENERATED_BODY()


	
protected:
	
	virtual void OnPossess(APawn* InPawn) override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TObjectPtr<UBehaviorTree> BehaviorTree;

	UFUNCTION()
	void OnPerceptionUpdate(const TArray<AActor*>& UpdatedActors);
	
};
