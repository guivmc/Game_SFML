#include "pch.h"
#include "Engine.h"
#include "MenuState.h"
#include <iostream>

Engine::Engine(int screenWidth, int screenHeight, std::string title) 
{
	this->screenWidth = screenWidth;
	this->screenHeight = screenHeight;							//Window with title and close buttons
	this->_data->_window.create(sf::VideoMode(screenWidth, screenHeight), title,
						  sf::Style::Titlebar + sf::Style::Close);
}

//Methods
void Engine::CreateMenu()
{
	this->_data->_stateMachine.AddState(StateRef(new MenuState(this->_data)), false);
}

void Engine::drawEngine(float dt)
{
	this->_data->_window.clear(sf::Color::Black);

	this->_data->_stateMachine.getActiveState()->Draw(dt);

	this->_data->_window.display();
}

void Engine::handleInputEngine()
{
	sf::Event event;

	while (this->_data->_window.pollEvent(event))
	{
		if (sf::Event::Closed == event.type)
		{
			this->_data->_window.close();
		}

		this->_data->_stateMachine.getActiveState()->Input();
	}
}

void Engine::Run()
{
	float newTime, frameTime, interpolation, accumulator = 0, 
		  currentTime = _clock.getElapsedTime().asSeconds();
																			
	CreateMenu();

	while (this->_data->_window.isOpen())
	{
		this->_data->_stateMachine.ProcessStateChanges();
		
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
			this->_data->_stateMachine.getActiveState()->Update(dt);
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