#pragma once
#include "ShapeObject.h"

class Circle : ShapeObject{
public:
    Circle(const float x, const float y, const float radius, const sf::Color color);
    void draw(sf::RenderWindow* window) override;
    void rotate(float angle) override;
    void scale(float x, float y) override;
    void translate(int x, int y) override;
    ~Circle();
private:
    sf::RenderWindow* window;
    float x;
    float y;
    float radius;
    sf::Color color;
};

