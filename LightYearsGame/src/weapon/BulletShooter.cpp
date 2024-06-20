#include "framework/Core.h"
#include "framework/World.h"
#include "weapon/BulletShooter.h"
#include "weapon/Bullet.h"

namespace ly
{
	BulletShooter::BulletShooter(Actor* owner, float cooldownTime)
		: Shooter{owner},
		mCooldownClock{},
		mCooldownTime{cooldownTime}
	{
	}

	bool BulletShooter::IsOnCooldown() const
	{
		if (mCooldownClock.getElapsedTime().asSeconds() > mCooldownTime)
		{
			return false;
		}

		return true;
	}

	void BulletShooter::ShootImpl()
	{
		mCooldownClock.restart();
		//log("shooting");
		weak<Bullet> newBullet = GetOwner()->GetWorld()->SpawnActor<Bullet>(GetOwner(), "SpaceShooterRedux/PNG/Lasers/laserBlue01.png");
		newBullet.lock()->SetActorLocation(GetOwner()->GetActorLocation());
		newBullet.lock()->SetActorRotation(GetOwner()->GetActorRotation());
		
	}
}