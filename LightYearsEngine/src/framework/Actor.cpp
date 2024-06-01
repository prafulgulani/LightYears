#include "framework/Actor.h"
#include "framework/Core.h"

namespace ly
{
	Actor::Actor(World* owningWorld)
		: mOwningWorld(owningWorld),
		mHasBeganPlay{ false }
	{

	}

	Actor::~Actor()
	{
	}

	void Actor::BeginPlayInternal()
	{
		if (!mHasBeganPlay)
		{
			mHasBeganPlay = true;
			BeginPlay();
		}
	}

	void Actor::BeginPlay()
	{
		log("actor beign play");
	}

	void Actor::Tick(float deltaTime)
	{
		log("actor ticking");

	}
}