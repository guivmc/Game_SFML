#pragma once
#include "State.h"
#include "Engine.h"

class MenuState : public State
{
private:
	GameDataRef _data;

	std::string texts[2] = { "Menu.", "Press Enter." };
	sf::Text sfText[2];

public:
	MenuState(GameDataRef data);

	void Init();

	void Draw(float dt);
	void Update(float dt);
	void Input();
};