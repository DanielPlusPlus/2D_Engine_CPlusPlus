#pragma once
#include "PrimitiveRenderer.h"
#include "PrimitiveRenderer2.h"
#include "LineSegment.h"
#include "BitmapHandler.h"
#include "Player.h"
#include "SpriteObject.h"
#include <vector>

class Engine
{
private:

	sf::RenderWindow* window;
	sf::Event event;
	BitmapHandler* bitmapHandler;
	Player* player;
	SpriteObject* spriteObject;
	SpriteObject* test;

	sf::Texture texture;

	void initWindow();
	void initVariables();
	void pollEvent();
	void update();
	void render(sf::Clock clock);

public:
	Engine();
	~Engine();

	void run();
};
