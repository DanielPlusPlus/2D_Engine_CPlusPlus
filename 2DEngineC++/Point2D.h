#pragma once
#include "PrimitiveRenderer.h"
#include "ShapeObject.h"
class Point2D : ShapeObject{
private:
    float x;
    float y;
    sf::Color color;
public:
    Point2D(float x = 0.0f, float y = 0.0f, const sf::Color color = sf::Color::Black);

    float getX();
    float getY();

    void setX(float x);
    void setY(float y);

    void setPosition(float x, float y);
    void draw(sf::RenderWindow* window) override;

    void draw(PrimitiveRenderer* renderer);

    void rotate(float angle) override;
    void scale(float x, float y) override;
    void translate(int x, int y) override;

    ~Point2D();
};

