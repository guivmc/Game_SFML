#include "pch.h"
#include "Assets.h"

#pragma region Font

void Assets::LoadFont(const std::string & keyName)
{
	if (this->IsFontLoaded(keyName))
		return;

	sf::Font font;
	if (font.loadFromFile("C:/res/font/" + keyName + ".ttf"))
	{
		this->fontMap[keyName] = font;
	}
}

void Assets::UnloadAllFonts()
{
	this->fontMap.clear();
}

bool Assets::IsFontLoaded(const std::string & keyName)
{
	return (this->fontMap.count(keyName) > 0);
}

sf::Font & Assets::getFont(const std::string & keyName)
{
	sf::Font get;

	try
	{
		get = this->fontMap.at(keyName);

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

	return get;
}

#pragma endregion

#pragma region Texture

void Assets::LoadTexture(const std::string &keyName)
{
	if (this->IsTextureLoaded(keyName))
		return;

	sf::Texture tex;
	if (tex.loadFromFile("C:/res/chars/" + keyName + "/" + keyName + ".png"))
	{
		this->textureMap[keyName] = tex;
	}
}

void Assets::UnloadAllTexture()
{
	this->textureMap.clear();
}

bool Assets::IsTextureLoaded(const std::string &keyName)
{
	return (this->textureMap.count(keyName) > 0);
}

//Getters
sf::Texture &Assets::getTexture(const std::string &keyName)
{
	sf::Texture get;

	try
	{
		get = this->textureMap.at(keyName);

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
	
	return get;
}

#pragma endregion
