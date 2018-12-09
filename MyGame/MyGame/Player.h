#pragma once
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>
#include "Animation.h"


class Player
{
private:
	//Logic
	float speedX, speedY, hp;
	sf::RectangleShape bounds;
	//Graphics
	int x, y;
	sf::Sprite sprite;
	//Animation anims[2] = {Animation(idle_, 0.03f, 5), Animation(walk_, 0.07f, 16) };
	int currentAnim;
public:
	Player() {}
   ~Player() {}
	Player(int x, int y, float hp);

	//Logic
	void update();
	void input();
	void moveX(float speedX);
	void moveY(float speedY);
	bool isDead();

	//Getters
	sf::FloatRect getBounds();
	sf::Sprite &getSprite();
	float getHP();
	

	//setters
	void setHP(float hp);
	void setSprite(sf::Texture &texture);
};
