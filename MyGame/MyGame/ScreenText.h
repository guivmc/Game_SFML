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
	sf::FloatRect getScreenTextSize();

	//Setters
	void setPosition(float x, float y);
	void setText(std::string text);
	void setFont(std::string keyName);
	void setColor(sf::Color color);
};