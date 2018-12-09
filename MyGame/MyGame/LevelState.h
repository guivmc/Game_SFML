#pragma once
#include "State.h"
#include "Assets.h"
#include "EntityManager.h"

class LevelState : public State
{
protected:
	EntityManager entityManager;
public:

	void draw();

	void input();

	void update(float dt);
};