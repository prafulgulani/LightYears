#include "gameFramework/GameApplication.h"
#include "level/GameLevelOne.h"
#include "framework/AssetManager.h"
#include "config.h"

ly::Application* GetApplication()
{
	return new ly::GameApplication{};
}

namespace ly
{
	GameApplication::GameApplication()
		: Application{ 600, 900, "Light Years", sf::Style::Titlebar | sf::Style::Close }
	{
		AssetManager::Get().SetAssetRootDirectory(GetResourceDir());
		weak<GameLevelOne> newWorld = LoadWorld<GameLevelOne>();
		
	}
	
}