// Fill out your copyright notice in the Description page of Project Settings.


#include "Scene/SGAISpawner.h"

#include "Data/AIEvent.h"


// Sets default values
ASGAISpawner::ASGAISpawner()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ASGAISpawner::BeginPlay()
{
	Super::BeginPlay();
	//只是做个测试，肯定是要按照实际需要调用Spawn的
	SpawnAI();
}

// Called every frame
void ASGAISpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASGAISpawner::SpawnAI()
{
	if (!AIEnemyGroup)
	{
		return;
	}
	for (const TSubclassOf<ASGAIPawn>& AIRef : AIEnemyGroup->Enemies)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
 		GetWorld()->SpawnActor<ASGAIPawn>(AIRef,GetActorLocation(),GetActorRotation(),SpawnParams);
	}
	ExecEvent(ESGAIEventType::AllSpawn);
}

void ASGAISpawner::ExecEvent(ESGAIEventType EventType)
{
	for (FInstancedStruct Event:AIEventList)
	{
		FSGAIEventBase *AIEvent = Event.GetMutablePtr<FSGAIEventBase>();
		switch (EventType)
		{
		case ESGAIEventType::Spawn:
			AIEvent->PostAISpawn();
			break;
		case ESGAIEventType::AllSpawn:
			AIEvent->PostAIAllSpawn();
			break;
		case ESGAIEventType::Dead:
			AIEvent->PostAIDead();
			break;
		case ESGAIEventType::AllDead:
			AIEvent->PostAIAllDead();
			break;
		}
	}
}


