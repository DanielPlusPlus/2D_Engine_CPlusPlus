#pragma once
#include "ShapeObject.h"

class Ellipse4 : ShapeObject{
public:
    Ellipse4(const float x, const float y, const float radiusX, const float radiusY, const sf::Color color);
    void draw(sf::RenderWindow* window) override;
    void rotate(float angle) override;
    void scale(float x, float y) override;
    void translate(int x, int y) override;
    ~Ellipse4();
private:
    sf::RenderWindow* window;
    float x;
    float y;
    float radiusX;
    float radiusY;
    sf::Color color;
};


