// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/SGHUD.h"

#include "Subsystems/SGUISubsystem.h"



void ASGHUD::BeginPlay()
{
	Super::BeginPlay();
	UWorld *World = GetWorld();
	if (!World)
	{
		return;
	}
	UISubsystem = World->GetSubsystem<USGUISubsystem>();
	if (!UISubsystem)
	{
		UE_LOG(LogSlate, Error, TEXT("UI子系统获取失败"));
	}
}
