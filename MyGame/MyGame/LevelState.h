#pragma once
#include "State.h"
#include "Assets.h"
#include "EntityManager.h"

class LevelState : public State
{
protected:
	EntityManager entityManager;
public:

	void Draw();

	void Input();

	void Update(float dt);
};