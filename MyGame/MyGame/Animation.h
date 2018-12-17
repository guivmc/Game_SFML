#pragma once
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>

class Animation
{
private:
	//TotalTime since last change Image, switchTime = time to wait between frames
	float totalTime, switchTime;
	//ImageCount = image total rows.
	sf::Vector2u imageCount, currentImage;
	sf::IntRect resultRect;
public:
	Animation() {}
   ~Animation() {}

   Animation(sf::Texture &texture, sf::Vector2u imageCount, float switchTime);

   //Play entity animation
   void PlayAnim(int row, float dt);

   //Getters
   //Get current frame. 
   sf::IntRect &getResultRect();
};