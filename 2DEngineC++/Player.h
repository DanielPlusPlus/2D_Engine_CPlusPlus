#pragma once
#include "SpriteObject.h"

class Player : public SpriteObject
{
	int frames;
	int directions;
	int currentDirection;
	bool idle;
	sf::IntRect spriteRect;
	int speedx = 0;
	int speedy = 0;
	int frameHeight;

public:
	Player(std::string filepath, int frames, int directions);
	void handleInput(sf::RenderWindow* window, sf::Event event);
	void updateAnimation(sf::Clock clock);
	void changeDirection(sf::Event event);
	~Player();
};

