#include "pch.h"
#include "Assets.h"
//Methods
void Assets::loadTexture(const std::string &keyName)
{
	sf::Texture tex;
	if (tex.loadFromFile("res/chars/" + keyName + "/" + keyName + ".png"))
	{
		textureMap[keyName] = tex;
	}
}

void Assets::unloadAll()
{
	textureMap.clear();
}

bool Assets::isTextureLoaded(const std::string &keyName)
{
	if (textureMap.count(keyName) > 0) return true;
	else return false;
}

//Getters
sf::Texture &Assets::getTexture(const std::string &keyName)
{
	return textureMap.at(keyName);
}
