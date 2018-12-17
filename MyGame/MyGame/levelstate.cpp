#include "pch.h"
#include "LevelState.h"

//LevelState::LevelState(){}
//
//LevelState::~LevelState() {}



void LevelState::Draw()
{
	entityManager.Draw();
}

void LevelState::Input()
{

}

void LevelState::Update(float dt)
{
	entityManager.Update(dt);
}