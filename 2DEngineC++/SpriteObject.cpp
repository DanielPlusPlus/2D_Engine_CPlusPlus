#include "SpriteObject.h"
#include <iostream>
#include <chrono>
#include <thread>

void SpriteObject::changeFrame(int direction)
{
	this->currentFrame = (this->currentFrame + 1) % this->framesNumber;
	sprite.setTextureRect(sf::IntRect(this->currentFrame * this->frameWidth, direction * frameHeight,
		this->frameWidth, this->frameHeight));
}


SpriteObject::SpriteObject(std::string filepath, int frames, int directions, float frameDuration)
	: BitmapObject(filepath)
{
	this->framesNumber = frames;
	this->directionsNumber = directions;
	this->frameDuration = frameDuration;
	this->currentFrame = 0;
	this->frameWidth =texture.getSize().x / frames;
	this->frameHeight = texture.getSize().y / directions;
	changeFrame(0);
}

SpriteObject::SpriteObject(std::vector<std::string> filepaths, float frameDuration) : BitmapObject(filepaths)
{
	this->frameDuration = frameDuration;
	this->currentFrame = 0;
}

void SpriteObject::animate(sf::Clock clock, int direction)
{
	std::chrono::milliseconds timespan(30);
	if (clock.getElapsedTime().asSeconds() > this->frameDuration) {
		changeFrame(direction);
		std::this_thread::sleep_for(timespan);
		clock.restart();
	}
}

void SpriteObject::animateBitmaps(sf::Clock clock, sf::RenderWindow* window)
{
	std::chrono::milliseconds timespan(300);
	if (clock.getElapsedTime().asSeconds() > this->frameDuration) {
		changeBitmap(currentFrame, window);
		//std::this_thread::sleep_for(timespan);
		clock.restart();
	}
}

void SpriteObject::animateBitmaps(sf::Clock clock)
{
	std::chrono::milliseconds timespan(30);
	if (clock.getElapsedTime().asSeconds() > this->frameDuration) {
		changeBitmap(currentFrame);
		//std::this_thread::sleep_for(timespan);
		clock.restart();
	}
}

void SpriteObject::changeBitmap(int index, sf::RenderWindow* window)
{
	setBitmap(index);
	sf::Vector2u windowSize = window->getSize();

	sprite.setScale(
		static_cast<float>(windowSize.x) / static_cast<float>(textures[currentFrame].getSize().x),
		static_cast<float>(windowSize.y) / static_cast<float>(textures[currentFrame].getSize().y)
	);
	this->currentFrame = (this->currentFrame + 1) % this->textures.size();
}

void SpriteObject::changeBitmap(int index)
{
	setBitmap(index);
	this->currentFrame = (this->currentFrame + 1) % this->textures.size();
}

SpriteObject::~SpriteObject()
{
}
