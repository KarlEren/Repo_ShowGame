// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InstancedStruct.h"
#include "SGAIBasket.h"
#include "Data/SGAIEnemyGroup.h"
#include "SGAISpawner.generated.h"

/*
 * AI生成器看，负责每个区域的AI生成
 */

UENUM(BlueprintType)
enum class ESGAIEventType : uint8
{
	Spawn = 0,
	AllSpawn,
	Dead,
	AllDead,
};


UCLASS()
class SHOWGAME_API ASGAISpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASGAISpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(DisplayName="AI事件回调列表"))
	TArray<FInstancedStruct> AIEventList;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,meta=(DisplayName="刷怪组"))
	TObjectPtr<USGAIEnemyGroup> AIEnemyGroup;

private:
	void SpawnAI();

	UPROPERTY()
	TObjectPtr<USGAIBasket> AIBasket;

	void ExecEvent(ESGAIEventType EventType);
	
};
