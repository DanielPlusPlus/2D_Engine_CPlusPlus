#include "Point2D.h"
Point2D::Point2D(float x, float y, const sf::Color color){
    this->x = x;
    this->y = y;
    this->color = color;
}
float Point2D::getX(){
    return x;
}

float Point2D::getY(){
    return y;
}

void Point2D::setX(float x){
    this->x = x;
    return;
}

void Point2D::setY(float y){
    this->y = y;
    return;
}

void Point2D::setPosition(float x, float y){
    this->x = x;
    this->y = y;
    return;
}

void Point2D::draw(PrimitiveRenderer* renderer){
    renderer->drawPoint(x, y, color);
    return;
}

void Point2D::draw(sf::RenderWindow* window){
    return;
}

void Point2D::rotate(float angle){

    return;
}

void Point2D::scale(float x, float y){

    return;
}

void Point2D::translate(int x, int y){
    this -> x += x;
    this -> y += y;
    return;
}
Point2D::~Point2D(){

}
