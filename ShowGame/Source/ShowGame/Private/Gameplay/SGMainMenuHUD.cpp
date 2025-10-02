// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/SGMainMenuHUD.h"

#include "Blueprint/UserWidget.h"

void ASGMainMenuHUD::BeginPlay()
{
	Super::BeginPlay();
	
	//要是主菜单没有配置，那玩家就什么也动不了，直接崩溃算了
	checkf(MainMenuClass,TEXT("主菜单类引用没有配置，检查一下蓝图"));
	UWorld* World = GetWorld();
	
	checkf(World,TEXT("World获取失败"))
	MainMenuWidget = CreateWidget<UUserWidget>(World,MainMenuClass);
	
	checkf(MainMenuWidget,TEXT("主菜单加载失败"));
	MainMenuWidget->AddToViewport();	
}
