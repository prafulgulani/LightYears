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
#include "player/PlayerManager.h"
#include "widgets/GameplayHUD.h"

namespace ly
{
	GameLevelOne::GameLevelOne(Application* owningApp)
		: World{owningApp}
	{
		
	}
	void GameLevelOne::BeginPlay()
	{
		Player newPlayer = PlayerManager::Get().CreateNewPlayer();
		mPlayerSpaceship = newPlayer.SpawnSpaceship(this);
		mPlayerSpaceship.lock()->onActorDestroyed.BindAction(GetWeakRef(), &GameLevelOne::PlayerSpaceshipDestroyed);
		mGameplayHUD = SpawnHUD<GameplayHUD>();
	}

	void GameLevelOne::PlayerSpaceshipDestroyed(Actor* destroyedPlayerSpaceship)
	{
		mPlayerSpaceship = PlayerManager::Get().GetPlayer()->SpawnSpaceship(this);
		if (!mPlayerSpaceship.expired())
		{
			mPlayerSpaceship.lock()->onActorDestroyed.BindAction(GetWeakRef(), &GameLevelOne::PlayerSpaceshipDestroyed);
		}
		else
		{
			GameOver();
		}
	}

	void GameLevelOne::InitGameStages()
	{
		AddStage(shared<WaitStage>{new WaitStage{ this, 2.f }});
		AddStage(shared<VanguardStage>{new VanguardStage{ this }});
		
		AddStage(shared<WaitStage>{new WaitStage{ this, 5.f }});
		AddStage(shared<TwinBladeStage>{new TwinBladeStage{ this }});
	
		AddStage(shared<WaitStage>{new WaitStage{ this, 2.f }});
		AddStage(shared<UFOStage>{new UFOStage{ this }});
		
		AddStage(shared<WaitStage>{new WaitStage{ this, 2.f }});
		AddStage(shared<HexagonStage>{new HexagonStage{ this }});
	}

	void GameLevelOne::GameOver()
	{
		log("game over ===================================================");
	}
}