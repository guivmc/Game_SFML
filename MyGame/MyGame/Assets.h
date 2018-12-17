#pragma once
#include <SFML/Graphics.hpp>
#include <unordered_map>
#include <iostream>      
#include <stdexcept> 

using namespace sf;

class Assets
{
private:
	std::unordered_map<std::string, sf::Texture> textureMap;
	std::unordered_map<std::string, sf::Font> fontMap;
public:
	Assets(){}
   ~Assets(){}

   #pragma region Font
   //Load a Font.
   //KeyName is the name used to recover the font in memory.
   void LoadFont(const std::string &keyName);
   //Unload all loaded fonts.
   void UnloadAllFonts();
   //Return true is the font is already loaded.
   bool IsFontLoaded(const std::string & keyName);
   //Get font from memory.
   sf::Font &getFont(const std::string &keyName);
   #pragma endregion

	#pragma region Texture
   //Load a texture.
   //KeyName is the name used to recover the texture in memory.
	void LoadTexture(const std::string &keyName);
	//Unload all loaded textures.
	void UnloadAllTexture();
	//Return true is the texture is already loaded.
	bool IsTextureLoaded(const std::string &keyName);
	//Get texture from memory.
	sf::Texture &getTexture(const std::string &keyName);
	#pragma endregion
};