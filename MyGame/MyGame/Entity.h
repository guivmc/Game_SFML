#pragma once
class Entity
{
protected:
	int x, y;

public:
	Entity();
   ~Entity();
	Entity(int x, int y);

	//Getters
	int getX();
	int getY();

	//Setters
	void setX(int x);
	void setY(int y);
};