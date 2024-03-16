#pragma once
#include "GameObject.h"

class AnimatedObject
{

public:
	virtual ~AnimatedObject() = default;
	virtual void animate(sf::Clock clock, int direction) = 0;

};

