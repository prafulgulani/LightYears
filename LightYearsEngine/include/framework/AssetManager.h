#pragma once
#include <SFML/Graphics.hpp>

#include "framework/Core.h"

namespace ly
{
	class AssetManager
	{
	public:
		static AssetManager& Get();
		shared<sf::Texture> LoadTexture(const std::string& path);
		shared<sf::Font> LoadFont(const std::string& path);
		void CleanCycle();
		void SetAssetRootDirectory(const std::string& directory);
	protected:
		AssetManager();
	private:
		static unique<AssetManager> assetManager; //because this is statis it means this is a singleton whole application will share this one and only copy
		Dictionary<std::string, shared<sf::Texture>> mLoadedTextureMap;// we need a dictionary to find if we have a texture loaded already, the only way to find that is to use path as a key
		Dictionary<std::string, shared<sf::Font>> mLoadedFontMap;
		std::string mRootDirectory;
	};
}