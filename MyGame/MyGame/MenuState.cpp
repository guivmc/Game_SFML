#include "pch.h"
#include "MenuState.h"
#include "LevelOne.h"

MenuState::MenuState(GameDataRef data) : _data(data)
{

}

void MenuState::init() 
{
		sfFont.loadFromFile("res/fonts/square-deal.ttf");
		sfText[0].setString(texts[0]);
		sfText[0].setPosition((float) (640 / 2 - 100), 100);
		sfText[0].setFont(sfFont);

		sfText[1].setString(texts[1]);
		sfText[1].setPosition((float)(640 / 2 - 100), 150);
		sfText[1].setFont(sfFont);
}

void MenuState::draw(float dt)
{
	this->_data->_window.draw(this->sfText[0]);
	this->_data->_window.draw(this->sfText[1]);
}

void MenuState::update(float dt)
{
}

void MenuState::input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		// Switch To Game State
		this->_data->_stateMachine.addState(StateRef(new LevelOne(_data)), true);
	}
}