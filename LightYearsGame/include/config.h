#pragma once
#include <string>

std::string GetResouceDir()
{
#ifdef NDEBUG //release build
	return "assets/";
#else
	return "D:/LEARNEXTRA/c++games/udemy_lightYears/LightYears/LightYearsGame/assets/";
#endif
}
