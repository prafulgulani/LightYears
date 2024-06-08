#include "framework/Actor.h"
#include "framework/Core.h"
#include "framework/AssetManager.h"
#include "framework/MathUtility.h"
#include "framework/World.h"

namespace ly
{
	Actor::Actor(World* owningWorld, const std::string& texturePath)
		: mOwningWorld(owningWorld),
		mHasBeganPlay{ false },
		mSprite{},
		mTexture{}
	{
		SetTexture(texturePath);
	}

	Actor::~Actor()
	{
		log("actor destroyed");
	}

	void Actor::BeginPlayInternal()
	{
		if (!mHasBeganPlay)
		{
			mHasBeganPlay = true;
			BeginPlay();
		}
	}

	void Actor::TickInternal(float deltaTime)
	{
		if (!isPendingDestroy())
		{
			Tick(deltaTime);
		}
	}

	void Actor::BeginPlay()
	{
	}

	void Actor::Tick(float deltaTime)
	{
	}
	void Actor::SetTexture(const std::string& texturePath)
	{
		mTexture = AssetManager::Get().LoadTexture(texturePath);
		if (!mTexture) return;
		mSprite.setTexture(*mTexture);

		int textureWidth = mTexture->getSize().x;
		int textureHeight = mTexture->getSize().y;
		mSprite.setTextureRect(sf::IntRect{ sf::Vector2i{}, sf::Vector2i{textureWidth, textureHeight} });
		CenterPivot();
	}
	void Actor::Render(sf::RenderWindow& window)
	{
		if (isPendingDestroy())
		{
			return;
		}
		window.draw(mSprite);
	}
	void Actor::SetActorLocation(const sf::Vector2f& newLoc)
	{
		mSprite.setPosition(newLoc);
	}
	void Actor::SetActorRotation(float newRot)
	{
		mSprite.setRotation(newRot);
	}
	void Actor::AddActorLocationOffset(const sf::Vector2f& offsetAmt)
	{
		SetActorLocation(GetActorLocation() + offsetAmt);
	}
	void Actor::AddActorRotationOffset(float offsetAmt)
	{
		SetActorRotation(GetActorRotation() + offsetAmt);
	}
	sf::Vector2f Actor::GetActorLocation() const
	{
		return mSprite.getPosition();
	}
	float Actor::GetActorRotation() const
	{
		return mSprite.getRotation();
	}
	sf::Vector2f Actor::GetActorForwardDirection() const
	{
		return RotationToVector(GetActorRotation());
	}
	sf::Vector2f Actor::GetActorRightDirection() const
	{
		return RotationToVector(GetActorRotation() + 90.f);
	}
	sf::FloatRect Actor::GetActorGloabalBounds() const
	{
		return mSprite.getGlobalBounds();
	}
	sf::Vector2u Actor::GetWindowSize() const
	{
		return mOwningWorld->GetWindowSize();
	}
	bool Actor::IsActorOutOfWindowBounds() const
	{
		float windowWidth = GetWorld()->GetWindowSize().x;
		float windowHeight = GetWorld()->GetWindowSize().y;
		
		float width = GetActorGloabalBounds().width;
		float height = GetActorGloabalBounds().height;
		
		sf::Vector2f actorPos = GetActorLocation();

		if (actorPos.x < -width)
		{
			return true;
		}
		if (actorPos.x > windowWidth + width)
		{
			return true;
		}
		if (actorPos.y < -width)
		{
			return true;
		}
		if (actorPos.y > windowWidth + height)
		{
			return true;
		}
		return false;
	}

	void Actor::CenterPivot()
	{
		sf::FloatRect bound = mSprite.getGlobalBounds();
		mSprite.setOrigin(bound.width / 2.f, bound.height / 2.f);
	}
}