#pragma once
#include <string>

<<<<<<< HEAD
std::string GetResouceDir()
{
#ifdef NDEBUG //release build
	return "assets/";
#else
	return "D:/LEARNEXTRA/c++games/udemy_lightYears/LightYears/LightYearsGame/assets/";
#endif
=======
std::string GetResourceDir()
{
#ifdef NDEBUG //RELEASE BUILD
	return "assets/";
#else //debug build
	return "D:/LEARNEXTRA/c++games/udemy_lightYears/LightYears/LightYearsGame/assets/";
#endif //  NDEBUG //RELEASE BUILD

>>>>>>> restart
}
