#include "pch.h"
#include "Engine.h"
#include "MenuState.h"
#include <iostream>

Engine::Engine(int screenWidth, int screenHeight, std::string title) 
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;							//Window with title and close buttons
	_data->_window.create(sf::VideoMode(screenWidth, screenHeight), title, 
						  sf::Style::Titlebar + sf::Style::Close);
}

//Methods
void Engine::createMenu()
{
	_data->_stateMachine.addState(StateRef(new MenuState(this->_data)), false);
}

void Engine::drawEngine(float dt)
{
	_data->_window.clear(sf::Color::White);

	_data->_stateMachine.getActiveState()->draw(dt);

	_data->_window.display();
}

void Engine::handleInputEngine()
{
	sf::Event event;

	while (_data->_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			_data->_window.close();
		}

		_data->_stateMachine.getActiveState()->input();
	}
}

void Engine::run()
{
	float newTime, frameTime, interpolation, accumulator = 0, 
		  currentTime = _clock.getElapsedTime().asSeconds();
																			
	createMenu();

	while (_data->_window.isOpen())
	{
		_data->_stateMachine.processStateChanges();
		
		newTime = _clock.getElapsedTime().asSeconds();
		//Frame diference 
		frameTime = newTime - currentTime;
		if (frameTime > 0.25f) frameTime = 0.25f;
		currentTime = newTime;
		accumulator += frameTime;
		//update with frame
		while (accumulator >= dt)
		{
			handleInputEngine();
			_data->_stateMachine.getActiveState()->update(dt);
			accumulator -= dt;
		}
		interpolation = accumulator / dt;
		drawEngine(interpolation);

		//std::cout << accumulator << std::endl;
	}
}

//Getters
int Engine::getScreenWidth()
{
	return screenWidth;
}

int Engine::getScreenHeight()
{
	return screenHeight;
}

//Setters
void Engine::setScreenWidth(int screenWidth)
{
	this->screenWidth = screenWidth;
}

void Engine::setScreenHeight(int screenHeight)
{
	this->screenHeight = screenHeight;
}