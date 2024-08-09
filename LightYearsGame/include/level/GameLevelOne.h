#pragma once
#include "framework/World.h"
#include "framework/TimerManager.h"

namespace ly
{
	class PlayerSpaceship;
	class GameplayHUD;
	class GameLevelOne : public World
	{
	public:
		GameLevelOne(Application* owningApp);
	private:
		virtual void AllGameStageFinished() override;
		virtual void BeginPlay() override;
		weak<PlayerSpaceship> mPlayerSpaceship;
		weak<GameplayHUD> mGameplayHUD;
		void PlayerSpaceshipDestroyed(Actor* destroyedPlayerSpaceship);
		TimerHandle timerHandle_test;
		virtual void InitGameStages() override;
		void GameOver();
		void QuitGame();
		void Restart();
		void SpawnCosmetics();
	};
}