#include "pch.h"
#include "Assets.h"

#pragma region Font

void Assets::LoadFont(const std::string & keyName)
{
	sf::Font font;
	if (font.loadFromFile("res/chars/" + keyName + "/" + keyName + ".png"))
	{
		fontMap[keyName] = font;
	}
	
}

void Assets::UnloadAllFonts()
{
	fontMap.clear();
}

bool Assets::IsFontLoaded(const std::string & keyName)
{
	return (fontMap.count(keyName) > 0);
}

sf::Font & Assets::getFont(const std::string & keyName)
{
	try
	{
		sf::Font get = fontMap.at(keyName);

		return get;
	}
	catch (const std::out_of_range& oor)
	{
		#if _DEBUG
		std::cerr << "Assets.cpp unable to load font -> Out of Range error: " << oor.what() << '\n';
		#else
		// POP UP windows message error
		#endif

	}
}

#pragma endregion

#pragma region Texture

void Assets::LoadTexture(const std::string &keyName)
{
	sf::Texture tex;
	if (tex.loadFromFile("res/chars/" + keyName + "/" + keyName + ".png"))
	{
		textureMap[keyName] = tex;
	}
}

void Assets::UnloadAllTexture()
{
	textureMap.clear();
}

bool Assets::IsTextureLoaded(const std::string &keyName)
{
	return (textureMap.count(keyName) > 0);
}

//Getters
sf::Texture &Assets::getTexture(const std::string &keyName)
{
	try
	{
		sf::Texture get = textureMap.at(keyName);

		return get;
	}
	catch (const std::out_of_range& oor)
	{
		#if _DEBUG
		std::cerr << "Assets.cpp unable to load texture -> Out of Range error: " << oor.what() << '\n';
		#else
		// POP UP windows message error
		#endif

	}
}

#pragma endregion
