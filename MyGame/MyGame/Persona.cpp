#include "pch.h"
#include "Persona.h"

Persona::Persona(int x, int y, float hp, sf::Texture &texture) 
{
	this->x = x;
	this->y = y;
	this->hp = hp;
	sprite.setTexture(texture);
}

//Methods
bool Persona::isDead()
{
	return (hp < 0);
}

//Getters
sf::Sprite &Persona::getSprite()
{
	return sprite;
}
