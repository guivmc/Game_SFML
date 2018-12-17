#include "pch.h"
#include "LevelOne.h"

LevelOne::LevelOne(GameDataRef data) : _data(data), entityManager(data)
{

}

void LevelOne::Init()
{
	p = new Player(50, 50, 100);
	_data->_assets.LoadTexture("Slime");
	p->setSprite(_data->_assets.getTexture("Slime"));
	entityManager.AddEntity(80, 80, 100, "Slime");
}

void LevelOne::Draw(float dt)
{
	entityManager.Draw();
	//_data->_window.draw(p->getSprite());
}

void LevelOne::Update(float dt)
{
	//p->update();
	entityManager.Update(dt);
}

void LevelOne::Input()
{

}