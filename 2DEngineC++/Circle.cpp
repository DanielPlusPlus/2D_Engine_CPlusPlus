#include "Circle.h"

Circle::Circle(const float x, const float y, const float radius, const sf::Color color){
    this -> x = x;
    this -> y = y;
    this -> radius = radius;
    this -> color = color;
}

void Circle::draw(sf::RenderWindow* window){
    this -> window = window;
    sf::CircleShape circle(radius);
    circle.setPosition(x - radius, y - radius);
    circle.setFillColor(color);
    window->draw(circle);
    return;
}

void Circle::rotate(float angle){
    sf::Transform transform;
    transform.rotate(angle);
    sf::Vector2f newPosition = transform.transformPoint(x, y);
    x = newPosition.x;
    y = newPosition.y;
    return;
}

void Circle::scale(float x, float y){
    radius *= std::max(x, y);
    return;
}

void Circle::translate(int x, int y){
    this -> x += x;
    this -> y += y;
    return;
}

Circle::~Circle() {

}
