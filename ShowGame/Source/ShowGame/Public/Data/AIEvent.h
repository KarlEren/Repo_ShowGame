// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InstancedStruct.h"
#include "UObject/Object.h"
#include "AIEvent.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FSGAIEventBase
{
	GENERATED_USTRUCT_BODY()

	virtual void PostAIDead(){}

	virtual void PostAIAllDead(){}

	virtual void PostAIAttributeChange(){}

	virtual void PostAISpawn(){}

	virtual void PostAIAllSpawn(){}

	virtual ~FSGAIEventBase(){}
};

USTRUCT(BlueprintType,meta=(DisplayName="全部生成完毕后打印测试信息"))
struct FSGAIAllSpawnPrintLog:public FSGAIEventBase
{
	GENERATED_USTRUCT_BODY()

	virtual void PostAIAllSpawn() override;
};