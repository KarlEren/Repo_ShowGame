// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/SGAIController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "ShowGame/ShowGame.h"



void ASGAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	if (BehaviorTree)
	{
		RunBehaviorTree(BehaviorTree);	
	}
	else
	{
		UE_LOG(LogAI,Error,TEXT("行为树未赋值"))
	}

	UAIPerceptionComponent *AIPerceptionComp = GetPerceptionComponent();
	if (AIPerceptionComp)
	{
		AIPerceptionComp->OnPerceptionUpdated.AddDynamic(this, &ASGAIController::OnPerceptionUpdate);
	}
}

void ASGAIController::OnPerceptionUpdate(const TArray<AActor*>& UpdatedActors)
{
	for (const AActor* UpdatedActor : UpdatedActors)
	{
		if (UpdatedActor->ActorHasTag(FName{"Player"}))
		{
			UBlackboardComponent * BlackboardComponent = GetBlackboardComponent();
			if (BlackboardComponent)
			{
				FVector Location = UpdatedActor->GetActorLocation();
				BlackboardComponent->SetValueAsBool(FName{"HasSeenPlayer"}, true);
				BlackboardComponent->SetValueAsVector(FName{"PlayerLocation"},Location);
			}
		}
	}
}

