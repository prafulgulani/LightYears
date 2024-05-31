#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>

#include "framework/Application.h"

int main()
{
	//ly::Application* app = new ly::Application();
	//app->Run();

	std::unique_ptr<ly::Application> app = std::make_unique<ly::Application>();
	app->Run();
}