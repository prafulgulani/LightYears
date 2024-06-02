#include "gameFramework/GameApplication.h"
#include "framework/World.h"
#include "framework/Actor.h"


ly::Application* GetApplication()
{
	return new ly::GameApplication{};
}

namespace ly
{
	GameApplication::GameApplication()
		: Application{ 600, 900, "Light Years", sf::Style::Titlebar | sf::Style::Close }
	{
		weak<World> newWorld = LoadWorld<World>();
		newWorld.lock()->SpawnActor<Actor>();
		actorToDestroy = newWorld.lock()->SpawnActor<Actor>();
		actorToDestroy.lock()->SetTexture("D:/LEARNEXTRA/c++games/udemy_lightYears/LightYears/LightYearsGame/assets/assets/SpaceShooterRedux/PNG/playerShip1_blue.png");
	    counter = 0;
	}
	void GameApplication::Tick(float deltaTime)
	{
		counter += deltaTime;
		if (counter > 2.f)
		{
			if (!actorToDestroy.expired()) // if corresponding shared ptr is removed
			{
				actorToDestroy.lock()->Destroy();
			}
		}
	}
}