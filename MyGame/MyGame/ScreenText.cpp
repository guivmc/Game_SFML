#include "pch.h"
#include "ScreenText.h"

ScreenText::ScreenText(GameDataRef data, std::string keyName, std::string text) : _data(data)
{

	if (!this->textFont.loadFromFile("C:/res/font/" + keyName + ".ttf"))
	{
		//POP ERROR
	}

	this->screenText.setString(text);
	this->screenText.setFont(textFont);
	this->screenText.setFillColor(sf::Color::White);
	this->screenText.setPosition((this->_data->_window.getSize().x / 2 - this->screenText.getLocalBounds().width / 2 ), this->_data->_window.getSize().y / 5);

}

sf::Text &ScreenText::getScreenText()
{
	return this->screenText;
}