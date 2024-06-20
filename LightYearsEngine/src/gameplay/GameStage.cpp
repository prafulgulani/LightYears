#include "gameplay/GameStage.h"
#include "framework/Core.h"

namespace ly
{
	GameStage::GameStage(World* world)
		: mWorld{world}
	{
	}
	
	void GameStage::StartStage()
	{
		log("stage start");
	}
	
	void GameStage::TickStage(float deltaTime)
	{
		log("stage ticking");
	}
	
	void GameStage::FinishedStage()
	{
		OnStageFinished.Broadcast();
		mStageFinished = true;
		StageFinished();
	}

	void GameStage::StageFinished()
	{
		log("stage finished");
	}
}