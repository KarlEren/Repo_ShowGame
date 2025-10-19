// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Subsystems/GameModeSubsystem.h"
#include "SGGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SHOWGAME_API ASGGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	template<typename T>
	T* GetSubsystem() const
	{
		return GameModeSubsystemCollection.GetSubsystem<T>();
	}

protected:
	ASGGameModeBase();
	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;
private:
	FSubsystemCollection<UGameModeSubsystem> GameModeSubsystemCollection;
	
};
