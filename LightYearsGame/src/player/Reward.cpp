#include "framework/World.h"
#include "player/Reward.h"
#include "player/PlayerSpaceship.h"
#include "weapon/ThreeWayShooter.h"
#include "weapon/FrontalWiper.h"
namespace ly
{
	Reward::Reward(World* world, const std::string& texturePath, RewardFunc rewardFunc, float speed)
		: Actor{ world, texturePath },
		mRewardFunc{ rewardFunc },
		mSpeed{speed}
	{
	}

	void Reward::BeginPlay()
	{
		Actor::BeginPlay();
		SetEnablePhysics(true);
	}

	void Reward::Tick(float deltaTime)
	{
		Actor::Tick(deltaTime);
		AddActorLocationOffset({ 0.f, mSpeed * deltaTime });
	}

	void Reward::OnActorBeginOverlap(Actor* otherActor)
	{
		// todo: clean up casting
		PlayerSpaceship* playerSpaceship = dynamic_cast<PlayerSpaceship*>(otherActor);
		if (playerSpaceship != nullptr && !playerSpaceship->isPendingDestroy())
		{
			mRewardFunc(playerSpaceship);
			Destroy();
		}
	}


	weak<Reward> CreateHealthReward(World* world)
	{
		return CreateReward(world, "SpaceShooterRedux/PNG/pickups/pill_green.png", RewardHealth);
	}

	weak<Reward> CreateThreeWayShooterReward(World* world)
	{
		return CreateReward(world, "SpaceShooterRedux/PNG/pickups/three_shooter_pickup.png", RewardThreeWayShooter);
	}

	weak<Reward> CreateFrontalWiperReward(World* world)
	{
		return CreateReward(world, "SpaceShooterRedux/PNG/pickups/front_row_shooter_pickup.png", RewardFrontalWiper);
	}

	weak<Reward> CreateReward(World* world, const std::string& texturePath, RewardFunc rewardFunc)
	{
		weak<Reward> reward = world->SpawnActor<Reward>(texturePath, rewardFunc);
		return reward;
	}

	void RewardHealth(PlayerSpaceship* player)
	{
		static float rewardAmt = 10.f;
		if (player && !player->isPendingDestroy())
		{
			player->GetHealthComp().ChangeHealth(rewardAmt);
		}
	}

	void RewardThreeWayShooter(PlayerSpaceship* player)
	{
		if (player && !player->isPendingDestroy())
		{
			player->SetShooter(unique<Shooter>{new ThreeWayShooter{ player, 0.4f, {0.f, -50.f} }});
		}
	}

	void RewardFrontalWiper(PlayerSpaceship* player)
	{
		if (player && !player->isPendingDestroy())
		{
			player->SetShooter(unique<Shooter>{new FrontalWiper{ player, 0.4f, {0.f, -50.f} }});
		}
	}

}