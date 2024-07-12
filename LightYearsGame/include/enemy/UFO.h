#pragma once

#include "enemy/EnemySpaceship.h"

namespace ly
{
	class BulletShooter;
	class UFO : public EnemySpaceship
	{
	public:
		UFO(World* owningWorld, const sf::Vector2f& velocity, const std::string& texturePath = "SpaceShooterRedux/PNG/ufoBlue.png", float rotationSpeed = 300.f);

		virtual void Tick(float deltaTime) override;

	private:
		virtual void Shoot() override;

		unique<BulletShooter> mShooter1;
		unique<BulletShooter> mShooter2;
		unique<BulletShooter> mShooter3;
		unique<BulletShooter> mShooter4;
		unique<BulletShooter> mShooter5;

		float mRotationSpeed;

	};
}