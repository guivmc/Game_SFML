#include "pch.h"
#include "MenuState.h"
#include "LevelOne.h"

MenuState::MenuState(GameDataRef data) : _data(data)
{

}

void MenuState::Init()
{
	this->mainMenuText = new ScreenText(this->_data, "square-deal");

	this->uiArrow = new UIIcon(this->_data, "UI/UI_Arrows", "UI_Arrows");
	
	this->uiArrow->setSpriteRect(sf::IntRect(0, 0, 16, 16));

	this->uiArrow->setSpritePosition(50.0f, 50.0f);

	for (size_t i = 0; i < std::size(selectableItems); i++)
	{
		this->selectableItems[i] = new ScreenText(this->_data, "square-deal");
	}

	this->Layout();
}

void MenuState::Layout()
{
	//Text
	//Define texts first as it can change its global bounds.
	this->mainMenuText->setText("Main Menu");

	this->selectableItems[0]->setText("Play");
	this->selectableItems[1]->setText("Options");
	this->selectableItems[2]->setText("Exit");

	//Position
	float centerX = static_cast<float>(this->_data->_window.getSize().x / 2);
	
	//CenterX mainMenuText and put it above the half of the screen.
	this->mainMenuText->setPosition((centerX - static_cast<float>(this->mainMenuText->getScreenTextSize().width / 2)), static_cast<float>(this->_data->_window.getSize().y / 5));
	
	for (size_t i = 0; i < std::size(selectableItems); i++)
	{
		this->selectableItems[i]->setPosition((centerX - static_cast<float>(this->mainMenuText->getScreenTextSize().width / 2)), static_cast<float>((this->_data->_window.getSize().y / 3) + (40 * i)));
	}
}

void MenuState::Draw(float dt)
{
	_data->_window.draw(this->mainMenuText->getScreenText());

	_data->_window.draw(this->uiArrow->getSprite());

	for (size_t i = 0; i < std::size(selectableItems); i++)
	{
		_data->_window.draw(this->selectableItems[i]->getScreenText());
	}
}

void MenuState::Update(float dt)
{
	for (size_t i = 0; i < std::size(selectableItems); i++)
	{
		if(i == itemSelected)
			this->selectableItems[itemSelected]->setColor(sf::Color::Yellow);
		else
			this->selectableItems[i]->setColor(sf::Color::White);
	}
}

void MenuState::Input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
	{
		switch (itemSelected)
		{
		case 0:
			// Switch To Game State
			//this->_data->_stateMachine.AddState(StateRef(new LevelOne(_data)), true);
			break;
		case 1:
			std::cout << "Case 1";
			break;
		case 2:
			std::exit(EXIT_SUCCESS);
			break;
		default:
			break;
		}	
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if(itemSelected < 2)
			itemSelected++;

		this->selectableItems[itemSelected]->setColor(sf::Color::Yellow);
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (itemSelected > 0)
			itemSelected--;

		
	}
}