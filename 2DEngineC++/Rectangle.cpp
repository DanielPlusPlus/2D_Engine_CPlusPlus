#include "Rectangle.h"

Rectangle::Rectangle(const float x, const float y, const float width, const float height, const sf::Color color){
    this -> x = x;
    this -> y = y;
    this -> width = width;
    this -> height = height;
    this -> color = color;
}

void Rectangle::draw(sf::RenderWindow* window){
    this -> window = window;
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(x, y);
    rectangle.setFillColor(color);
    window->draw(rectangle);
    return;
}

void Rectangle::rotate(float angle){
    sf::Transform transform;
    transform.rotate(angle);
    sf::Vector2f newPosition = transform.transformPoint(x, y);
    x = newPosition.x;
    y = newPosition.y;
    return;
}

void Rectangle::scale(float x, float y){
    width *= x;
    height *= y;
    return;
}

void Rectangle::translate(int x, int y){
    this -> x += x;
    this -> y += y;
    return;
}

Rectangle::~Rectangle() {

}
