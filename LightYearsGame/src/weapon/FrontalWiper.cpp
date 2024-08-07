#include "weapon/FrontalWiper.h"

namespace ly
{
	FrontalWiper::FrontalWiper(Actor* ownerActor, float cooldownTime, const sf::Vector2f& localOffset, float width)
		: Shooter{ownerActor}, 
		mWidth{width},
		mShooter1{ownerActor, cooldownTime, {localOffset.x - width/2.f, localOffset.y},  0.f, "SpaceShooterRedux/PNG/Lasers/laserGreen11.png"},
		mShooter2{ownerActor, cooldownTime, {localOffset.x - width/6.f, localOffset.y},  0.f, "SpaceShooterRedux/PNG/Lasers/laserBlue07.png"},
		mShooter3{ ownerActor, cooldownTime, {localOffset.x + width/6.f, localOffset.y},  0.f, "SpaceShooterRedux/PNG/Lasers/laserBlue07.png" },
		mShooter4{ownerActor, cooldownTime, {localOffset.x + width/2.f, localOffset.y},  0.f, "SpaceShooterRedux/PNG/Lasers/laserGreen11.png"},
		mShooter5{ownerActor, cooldownTime, {localOffset.x + width/1.5f, localOffset.y},  0.f, "SpaceShooterRedux/PNG/Lasers/laserGreen11.png"},
		mShooter6{ownerActor, cooldownTime, {localOffset.x - width/1.5f, localOffset.y},  0.f, "SpaceShooterRedux/PNG/Lasers/laserGreen11.png"}
	{
	}
	void FrontalWiper::IncrementLevel(int amt)
	{
		Shooter::IncrementLevel(amt);
		mShooter1.IncrementLevel(amt);
		mShooter2.IncrementLevel(amt);
		mShooter3.IncrementLevel(amt);
		mShooter4.IncrementLevel(amt);
		mShooter5.IncrementLevel(amt);
		mShooter6.IncrementLevel(amt);

	}

	void FrontalWiper::SetCurrentLevel(int level)
	{
		Shooter::SetCurrentLevel(level);
		mShooter1.SetCurrentLevel(level);
		mShooter2.SetCurrentLevel(level);
		mShooter3.SetCurrentLevel(level);
		mShooter4.SetCurrentLevel(level);
		mShooter5.SetCurrentLevel(level);
		mShooter6.SetCurrentLevel(level);
	}

	void FrontalWiper::ShootImpl()
	{
		mShooter1.Shoot();
		mShooter2.Shoot();
		mShooter3.Shoot();
		mShooter4.Shoot();

		if (GetCurrentLevel() == GetMaxLevel())
		{
			mShooter5.Shoot();
			mShooter6.Shoot();
		}
	}
}