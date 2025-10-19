// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/SGGameModeBase.h"

ASGGameModeBase::ASGGameModeBase()
{
	GameModeSubsystemCollection.Initialize(this);
}

void ASGGameModeBase::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	GameModeSubsystemCollection.Initialize(this);
}

void ASGGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GameModeSubsystemCollection.Deinitialize();
	Super::EndPlay(EndPlayReason);
}
