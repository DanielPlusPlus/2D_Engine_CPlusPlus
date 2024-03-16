#pragma once
#include "GameObject.h"

class DrawableObject
{
public:
	virtual void draw(sf::RenderWindow* window) = 0;
};

