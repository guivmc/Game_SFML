#pragma once
#include <SFML/Graphics.hpp>
#include "Engine.h"

class Entity
{
protected:
	sf::Sprite sprite;

	GameDataRef _data;

public:
	Entity() {}
   ~Entity() {}
	Entity(GameDataRef data, int x, int y, const std::string& fileName, const std::string& keyName);
	Entity(GameDataRef data, const std::string& fileName, const std::string& keyName);


	//Getters
	sf::Sprite getSprite();

	//Setters
	void setSpriteRect(sf::IntRect  rect);
	void setSpritePosition(float x, float y);
};