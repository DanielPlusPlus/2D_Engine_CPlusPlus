#include "Triangle.h"

Triangle::Triangle(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3, const sf::Color color){
    this -> x1 = x1;
    this -> y1 = y1;
    this -> x2 = x2;
    this -> y2 = y2;
    this -> x3 = x3;
    this -> y3 = y3;
    this -> color = color;
}

void Triangle::draw(sf::RenderWindow* window){
    this -> window = window;
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(x1, y1));
    triangle.setPoint(1, sf::Vector2f(x2, y2));
    triangle.setPoint(2, sf::Vector2f(x3, y3));
    triangle.setFillColor(color);
    window->draw(triangle);
}

void Triangle::rotate(float angle){
    sf::Transform transform;
    transform.rotate(angle, x1, y1);
    sf::Vector2f newPosition1 = transform.transformPoint(x1, y1);
    sf::Vector2f newPosition2 = transform.transformPoint(x2, y2);
    sf::Vector2f newPosition3 = transform.transformPoint(x3, y3);
    x1 = newPosition1.x;
    y1 = newPosition1.y;
    x2 = newPosition2.x;
    y2 = newPosition2.y;
    x3 = newPosition3.x;
    y3 = newPosition3.y;
}

void Triangle::scale(float x, float y){
    x2 = x1 + (x2 - x1) * x;
    y2 = y1 + (y2 - y1) * y;
    x3 = x1 + (x3 - x1) * x;
    y3 = y1 + (y3 - y1) * y;
    return;
}

void Triangle::translate(int x, int y){
    x1 += x;
    y1 += y;
    x2 += x;
    y2 += y;
    x3 += x;
    y3 += y;
    return;
}

Triangle::~Triangle() {

}
