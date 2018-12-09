#include "pch.h"
#include "Slime.h"

Slime::Slime(int x, int y, float hp, sf::Texture &texture)
							  : Persona(x, y, hp, texture),
							    anim(texture, sf::Vector2u(3, 1), 0.1f)
{

}

void Slime::update(float dt)
{
	anim.playAnim(0, dt);
	this->getSprite().setTextureRect(anim.getResultRect());
	sprite.setPosition(x, y);
}