#include "pch.h"
#include "Entity.h"

Entity::Entity(int x, int y)
{
	this->x = x;
	this->y = y;
}

//Getters
int Entity::getX()
{
	return x;
}

int Entity::getY()
{
	return y;
}

//Setters
void Entity::setX(int x)
{
	this->x = x;
}

void Entity::setY(int y)
{
	this->y = y;
}