#include "pch.h"
#include "EntityManager.h"

EntityManager::EntityManager(GameDataRef data) : _data(data)
{
}

void EntityManager::addEntity(int x, int y, float hp, const std::string &keyName)
{
	if (!_data->_assets.isTextureLoaded(keyName))
	{
		_data->_assets.loadTexture(keyName);
	}

	Persona *per = new Slime(x, y, hp, _data->_assets.getTexture(keyName));

	entities.push_back(per);
}

void EntityManager::clearAll()
{
	for (int i = 0; i < entities.size(); i++)
	{		
		delete entities.at(i);
	}
	entities.clear();
}

void EntityManager::draw()
{
	for (int i = 0; i < entities.size(); i++)
	{
		_data->_window.draw(entities.at(i)->getSprite());
	}
}

void EntityManager::update(float dt)
{
	for (int i = 0; i < entities.size(); i++)
	{
		if (entities.at(i)->isDead())
		{
			delete entities.at(i);
			entities.erase(entities.begin() + i);
		}
		else
		{
			entities.at(i)->update(dt);
		}
	}
}

