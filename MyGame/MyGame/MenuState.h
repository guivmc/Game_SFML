#pragma once
#include "State.h"
#include "Engine.h"
#include "ScreenText.h"

class MenuState : public State
{
private:
	GameDataRef _data;

	ScreenText* menuSelectableItems[4];
public:
	MenuState(GameDataRef data);

	void Init();

	void Draw(float dt);
	void Update(float dt);
	void Input();

	void Layout();
};