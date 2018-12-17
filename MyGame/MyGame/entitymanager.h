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
    //Create and add an entity
	void AddEntity(int x, int y, float hp, const std::string &keyName);
	//Remove all entities from memory.
	void ClearAll();
	//Update all entities.
	void Update(float dt);
	//Draw all entities.
	void Draw();
};