#pragma once
#include "State.h"
#include "Engine.h"
#include "Player.h"
#include "EntityManager.h"

class LevelOne : public State
{
private:
	GameDataRef _data;
	Player *p;
	EntityManager entityManager;
public:
	LevelOne(GameDataRef data);

	void Init();

	void Draw(float dt);
	void Update(float dt);
	void Input();
};

