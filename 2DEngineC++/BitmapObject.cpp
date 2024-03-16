#include "BitmapObject.h"
#include <iostream>

BitmapObject::BitmapObject(std::string filepath)
{
	this->texture.loadFromFile(filepath);
	this->sprite.setTexture(this->texture);
}

BitmapObject::BitmapObject(std::vector<std::string> filepaths)
{
	for (auto& index : filepaths) {
		sf::Texture t;
		if (t.loadFromFile(index)) {
			this->textures.push_back(t);
		}
		else {
			std::cout << "Blad zaladowania pliku\n";
		}
	}
	this->sprite.setTexture(this->textures[0]);
}

void BitmapObject::draw(sf::RenderWindow* window)
{
	window->draw(sprite);
}

void BitmapObject::drawOneBitmap(sf::RenderWindow* window, int bitmapNumber, int bitmaps)
{
	sprite.setTextureRect(sf::IntRect(bitmapNumber * texture.getSize().x / bitmaps, 0, texture.getSize().x / bitmaps,
		texture.getSize().y));
	window->draw(sprite);
}

void BitmapObject::setBitmap(int index)
{
	if (index > this->textures.size()) {
		std::cout << "Blad\n";
	}
	else
		this->sprite.setTexture(this->textures[index]);
}

void BitmapObject::translate(int x, int y)
{
	this->sprite.setPosition(x, y);
}

void BitmapObject::scale(float x, float y)
{
	this->sprite.setScale(x, y);
}

void BitmapObject::rotate(float angle)
{
	return;
}

BitmapObject::~BitmapObject()
{
}
