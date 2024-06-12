#include "spaceship/Spaceship.h"
#include "framework/Core.h"

namespace ly
{
	Spaceship::Spaceship(World* owningWorld, const std::string& texturePath)
		: Actor(owningWorld, texturePath),
		mVelocity{},
		mHealthComp{100.f, 100.f}
	{

	}

	void Spaceship::Tick(float deltaTime)
	{
		Actor::Tick(deltaTime);
		AddActorLocationOffset(getVelocity() * deltaTime);
	}

	void Spaceship::setVelocity(const sf::Vector2f& newVel)
	{
		mVelocity = newVel;
	}

	void Spaceship::Shoot()
	{

	}

	void Spaceship::BeginPlay()
	{
		Actor::BeginPlay();
		SetEnablePhysics(true);

		mHealthComp.onHealthChanged.BindAction(GetWeakRef(), &Spaceship::OnHealthChanged);
	
		mHealthComp.onHealthChanged.Broadcast(11, 89, 100);
	}

	void Spaceship::OnHealthChanged(float amt, float health, float maxHealth)
	{
		log("health changed");
	}
	
}