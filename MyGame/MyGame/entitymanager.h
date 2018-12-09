#pragma once
#include "Engine.h"
#include "Persona.h"
#include "Slime.h"
#include <vector>

class EntityManager
{
private:
	GameDataRef _data;
	std::vector<Persona*> entities;
public:
	EntityManager(GameDataRef data);
   ~EntityManager(){}

    //void addEntity(Persona e);
	void addEntity(int x, int y, float hp, const std::string &keyName);
	void clearAll();
	void update(float dt);
	void draw();
};