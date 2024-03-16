#pragma once
#include "ShapeObject.h"

class Rectangle : ShapeObject{
public:
    Rectangle(const float x, const float y, const float width, const float height, const sf::Color color);
    void draw(sf::RenderWindow* window) override;
    void rotate(float angle) override;
    void scale(float x, float y) override;
    void translate(int x, int y) override;
    ~Rectangle();
private:
    sf::RenderWindow* window;
    float x;
    float y;
    float width;
    float height;
    sf::Color color;
};
