#include "BitmapHandler.h"
#include <iostream>

BitmapHandler::BitmapHandler(int width, int height)
{
	this->bitmapWidth = width;
	this->bitmapHeight = height;
	this->bitmap.create(width, height, sf::Color::Transparent);
}

BitmapHandler::BitmapHandler(std::string filepath)
{
	this->loadBitmapFromFile(filepath);
}

BitmapHandler::BitmapHandler(int width, int height, sf::Color color)
{
	this->bitmapWidth = width;
	this->bitmapHeight = height;
	this->bitmap.create(width, height, color);

}

bool BitmapHandler::loadBitmapFromFile(std::string filepath)
{
	if(this->bitmap.loadFromFile(filepath)){
		this->bitmapWidth = bitmap.getSize().x;
		this->bitmapHeight = bitmap.getSize().y;
		return true;
	}
	else {
		std::cout << "B³¹d odczytu z pliku.\n";
		return false;
	}

}

bool BitmapHandler::saveBitmapToFile(std::string filepath)
{


	if (this->bitmap.saveToFile(filepath)) {
		return true;
	}
	else {
		std::cout << "B³¹d zapisu do pliku.\n";
		return false;
	}
}

bool BitmapHandler::copyFromBitmap(BitmapHandler& bitmap2)
{
	if (this->bitmapWidth == bitmap2.bitmapWidth && this->bitmapHeight == bitmap2.bitmapHeight) {
		for (int x = 0; x < this->bitmapWidth; ++x) {
			for (int y = 0; y < this->bitmapHeight; ++y) {
				bitmap.setPixel(x, y, bitmap2.bitmap.getPixel(x, y));
			}
		}
		return true;
	}
	else {
		std::cout << "Nieprawid³owe wymiary bitmapy do skopiowania.\n";
		return false;
	}
}

void BitmapHandler::drawOnBitmap(int x, int y, sf::Color color) //mo¿na dorobiæ jeszcze ¿e argument to primitiverenderer
{
	if (x >= 0 && x < this->bitmapWidth && y >= 0 && y < this->bitmapHeight) {
		bitmap.setPixel(x, y, color);
	}
	else {
		std::cout << "Niew³aœciwe wspó³rzêdne rysowania.\n";
	}
}

void BitmapHandler::displayBitmap(sf::RenderWindow* window)
{
	sf::Texture texture;
	texture.loadFromImage(this->bitmap);
	sf::Sprite sprite(texture);
	window->draw(sprite);
}

void BitmapHandler::drawBrackgroundBitmap(sf::RenderWindow* window)
{
	sf::Texture texture;
	texture.loadFromImage(this->bitmap);
	sf::Sprite sprite(texture);
	sf::Vector2u windowSize = window->getSize();

	sprite.setScale(
		static_cast<float>(windowSize.x) / static_cast<float>(texture.getSize().x),
		static_cast<float>(windowSize.y) / static_cast<float>(texture.getSize().y)
	);
	window->clear();

	window->draw(sprite);
}


BitmapHandler::~BitmapHandler()
{

}


