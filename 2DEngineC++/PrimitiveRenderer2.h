#pragma once
#include "GameObject.h"
#include "Point2D.h"

class PrimitiveRenderer2
{
public:
    PrimitiveRenderer2(sf::RenderWindow* window);
    void drawLineOpen(std::vector<Point2D>& points, const sf::Color color);
    void drawLineClosed(std::vector<Point2D>& points, const sf::Color color);
    void drawConvexShapeFill(std::vector<Point2D>& points, const sf::Color& fillColor);
    void drawConvexShape(std::vector<Point2D>& points, const sf::Color& color);
    void floodFill(Point2D& seed, const sf::Color targetColor, const sf::Color fillColor);
    void floodFillRecursive(sf::Image& image, const sf::Vector2u& pixel, const sf::Color& targetColor, const sf::Color& fillColor);
    void borderFill(Point2D& seed, const sf::Color targetColor, const sf::Color fillColor);
    void borderFillRecursive(sf::Image& image, const sf::Vector2u& pixel, const sf::Color& targetColor, const sf::Color& fillColor);
private:
    sf::RenderWindow* window;
};

