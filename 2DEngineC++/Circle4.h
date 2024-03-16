#pragma once
#include "ShapeObject.h"

class Circle4 : ShapeObject{
public:
    Circle4(const float x, const float y, const float radius, const sf::Color color);
    void draw(sf::RenderWindow* window) override;
    void rotate(float angle) override;
    void scale(float x, float y) override;
    void translate(int x, int y) override;
    ~Circle4();
private:
    sf::RenderWindow* window;
    float x;
    float y;
    float radius;
    sf::Color color;
};

