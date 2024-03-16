#pragma once
#include "TransformableObject.h"
#include "DrawableObject.h"
#include "GameObject.h"
#include <vector>

class BitmapObject : public DrawableObject, public TransformableObject
{
protected:
	sf::Sprite sprite;
	sf::Texture texture;
	std::vector<sf::Texture> textures;

public:
	BitmapObject(std::string filepath);
	BitmapObject(std::vector<std::string> filepaths);
	void draw(sf::RenderWindow* window) override;
	void drawOneBitmap(sf::RenderWindow* window, int bitmapNumber, int bitmaps);
	void setBitmap(int index);
	void translate(int x, int y) override;
	void scale(float x, float y) override;
	void rotate(float angle) override;
	~BitmapObject();
};

