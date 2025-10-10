// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SGAreaController.generated.h"
/*
 *原视频里是以墙为分界划出一个个关卡区域，所以这里每个对应关卡都有一个区域管理器
 */
UCLASS()
class SHOWGAME_API ASGAreaController : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASGAreaController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
