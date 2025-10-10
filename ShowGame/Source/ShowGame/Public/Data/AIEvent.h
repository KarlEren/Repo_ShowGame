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

	virtual ~FSGAIEventBase(){}
};

USTRUCT(BlueprintType,meta=(DisplayName="这是一个普通的事件"))
struct FSGAIEvent:public FSGAIEventBase
{
	GENERATED_USTRUCT_BODY()

	virtual void PostAIDead() override;
};