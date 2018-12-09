#include "pch.h"
#include "Animation.h"

Animation::Animation(sf::Texture &texture, sf::Vector2u imageCount, float switchTime)
{
	this->imageCount = imageCount;
	this->switchTime = switchTime;

	totalTime = 0.0f;
	currentImage.x = 0;

	resultRect.width = texture.getSize().x / float(imageCount.x);
	resultRect.height = texture.getSize().y / float(imageCount.y);
}

void Animation::playAnim(int row, float dt)
{
	currentImage.y = row;
	totalTime += dt;

	if (totalTime >= switchTime)
	{
		totalTime -= switchTime;
		currentImage.x++;

		if (currentImage.x >= imageCount.x) currentImage.x = 0;
	}

	resultRect.left = currentImage.x * resultRect.width;
	resultRect.top = currentImage.y * resultRect.height;
}

//Getters
sf::IntRect &Animation::getResultRect()
{
	return resultRect;
}