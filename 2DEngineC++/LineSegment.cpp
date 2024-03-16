#include "LineSegment.h"
#include <cmath>
LineSegment::LineSegment(const Point2D* start, const Point2D* endd, sf::Color color){
    this->start = *start;
    this->endd = *endd;
    this->color = color;
}

Point2D LineSegment::getStart(){
    return start;
}

Point2D LineSegment::getEnd(){
    return endd;
}

void LineSegment::setStart(const Point2D* point) {
    this->start = *point;
    return;
}

void LineSegment::setEnd(const Point2D* point) {
    this->endd = *point;
    return;
}

void LineSegment::draw(PrimitiveRenderer* renderer, bool inc) {
    if(inc){
        drawInc(renderer, color);
    }
    else{
        drawDefault(renderer, color);
    }
    return;
}

void LineSegment::drawDefault(PrimitiveRenderer* renderer, sf::Color color) {
    renderer->drawLine(start.getX(), start.getY(), endd.getX(), endd.getY(), color);
    return;
}

void LineSegment::drawInc(PrimitiveRenderer* renderer, sf::Color color) {
    renderer->drawLineInc(start.getX(), start.getY(), endd.getX(), endd.getY(), color);
    return;
}

void LineSegment::draw(sf::RenderWindow* window){
    return;
}

void LineSegment::rotate(float angle){
    float radians = angle * 3.14159265 / 180;
    float startX = start.getX() - endd.getX();
    float startY = start.getY() - endd.getY();

    float rotatedStartX = startX * cos(radians) - startY * sin(radians);
    float rotatedStartY = startX * sin(radians) + startY * cos(radians);

    start.setX(rotatedStartX + endd.getX());
    start.setY(rotatedStartY + endd.getY());
    return;
}

void LineSegment::scale(float x, float y){

    return;
}

void LineSegment::translate(int x, int y){
    start.setX(start.getX() + x);
    start.setY(start.getY() + y);

    endd.setX(endd.getX() + x);
    endd.setY(endd.getY() + y);
    return;
}
LineSegment::~LineSegment(){

}
