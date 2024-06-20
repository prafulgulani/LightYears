#pragma once

#include "framework/Object.h"
#include "framework/Delegate.h"

namespace ly
{
	class World;
	class GameStage : public Object
	{
	public:
		GameStage(World* world);
		const World* GetWorld() const { return mWorld; }
		World* GetWorld() { return mWorld; }
		
		Delegate<> OnStageFinished;

		virtual void StartStage();
		virtual void TickStage(float deltaTime);
		void FinishedStage();
		bool IsStageFinished() const { return mStageFinished; }
	
	private:
		World* mWorld;
		bool mStageFinished;
		virtual void StageFinished();
	};
}