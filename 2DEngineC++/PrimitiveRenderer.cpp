#include "PrimitiveRenderer.h"
#include "Point2D.h"
#include <math.h>

PrimitiveRenderer::PrimitiveRenderer(sf::RenderWindow* window){
    this->window = window;
}

void PrimitiveRenderer::drawPoint(const float x, const float y, const sf::Color color){
    sf::Vertex point(sf::Vector2f(x, y), color);
    window->draw(&point, 1, sf::Points);
    return;
}

void PrimitiveRenderer::drawLine(const float x1, const float y1, const float x2, const float y2, const sf::Color color){
    sf::Vertex line[] = {
        sf::Vertex(sf::Vector2f(x1, y1), color),
        sf::Vertex(sf::Vector2f(x2, y2), color)
    };
    window->draw(line, 2, sf::Lines);
    return;
}

void PrimitiveRenderer::drawRectangle(const float x, const float y, const float width, const float height, const sf::Color color){
    sf::RectangleShape rectangle(sf::Vector2f(width, height));
    rectangle.setPosition(x, y);
    rectangle.setFillColor(color);
    window->draw(rectangle);
    return;
}

void PrimitiveRenderer::drawCircle(const float x, const float y, const float radius, const sf::Color color){
    sf::CircleShape circle(radius);
    circle.setPosition(x - radius, y - radius);
    circle.setFillColor(color);
    window->draw(circle);
    return;
}

void PrimitiveRenderer::drawTriangle(const float x1, const float y1, const float x2, const float y2, const float x3, const float y3, const sf::Color color){
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, sf::Vector2f(x1, y1));
    triangle.setPoint(1, sf::Vector2f(x2, y2));
    triangle.setPoint(2, sf::Vector2f(x3, y3));
    triangle.setFillColor(color);
    window->draw(triangle);
    return;
}

void PrimitiveRenderer::drawCircle4(const float x, const float y, const float radius, const sf::Color color) {
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

void PrimitiveRenderer::drawEllipse4(const float x, const float y, const float radiusX, const float radiusY, const sf::Color color) {
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

void PrimitiveRenderer::drawConvexShape(const std::vector<sf::Vector2f>& points, const sf::Color& fillColor) {
    sf::ConvexShape convex;
    int n = points.size();
    convex.setPointCount(n);
    for(int i = 0; i < n; i++) {
        convex.setPoint(i, sf::Vector2f(points[i].x, points[i].y));
    }
    convex.setFillColor(fillColor);
    window->draw(convex);
    return;
}


void PrimitiveRenderer::drawLineInc(float x1, float y1, float x2, float y2, const sf::Color color){
    int x, y;
    float dy, dx, m;
    dy = y2 - y1;
    dx = x2 - x1;
    if(dx == 0) {
        if (y1 > y2){
            float tmp = y1;
            y1 = y2;
            y2 = tmp;
        }
        for (y = y1; y <= y2; y++) {
             drawPoint(x1, y, color);
        }
    }else {
        m = dy / dx;
        y = int(y1 + 0.5);
        for (x = x1; x <= x2; x++) {
            drawPoint(x, y, color);
            y += m;
        }
    }
    return;
}
