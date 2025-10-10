// Fill out your copyright notice in the Description page of Project Settings.


#include "Data/AIEvent.h"

void FSGAIEvent::PostAIDead()
{
	FSGAIEventBase::PostAIDead();
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, "AI Dead");
}
