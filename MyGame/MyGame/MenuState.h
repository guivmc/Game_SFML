#pragma once
#include "State.h"
#include "Engine.h"
#include "ScreenText.h"
#include "UIIcon.h"

class MenuState : public State
{
private:
	GameDataRef _data;

	ScreenText* selectableItems[3];
	ScreenText* mainMenuText;

	UIIcon* uiArrow;

	short itemSelected = 0;
public:
	MenuState(GameDataRef data);

	void Init();

	void Draw(float dt);
	void Update(float dt);
	void Input();

	void Layout();
};