// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "SGGameDataSettings.generated.h"

/**
 * 
 */
UCLASS(Config = Game,DefaultConfig,meta=(DisplayName="游戏数据设置"))
class SHOWGAME_API USGGameDataSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:

	virtual FName GetCategoryName() const override;

	UPROPERTY(EditAnywhere,Config,BlueprintReadWrite,meta=(DisplayName = "游戏关卡地图数据"))
	TSoftObjectPtr<UDataTable> GameMapInfos;

	
};
