#pragma once
#include "ShapeObject.h"

class Triangle : ShapeObject{
public:
    Triangle(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3, const sf::Color color);
    void draw(sf::RenderWindow* window) override;
    void rotate(float angle) override;
    void scale(float x, float y) override;
    void translate(int x, int y) override;
    ~Triangle();
private:
    sf::RenderWindow* window;
    float x1;
    float y1;
    float x2;
    float y2;
    float x3;
    float y3;
    sf::Color color;
};

