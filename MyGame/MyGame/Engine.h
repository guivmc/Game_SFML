#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "StateHandler.h"
#include "Assets.h"

using namespace sf;
//"Global" acess to these datas.
struct GameData
{
	sf::RenderWindow _window;
	StateHandler _stateMachine;
	Assets _assets;
};

//Pointer that is manage by a group of the same pointer type, with the same data.
//Can share data across others shared pointers of the same type.
typedef std::shared_ptr<GameData> GameDataRef;

class Engine
{
private:
	//window
	int screenWidth, screenHeight;
	//Logic
	GameDataRef _data = std::make_shared<GameData>();
	const float dt = 1.0f / 60.0f;
	sf::Clock _clock;

	//Draw what is in the current state.
	void drawEngine(float dt);
	//
	void handleInputEngine();

public:
	Engine() {}
   ~Engine() {}
	Engine(int screenWidth, int screenHeight, std::string title);

	//Run engine.
	void Run();
	//Push menu state.
	void CreateMenu();

	//Getters
	int getScreenWidth();
	int getScreenHeight();

	//setters
	void setScreenWidth(int screenWidth);
	void setScreenHeight(int screenHeight);
};
