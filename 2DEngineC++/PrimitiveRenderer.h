#pragma once
#include "GameObject.h"

class PrimitiveRenderer
{
public:
    PrimitiveRenderer(sf::RenderWindow* window);
    void drawPoint(const float x, const float y, const sf::Color color);
    void drawLine(const float x1, const float y1, const float x2, const float y2, const sf::Color color);
    void drawRectangle(const float x, const float y, const float width, const float height, const sf::Color color);
    void drawCircle(const float x, const float y, const float radius, const sf::Color color);
    void drawTriangle(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3, const sf::Color color);
    void drawCircle4(const float x, const float y, const float radius, const sf::Color color);
    void drawEllipse4(const float x, const float y, const float radiusX, const float radiusY, const sf::Color color);
    void drawConvexShape(const std::vector<sf::Vector2f>& points, const sf::Color& fillColor);
    void drawLineInc(float x1, float y1, float x2, float y2, const sf::Color color);
private:
    sf::RenderWindow* window;
};

