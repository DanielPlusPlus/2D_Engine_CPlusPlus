#include "Ellipse4.h"
#include <cmath>

Ellipse4::Ellipse4(const float x, const float y, const float radiusX, const float radiusY, const sf::Color color){
    this -> x = x;
    this -> y = y;
    this -> radiusX = radiusX;
    this -> radiusY = radiusY;
    this -> color = color;
}

void Ellipse4::draw(sf::RenderWindow* window){
    sf::VertexArray ellipse(sf::Points);
    for(int angle = 0; angle <= 90; angle++) {
        float radians = angle * 3.14159265 / 180;
        float ex = radiusX * cos(radians);
        float ey = radiusY * sin(radians);
        ellipse.append(sf::Vertex(sf::Vector2f(x + ex, y + ey), color));
        ellipse.append(sf::Vertex(sf::Vector2f(x - ex, y + ey), color));
        ellipse.append(sf::Vertex(sf::Vector2f(x + ex, y - ey), color));
        ellipse.append(sf::Vertex(sf::Vector2f(x - ex, y - ey), color));
    }
    window->draw(ellipse);
    return;
}

void Ellipse4::rotate(float angle){
    sf::Transform transform;
    transform.rotate(angle);
    for (int i = 0; i < 4; i++) {
        float ex = radiusX * cos(i * 90 * 3.14159265 / 180);
        float ey = radiusY * sin(i * 90 * 3.14159265 / 180);
        sf::Vector2f newPosition = transform.transformPoint(x + ex, y + ey);
        x = newPosition.x;
        y = newPosition.y;
    }
}

void Ellipse4::scale(float x, float y){
    radiusX *= x;
    radiusY *= y;
}

void Ellipse4::translate(int x, int y){
    this -> x += x;
    this -> y += y;
    return;
}

Ellipse4::~Ellipse4() {

}
