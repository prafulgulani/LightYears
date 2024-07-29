#include "level/MainMenuLevel.h"
#include "widgets/MainMenuHUD.h"

namespace ly
{
	MainMenuLevel::MainMenuLevel(Application* owningApplication)
		: World{owningApplication}
	{
		mMainMenuHUD = SpawnHUD<MainMenuHUD>();
	}
	void MainMenuLevel::BeginPlay()
	{
		mMainMenuHUD.lock()->onStartButtonClicked.BindAction(GetWeakRef(), &MainMenuLevel::StartGame);
		mMainMenuHUD.lock()->onQuitButtonClicked.BindAction(GetWeakRef(), &MainMenuLevel::QuitGame);
	}
	void MainMenuLevel::StartGame()
	{
		log("starting game");
	}
	void MainMenuLevel::QuitGame()
	{
		log("ending game");
	}
}