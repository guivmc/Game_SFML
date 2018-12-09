#include "pch.h"
#include "LevelOne.h"

LevelOne::LevelOne(GameDataRef data) : _data(data), entityManager(data)
{

}

void LevelOne::init()
{
	p = new Player(50, 50, 100);
	_data->_assets.loadTexture("Slime");
	p->setSprite(_data->_assets.getTexture("Slime"));
	entityManager.addEntity(80, 80, 100, "Slime");
}

void LevelOne::draw(float dt)
{
	entityManager.draw();
	//_data->_window.draw(p->getSprite());
}

void LevelOne::update(float dt)
{
	//p->update();
	entityManager.update(dt);
}

void LevelOne::input()
{

}