#pragma once
#include "Engine.h"

class ScreenText
{
private:
	GameDataRef _data;

	sf::Text screenText;
	sf::Font textFont;
public:
	ScreenText(GameDataRef data, std::string keyName, std::string text = "");
	~ScreenText() {}

	//Getters
	sf::Text &getScreenText();
};