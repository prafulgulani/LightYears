#pragma once

#include "enemy/EnemySpaceship.h"
#include "weapon/BulletShooter.h"
#include "weapon/ThreeWayShooter.h"
#include "weapon/FrontalWiper.h"

namespace ly
{
	class Boss : public EnemySpaceship
	{
	public:
		Boss(World* world);
		
		virtual void Tick(float deltaTime);
		virtual void BeginPlay() override;
		
	private:
		float mSpeed;
		float mSwitchDistanceToEdge;
		void CheckMove();

		BulletShooter mBaseShooterLeft;
		BulletShooter mBaseShooterRight;

		ThreeWayShooter mThreeWayShooter;
		FrontalWiper mFrontalWiperLeft;
		FrontalWiper mFrontalWiperRight;

		BulletShooter mFinalStageShooterLeft;
		BulletShooter mFinalStageShooterRight;

		void BaseShooters();
		void ThreeWayShooter();
		void FrontalWiperShooter();
		void HeaalthChanged(float amt, float currentHealth, float maxHealth);

		void SetStage(int newStage);
		int mStage;
	};
}