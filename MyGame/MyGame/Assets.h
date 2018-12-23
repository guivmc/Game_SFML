#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <iostream>      
#include <stdexcept> 

class Assets
{
private:
	std::unordered_map<std::string, sf::Texture> textureMap;
public:
	Assets(){}
   ~Assets(){}

	#pragma region Texture
   //Load a texture.
   //KeyName is the name used to recover the texture in memory.
	void LoadTexture(const std::string &fileName, const std::string &keyName);
	//Unload all loaded textures.
	void UnloadAllTexture();
	//Return true is the texture is already loaded.
	bool IsTextureLoaded(const std::string &keyName);
	//Get texture from memory.
	sf::Texture &getTexture(const std::string &keyName);
	#pragma endregion
};