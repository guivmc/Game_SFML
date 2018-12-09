#include "pch.h"
#include "LevelState.h"

//LevelState::LevelState(){}
//
//LevelState::~LevelState() {}


void LevelState::draw()
{
	entityManager.draw();
}

void LevelState::input()
{

}

void LevelState::update(float dt)
{
	entityManager.update(dt);
}