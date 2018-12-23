#include "pch.h"
#include "EntityManager.h"

EntityManager::EntityManager(GameDataRef data) : _data(data)
{
}

void EntityManager::AddEntity(int x, int y, float hp, const std::string &keyName)
{
	/*if (!_data->_assets.IsTextureLoaded(keyName))
	{
		_data->_assets.LoadTexture(keyName);
	}

	Persona *per = new Slime(x, y, hp, _data->_assets.getTexture(keyName));

	entities.push_back(per);*/
}

void EntityManager::ClearAll()
{
	for (size_t i = 0; i < entities.size(); i++)
	{		
		delete entities.at(i);
	}
	entities.clear();
}

void EntityManager::Draw()
{
	for (size_t i = 0; i < entities.size(); i++)
	{
		_data->_window.draw(entities.at(i)->getSprite());
	}
}

void EntityManager::Update(float dt)
{
	for (size_t i = 0; i < entities.size(); i++)
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

