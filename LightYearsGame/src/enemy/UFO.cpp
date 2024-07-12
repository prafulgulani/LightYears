#include "enemy/UFO.h"
#include "weapon/BulletShooter.h"

namespace ly
{
	UFO::UFO(World* owningWorld, const sf::Vector2f& velocity, const std::string& texturePath, float rotationSpeed)
		: EnemySpaceship{owningWorld, texturePath},
		mShooter1{ new BulletShooter{this, .8f, sf::Vector2f{0.f, 0.f}, 0} },
		mShooter2{ new BulletShooter{this, .8f, sf::Vector2f{0.f, 0.f}, 72} },
		mShooter3{ new BulletShooter{this, .8f, sf::Vector2f{0.f, 0.f}, 144} },
		mShooter4{ new BulletShooter{this, .8f, sf::Vector2f{0.f, 0.f}, 216} },
		mShooter5{ new BulletShooter{this, .8f, sf::Vector2f{0.f, 0.f}, 288} },
		mRotationSpeed{rotationSpeed}
	{
		SetVelocity(velocity);
		SetActorRotation(180.f);
	}

	void UFO::Tick(float deltaTime)
	{
		EnemySpaceship::Tick(deltaTime);
		Shoot();
		AddActorRotationOffset(mRotationSpeed * deltaTime);
	}

	void UFO::Shoot()
	{
		mShooter1->Shoot();
		mShooter2->Shoot();
		mShooter3->Shoot();
		mShooter4->Shoot();
		mShooter5->Shoot();
	}

	
}