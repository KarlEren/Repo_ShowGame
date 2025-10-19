// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AI/SGAIPawn.h"
#include "Engine/DataAsset.h"
#include "SGAIEnemyGroup.generated.h"

/**
 * 刷怪组，表示当前这个区域要刷什么怪
 */
UCLASS(Blueprintable)
class SHOWGAME_API USGAIEnemyGroup : public UDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(DisplayName="刷怪组"))
	TArray<TSubclassOf<ASGAIPawn>> Enemies;
	
};
