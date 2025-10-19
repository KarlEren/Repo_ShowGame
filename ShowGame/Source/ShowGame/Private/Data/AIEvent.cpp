// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/AIEvent.h"

void FSGAIAllSpawnPrintLog::PostAIAllSpawn()
{
	FSGAIEventBase::PostAIAllSpawn();
	GEngine->AddOnScreenDebugMessage(-1,10.f,FColor::Green,TEXT("AI全部生成完毕"));
}
