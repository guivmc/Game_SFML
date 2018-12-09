#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class Persona
{
protected:
	//Logic
	float speedX, speedY, hp;
	sf::RectangleShape bounds;

	//Graphics
	int x, y;
	int id;
	sf::Sprite sprite;
public:
	Persona() {}
   ~Persona() {}
	Persona(int x, int y, float hp, sf::Texture &texture);

	virtual void update(float dt) = 0;

	bool isDead();

	sf::Sprite &getSprite();
};