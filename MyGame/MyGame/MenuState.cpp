#include "pch.h"
#include "MenuState.h"
#include "LevelOne.h"

MenuState::MenuState(GameDataRef data) : _data(data)
{
}

void MenuState::Init()
{
	this->_data->_assets.LoadFont("square-deal");

}

void MenuState::Draw(float dt)
{
	
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