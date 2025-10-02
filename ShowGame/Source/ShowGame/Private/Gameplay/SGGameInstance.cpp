// Fill out your copyright notice in the Description page of Project Settings.


#include "Gameplay/SGGameInstance.h"

#include "Data/GameData.h"
#include "Settings/DataSettings/SGGameDataSettings.h"
#include "ShowGame/ShowGame.h"

TSubclassOf<AGameModeBase> USGGameInstance::OverrideGameModeClass(TSubclassOf<AGameModeBase> GameModeClass,
                                                                  const FString& MapName, const FString& Options, const FString& Portal) const
{
	if (GameMapInfos)
	{
		TArray<FSGGameMapInfo*> GameMapInfoRows;
		GameMapInfos->GetAllRows(TEXT("未找到数据行"),GameMapInfoRows);
		for (const FSGGameMapInfo* GameMapInfoRow : GameMapInfoRows)
		{
			if (GameMapInfoRow && GameMapInfoRow->WorldMap)
			{
				FString WorldName = GameMapInfoRow->WorldMap->GetMapName();
				if (WorldName.Equals(MapName))
				{
					return GameMapInfoRow->GameMode;
				}
			}
		}
	}
	return Super::OverrideGameModeClass(GameModeClass, MapName, Options, Portal);
}

void USGGameInstance::Init()
{
	Super::Init();
	USGGameDataSettings *GameDataSettings = GetMutableDefault<USGGameDataSettings>();
	if (GameDataSettings)
	{
		//这里不知道为什么异步加载会失效
		GameMapInfos = GameDataSettings->GameMapInfos.LoadSynchronous();	
	}
	else
	{
		UE_LOG(LogGameData,Error,TEXT("项目设置界面的数据表失效"))
	}
}
