#pragma once
#include "State.h"
#include "Engine.h"

class MenuState : public State
{
private:
	GameDataRef _data;
public:
	MenuState(GameDataRef data);

	void Init();

	void Draw(float dt);
	void Update(float dt);
	void Input();
};