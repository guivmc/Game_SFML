#include "pch.h"
#include "MenuState.h"
#include "LevelOne.h"

MenuState::MenuState(GameDataRef data) : _data(data)
{

}

void MenuState::Init()
{
	this->text[0] = new ScreenText(this->_data, "square-deal", "Main Menu");
}

void MenuState::Draw(float dt)
{
	_data->_window.draw(this->text[0]->getScreenText());
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