// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SGGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SHOWGAME_API USGGameInstance : public UGameInstance
{
	GENERATED_BODY()

	//实验一个小功能，根据配置表来确定每张地图的玩法
	virtual TSubclassOf<AGameModeBase> OverrideGameModeClass(TSubclassOf<AGameModeBase> GameModeClass, const FString& MapName, const FString& Options, const FString& Portal) const override;

	virtual void Init() override;
	
	UPROPERTY()
	TObjectPtr<UDataTable> GameMapInfos;
};
