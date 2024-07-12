#include "level/GameLevelOne.h"
#include "enemy/UFO.h"
#include "enemy/UFOStage.h"
#include "enemy/Vanguard.h"
#include "enemy/HexagonStage.h"
#include "enemy/TwinBladeStage.h"
#include "enemy/VanguardStage.h"
#include "framework/Actor.h"
#include "framework/AssetManager.h"
#include "framework/TimerManager.h"
#include "framework/World.h"
#include "gameplay/GameStage.h"
#include "gameplay/WaitStage.h"
#include "player/PlayerSpaceship.h"

namespace ly
{
	GameLevelOne::GameLevelOne(Application* owningApp)
		: World{owningApp}
	{
		testPlayerSpaceship = SpawnActor<PlayerSpaceship>();
		testPlayerSpaceship.lock()->SetActorLocation(sf::Vector2f(300.f, 490.f));
		testPlayerSpaceship.lock()->SetActorRotation(0.f);
	
	}
	void GameLevelOne::BeginPlay()
	{
	}

	void GameLevelOne::InitGameStages()
	{
		AddStage(shared<WaitStage>{new WaitStage{ this, 2.f }});
		AddStage(shared<UFOStage>{new UFOStage{ this }});
		
		AddStage(shared<WaitStage>{new WaitStage{ this, 2.f }});
		AddStage(shared<HexagonStage>{new HexagonStage{ this }});
		
		AddStage(shared<WaitStage>{new WaitStage{ this, 2.f }});
		AddStage(shared<VanguardStage>{new VanguardStage{ this }});
		
		AddStage(shared<WaitStage>{new WaitStage{ this, 5.f }});
		AddStage(shared<TwinBladeStage>{new TwinBladeStage{ this }});
	}
}