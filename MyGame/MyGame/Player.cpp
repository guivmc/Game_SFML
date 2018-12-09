#include "pch.h"
#include "Player.h"

Player::Player(int x, int y, float hp) 
{
	this->x = x;
	this->y = y;
	this->hp = hp;
	speedX = 3.0f;
	bounds.setSize(sf::Vector2f(20, 20));
	sprite.setOrigin(24, 15);
	currentAnim = 0;
	sprite.setTextureRect(sf::IntRect(0, 18, 48, 31));
}

//Methods
//Logic
void Player::update()
{
	//input();
	//anims[currentAnim].updateLoopAnim();
	sprite.setPosition(x, y);
	//sprite.setTextureRect(anims[currentAnim].getCurrentFrame());
}

void Player::input()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		moveX(speedX);
		sprite.setScale(1, 1);
		currentAnim = 1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		moveX(-speedX);
		sprite.setScale(-1, 1);
		currentAnim = 1;
	}
	if (sf::Keyboard::isKeyPressed == false) currentAnim = 0;
}

void Player::moveX(float speedX)
{
	x += speedX;
}

void Player::moveY(float speedY)
{

}

bool Player::isDead()
{
	return (hp < 0);
}

//Graphics

//Getters
sf::FloatRect Player::getBounds()
{
	return bounds.getGlobalBounds();
}

float Player::getHP()
{
	return hp;
}

sf::Sprite &Player::getSprite()
{
	return sprite;
}

//Setters
void Player::setHP(float hp)
{
	this->hp = hp;
}

void Player::setSprite(sf::Texture &texture)
{
	sprite.setTexture(texture);
}