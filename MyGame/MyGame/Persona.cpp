#include "pch.h"
#include "Persona.h"

Persona::Persona(int x, int y, float hp, sf::Texture &texture) 
{
	this->hp = hp;
	sprite.setTexture(texture);
}

//Methods
bool Persona::isDead()
{
	return (hp < 0);
}
