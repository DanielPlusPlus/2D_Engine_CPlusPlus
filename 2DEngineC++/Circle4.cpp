#include "Circle4.h"
#include <cmath>
Circle4::Circle4(const float x, const float y, const float radius, const sf::Color color){
    this -> x = x;
    this -> y = y;
    this -> radius = radius;
    this -> color = color;
}

void Circle4::draw(sf::RenderWindow* window){
    sf::VertexArray circle(sf::Points);
    for(int angle = 0; angle <= 90; angle++) {
        float radians = angle * 3.14159265 / 180;
        float cx = radius * cos(radians);
        float cy = radius * sin(radians);
        circle.append(sf::Vertex(sf::Vector2f(x + cx, y + cy), color));
        circle.append(sf::Vertex(sf::Vector2f(x - cx, y + cy), color));
        circle.append(sf::Vertex(sf::Vector2f(x + cx, y - cy), color));
        circle.append(sf::Vertex(sf::Vector2f(x - cx, y - cy), color));
    }
    window->draw(circle);
    return;
}

void Circle4::rotate(float angle){
    sf::Transform transform;
    transform.rotate(angle);
    sf::Vector2f newPosition = transform.transformPoint(x, y);
    x = newPosition.x;
    y = newPosition.y;
    return;
}

void Circle4::scale(float x, float y){
    radius *= std::max(x, y);
    return;
}

void Circle4::translate(int x, int y){
    this -> x += x;
    this -> y += y;
    return;
}

Circle4::~Circle4() {

}
