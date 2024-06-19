#include "level/GameLevelOne.h"
#include "enemy/Vanguard.h"
#include "framework/World.h"
#include "framework/Actor.h"
#include "framework/AssetManager.h"
#include "player/PlayerSpaceship.h"
#include "framework/TimerManager.h"
namespace ly
{
	GameLevelOne::GameLevelOne(Application* owningApp)
		: World{owningApp}
	{
		testPlayerSpaceship = SpawnActor<PlayerSpaceship>();
		testPlayerSpaceship.lock()->SetActorLocation(sf::Vector2f(300.f, 490.f));
		testPlayerSpaceship.lock()->SetActorRotation(0.f);

		weak<Vanguard> testSpaceship = SpawnActor<Vanguard>();
		testSpaceship.lock()->SetActorLocation(sf::Vector2f{ 100.f, 50.f });
	
	
	}
	void GameLevelOne::BeginPlay()
	{
		timerHandle_test = TimerManager::Get().SetTimer(GetWeakRef(), &GameLevelOne::TimerCallBack_Test, 2, true);
	}

	void GameLevelOne::TimerCallBack_Test()
	{
		log("callback called");
		TimerManager::Get().ClearTimer(timerHandle_test);
	}
}