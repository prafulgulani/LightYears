#include "framework/Object.h"
#include "framework/Core.h"

namespace ly
{
	Object::Object()
		:mIsPendingDestroy{false}
	{
	}

	Object::~Object()
	{
		log("object destroyed");
	}

	void Object::Destroy()
	{
		mIsPendingDestroy = true;
	}
}