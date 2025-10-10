// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/BTTask_MoveToPlayer.h"

#include "AI/SGAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Navigation/PathFollowingComponent.h"

EBTNodeResult::Type UBTTask_MoveToPlayer::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	ASGAIController *AICon = Cast<ASGAIController>(OwnerComp.GetAIOwner());
	if (!AICon)
	{
		return EBTNodeResult::Failed;
	}
	UBlackboardComponent *BlackboardComponent = OwnerComp.GetBlackboardComponent();
	if (!BlackboardComponent)
	{
		return EBTNodeResult::Failed;
	}
	FVector PlayerLocation = BlackboardComponent->GetValueAsVector(FName{"PlayerLocation"});
	EPathFollowingRequestResult::Type MoveRet=AICon->MoveToLocation(PlayerLocation);
	switch (MoveRet)
	{
	case EPathFollowingRequestResult::Type::Failed:
		return EBTNodeResult::Failed;
	case EPathFollowingRequestResult::Type::RequestSuccessful:
		return EBTNodeResult::Succeeded;
	case EPathFollowingRequestResult::Type::AlreadyAtGoal:
		return EBTNodeResult::InProgress;
	}
	return EBTNodeResult::Failed;
}
