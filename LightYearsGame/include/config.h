#pragma once
#include <string>

std::string GetResourceDir()
{
#ifdef NDEBUG //RELEASE BUILD
	return "assets/";
#else //debug build
	return "D:/LEARNEXTRA/c++games/udemy_lightYears/LightYears/LightYearsGame/assets/";
#endif //  NDEBUG //RELEASE BUILD
}
