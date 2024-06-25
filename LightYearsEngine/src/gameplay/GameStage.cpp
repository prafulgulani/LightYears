#include "gameplay/GameStage.h"
#include "framework/Core.h"

namespace ly
{
	GameStage::GameStage(World* world)
		: mWorld{world},
		mStageFinished{false}
	{
	}
	
	void GameStage::StartStage()
	{
		log("stage started");
	}
	
	void GameStage::TickStage(float deltaTime)
	{
	}
	
	void GameStage::FinishStage()
	{
		onStageFinished.Broadcast();
		mStageFinished = true;
		StageFinished();
	}

	void GameStage::StageFinished()
	{
		log("stage finished");
	}
}