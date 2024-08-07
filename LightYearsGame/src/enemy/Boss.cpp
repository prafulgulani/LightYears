#include "enemy/Boss.h"
#include "gameplay/HealthComponent.h"

namespace ly
{
	Boss::Boss(World* world)
		: EnemySpaceship{ world, "SpaceShooterRedux/PNG/Enemies/boss.png" },
		mSpeed{ 100.f },
		mSwitchDistanceToEdge{ 100.f },
		mBaseShooterLeft{ this, 1.0f, {-50.f, -30.f} },
		mBaseShooterRight{ this, 1.0f, {50.f, -30.f} },
		mThreeWayShooter{ this, 4.f, {0.f, -130.f} },
		mFrontalWiperLeft{ this, 5.f, {-80.f, 0.f} },
		mFrontalWiperRight{ this, 5.f, {80.f, 0.f} },
		mFinalStageShooterLeft{this, 0.3f, {-150.f, 50.f}},
		mFinalStageShooterRight{this, 0.3f, {150.f, 50.f}},
		mStage{ 1 }
	{
		SetActorRotation(180.f);
		SetVelocity({ mSpeed, 0.f });
		SetRewardSpawnWeight(0.f);		
	}

	void Boss::Tick(float deltaTime)
	{
		EnemySpaceship::Tick(deltaTime);
		BaseShooters();
		ThreeWayShooter();
		FrontalWiperShooter();
		if (mStage == 4)
		{
			mFinalStageShooterLeft.Shoot();
			mFinalStageShooterRight.Shoot();
		}
		CheckMove();
	}

	void Boss::BeginPlay()
	{
		EnemySpaceship::BeginPlay();
		HealthComponent& healthComp = GetHealthComp();
		healthComp.SetInitialHealth(3000.f, 3000.f);
		healthComp.onHealthChanged.BindAction(GetWeakRef(), &Boss::HeaalthChanged);
	}

	void Boss::CheckMove()
	{
		if (GetActorLocation().x > GetWindowSize().x - mSwitchDistanceToEdge)
		{
			SetVelocity({ -mSpeed, 0.f });
		}
		else if (GetActorLocation().x < mSwitchDistanceToEdge)
		{
			SetVelocity({ mSpeed, 0.f });
		}
	}

	void Boss::BaseShooters()
	{
		mBaseShooterLeft.Shoot();
		mBaseShooterRight.Shoot();
	}

	void Boss::ThreeWayShooter()
	{
		mThreeWayShooter.Shoot();
	}

	void Boss::FrontalWiperShooter()
	{
		mFrontalWiperLeft.Shoot();
		mFrontalWiperRight.Shoot();
	}

	void Boss::HeaalthChanged(float amt, float currentHealth, float maxHealth)
	{
		float percentHealth = currentHealth / maxHealth;
		if (percentHealth < 0.7 && percentHealth > 0.5)
		{
			SetStage(2);
		}
		if (percentHealth < 0.5 && percentHealth > 0.3)
		{
			SetStage(3);
		}
		if (percentHealth < 0.3)
		{
			SetStage(4);
		}
	}

	void Boss::SetStage(int newStage)
	{
		mStage = newStage;
		mBaseShooterLeft.SetCurrentLevel(mStage);
		mBaseShooterRight.SetCurrentLevel(mStage);
		mFrontalWiperLeft.SetCurrentLevel(mStage);
		mFrontalWiperRight.SetCurrentLevel(mStage);
		mThreeWayShooter.SetCurrentLevel(mStage);
	}

	


}