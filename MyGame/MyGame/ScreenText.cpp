#include "pch.h"
#include "ScreenText.h"

ScreenText::ScreenText(GameDataRef data, std::string keyName, std::string text) : _data(data)
{
	this->setFont(keyName);

	this->screenText.setString(text);
	this->screenText.setFillColor(sf::Color::White);
	/*this->screenText.setPosition((this->_data->_window.getSize().x / 2 - this->screenText.getLocalBounds().width / 2 ), this->_data->_window.getSize().y / 5);
*/
}

#pragma region Getters

sf::Text &ScreenText::getScreenText()
{
	return this->screenText;
}

sf::FloatRect ScreenText::getScreenTextSize()
{
	return this->screenText.getGlobalBounds();
}

#pragma endregion

#pragma region Setters

void ScreenText::setPosition(float x, float y)
{
	this->screenText.setPosition(x, y);
}

void ScreenText::setText(std::string text)
{
	this->screenText.setString(text);
}

void ScreenText::setFont(std::string keyName)
{
	if (!this->textFont.loadFromFile("C:/res/font/" + keyName + ".ttf"))
	{
		//POP ERROR
	}

	this->screenText.setFont(textFont);
}

void ScreenText::setColor(sf::Color color)
{
	this->screenText.setFillColor(color);
}

#pragma endregion