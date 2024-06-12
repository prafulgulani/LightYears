#pragma once
#include "framework/Actor.h"
#include "gameplay/HealthComponent.h"

namespace ly
{
	class Spaceship : public Actor
	{
	public:
		Spaceship(World* owningWorld, const std::string& texturePath = "");
		virtual void Tick(float deltaTime) override;
		void setVelocity(const sf::Vector2f& newVel);
		sf::Vector2f getVelocity() const {return mVelocity;}
		virtual void Shoot();
		virtual void BeginPlay() override;
	private:
		void OnHealthChanged(float amt, float health, float maxHealth);
		sf::Vector2f mVelocity;
		HealthComponent mHealthComp;
	};
}