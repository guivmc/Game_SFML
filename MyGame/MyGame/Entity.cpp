#include "pch.h"
#include "Entity.h"

Entity::Entity(GameDataRef data, int x, int y, const std::string& fileName, const std::string& keyName) : _data(data)
{
	this->_data->_assets.LoadTexture(fileName, keyName);
}

Entity::Entity(GameDataRef data, const std::string& fileName, const std::string& keyName) : _data(data)
{
	this->_data->_assets.LoadTexture(fileName, keyName);
	this->sprite.setTexture(this->_data->_assets.getTexture(keyName));
}

//Getters
sf::Sprite &Entity::getSprite()
{
	return sprite;
}

//Setters
void Entity::setSpriteRect(sf::IntRect rect)
{
	this->sprite.setTextureRect(rect);
}

void Entity::setSpritePosition(float x, float y)
{
	this->sprite.setPosition(x, y);
}