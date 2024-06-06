#pragma once
#include "framework/Actor.h"

namespace ly
{
	class Spaceship : public Actor
	{
	public:
		Spaceship(World* owningWorld, const std::string& texturePath = "");
		virtual void Tick(float deltaTime) override;
		void setVelocity(const sf::Vector2f& newVel);
		sf::Vector2f getVelocity() const {return mVelocity;}
	private:
		sf::Vector2f mVelocity;
	};
}