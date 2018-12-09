#pragma once
#include "Persona.h"

class Slime : public Persona
{
private:
	Animation anim;
public:
	Slime(int x, int y, float hp, sf::Texture &texture);
   ~Slime(){}
  
	void update(float dt);
};