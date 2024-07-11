#pragma once

#include "enemy/EnemySpaceship.h"

namespace ly
{
	class BulletShooter;
	class TwinBlade : public EnemySpaceship
	{
	public:
		TwinBlade(World* owningWorld, const std::string texturePath = "SpaceShooterRedux/PNG/Enemies/enemyBlack1.png", const sf::Vector2f& velocity = sf::Vector2f{ 0.f, 120.f });
		virtual void Tick(float deltaTime) override;

	private:
		virtual void Shoot() override;
		unique<BulletShooter> mShooterLeft;
		unique<BulletShooter> mShooterRight;
	};
}