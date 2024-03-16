#pragma once
#include "GameObject.h"

class BitmapHandler
{
	sf::Image bitmap;
	int bitmapWidth;
	int bitmapHeight;

public:

	BitmapHandler(int width, int height);
	BitmapHandler(std::string filepath);
	BitmapHandler(int width, int height, sf::Color color);

	bool loadBitmapFromFile(std::string filepath);
	bool saveBitmapToFile(std::string filepath);
	bool copyFromBitmap(BitmapHandler& bitmap2);
	void drawOnBitmap(int x, int y, sf::Color color);
	void displayBitmap(sf::RenderWindow* window);
	void drawBrackgroundBitmap(sf::RenderWindow* window);

	~BitmapHandler();
};

