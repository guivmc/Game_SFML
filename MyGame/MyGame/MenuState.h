#pragma once
#include "State.h"
#include "Engine.h"

class MenuState : public State
{
private:
	GameDataRef _data;

	std::string texts[2] = { "Menu.", "Press Enter." };
	sf::Text sfText[2];
	sf::Font sfFont;

public:
	MenuState(GameDataRef data);

	void init();

	void draw(float dt);
	void update(float dt);
	void input();
};