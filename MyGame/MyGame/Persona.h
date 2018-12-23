#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"
#include "Entity.h"

class Persona : public Entity
{
protected:
	//Logic
	float speedX, speedY, hp;
	sf::RectangleShape bounds;

	//Graphics
	int id;
public:
	Persona() {}
   ~Persona() {}
	Persona(int x, int y, float hp, sf::Texture &texture);

	virtual void update(float dt) = 0;

	bool isDead();
};