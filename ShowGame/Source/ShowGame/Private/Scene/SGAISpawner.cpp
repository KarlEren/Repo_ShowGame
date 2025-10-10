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
	for (FInstancedStruct Event:AIEventList)
	{
		FSGAIEvent AIEvent = Event.Get<FSGAIEvent>();
		AIEvent.PostAIDead();
	}
}

// Called every frame
void ASGAISpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

