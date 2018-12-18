#include "pch.h"
#include "MenuState.h"
#include "LevelOne.h"

MenuState::MenuState(GameDataRef data) : _data(data)
{
}

void MenuState::Init() 
{
		this->_data->_assets.LoadFont("square-deal");

		sfText[0].setString(texts[0]);
		sfText[0].setPosition((float) (640 / 2 - 100), 100);
		sfText[0].setFont(this->_data->_assets.getFont("square-deal"));

		sfText[1].setString(texts[1]);
		sfText[1].setPosition((float)(640 / 2 - 100), 150);
		sfText[1].setFont(this->_data->_assets.getFont("square-deal"));
}

void MenuState::Draw(float dt)
{
	this->_data->_window.draw(this->sfText[0]);
	this->_data->_window.draw(this->sfText[1]);
}

void MenuState::Update(float dt)
{
}

void MenuState::Input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		// Switch To Game State
		this->_data->_stateMachine.AddState(StateRef(new LevelOne(_data)), true);
	}
}