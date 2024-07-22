#include "widgets/GameplayHUD.h"

namespace ly
{
	GameplayHUD::GameplayHUD()
		: mFramerateText{"Framerate: "}
	{
		mFramerateText.SetTextSize(25);
	}
	void GameplayHUD::Draw(sf::RenderWindow& windowRef)
	{
		mFramerateText.NativeDraw(windowRef);
	}
	void GameplayHUD::Tick(float deltaTime)
	{
		int frameRate = int(1 / deltaTime);
		std::string frameRateStr = "Framerate: " + std::to_string(frameRate);
		mFramerateText.SetString(frameRateStr);
	}
}
