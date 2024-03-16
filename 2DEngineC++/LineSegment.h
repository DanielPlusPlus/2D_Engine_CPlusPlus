#pragma once
#include "PrimitiveRenderer.h"
#include "Point2D.h"

class LineSegment : ShapeObject{
private:
    Point2D start;
    Point2D endd;
    sf::Color color;
    void drawDefault(PrimitiveRenderer* renderer, sf::Color color);
    void drawInc(PrimitiveRenderer* renderer, sf::Color color);
public:
    LineSegment(const Point2D* start, const Point2D* endd, sf::Color color);

    Point2D getStart();
    Point2D getEnd();

    void setStart(const Point2D* point);
    void setEnd(const Point2D* point);

    void draw(PrimitiveRenderer* renderer, bool inc);

    void draw(sf::RenderWindow* window) override;

    void rotate(float angle) override;
    void scale(float x, float y) override;
    void translate(int x, int y) override;

    ~LineSegment();
};

