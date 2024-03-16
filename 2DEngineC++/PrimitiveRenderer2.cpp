#include "PrimitiveRenderer2.h"

PrimitiveRenderer2::PrimitiveRenderer2(sf::RenderWindow* window){
    this->window = window;
}

void PrimitiveRenderer2::drawLineOpen(std::vector<Point2D>& points, const sf::Color color) {
    PrimitiveRenderer renderer2(this->window);
    if (points.size() < 2){
        return;
    }
    for (int i = 1; i < points.size(); i++){
        renderer2.drawLine(points[i - 1].getX(), points[i - 1].getY(), points[i].getX(), points[i].getY(), color);
    }
    return;
}

void PrimitiveRenderer2::drawLineClosed(std::vector<Point2D>& points, const sf::Color color) {
    PrimitiveRenderer renderer2(this->window);
    if (points.size() < 3) {
        return;
    }
    for (int i = 1; i < points.size(); ++i) {
        renderer2.drawLine(points[i - 1].getX(), points[i - 1].getY(), points[i].getX(), points[i].getY(), color);
    }
    renderer2.drawLine(points.back().getX(), points.back().getY(), points.front().getX(), points.front().getY(), color);
    return;
}
void PrimitiveRenderer2::drawConvexShapeFill(std::vector<Point2D>& points, const sf::Color& fillColor) {
    sf::ConvexShape convex;
    int n = points.size();
    convex.setPointCount(n);

    for (int i = 0; i < n; i++) {
        convex.setPoint(i, sf::Vector2f(points[i].getX(), points[i].getY()));
    }

    convex.setFillColor(fillColor);

    window->draw(convex);
    return;
}

void PrimitiveRenderer2::drawConvexShape(std::vector<Point2D>& points, const sf::Color& color) {
    sf::ConvexShape convex;
    int n = points.size();
    convex.setPointCount(n);

    for (int i = 0; i < n; i++) {
        convex.setPoint(i, sf::Vector2f(points[i].getX(), points[i].getY()));
    }

    convex.setOutlineColor(color);
    convex.setOutlineThickness(2);
    convex.setFillColor(sf::Color(0, 0, 0, 0));

    window->draw(convex);
    return;
}

void PrimitiveRenderer2::floodFill(Point2D& seed, const sf::Color targetColor, const sf::Color fillColor) {
    sf::Vector2u seedPixel(seed.getX(), seed.getY());
    sf::Image image = window->capture();
    if (image.getPixel(seedPixel.x, seedPixel.y) == targetColor) {
        floodFillRecursive(image, seedPixel, targetColor, fillColor);
    }
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite;
    sprite.setTexture(texture, true);
    window->draw(sprite);
    return;
}

void PrimitiveRenderer2::floodFillRecursive(sf::Image& image, const sf::Vector2u& pixel, const sf::Color& targetColor, const sf::Color& fillColor) {
    if (pixel.x < 0 || pixel.x >= image.getSize().x || pixel.y < 0 || pixel.y >= image.getSize().y) {
        return;
    }
    if (image.getPixel(pixel.x, pixel.y) != targetColor) {
        return;
    }
    image.setPixel(pixel.x, pixel.y, fillColor);
    floodFillRecursive(image, sf::Vector2u(pixel.x + 1, pixel.y), targetColor, fillColor);
    floodFillRecursive(image, sf::Vector2u(pixel.x - 1, pixel.y), targetColor, fillColor);
    floodFillRecursive(image, sf::Vector2u(pixel.x, pixel.y + 1), targetColor, fillColor);
    floodFillRecursive(image, sf::Vector2u(pixel.x, pixel.y - 1), targetColor, fillColor);
    return;
}

void PrimitiveRenderer2::borderFill(Point2D& seed, const sf::Color targetColor, const sf::Color fillColor) {
    sf::Vector2u seedPixel(seed.getX(), seed.getY());
    sf::Image image = window->capture();
    if (image.getPixel(seedPixel.x, seedPixel.y) == targetColor) {
        borderFillRecursive(image, seedPixel, targetColor, fillColor);
    }
    sf::Texture texture;
    texture.loadFromImage(image);
    sf::Sprite sprite;
    sprite.setTexture(texture, true);
    window->draw(sprite);
    return;
}

void PrimitiveRenderer2::borderFillRecursive(sf::Image& image, const sf::Vector2u& pixel, const sf::Color& targetColor, const sf::Color& fillColor) {
    if (pixel.x < 0 || pixel.x >= image.getSize().x || pixel.y < 0 || pixel.y >= image.getSize().y) {
        return;
    }
    if (image.getPixel(pixel.x, pixel.y) != targetColor) {
        return;
    }
    image.setPixel(pixel.x, pixel.y, fillColor);
    floodFillRecursive(image, sf::Vector2u(pixel.x + 1, pixel.y), targetColor, fillColor);
    floodFillRecursive(image, sf::Vector2u(pixel.x - 1, pixel.y), targetColor, fillColor);
    floodFillRecursive(image, sf::Vector2u(pixel.x, pixel.y + 1), targetColor, fillColor);
    floodFillRecursive(image, sf::Vector2u(pixel.x, pixel.y - 1), targetColor, fillColor);
    return;
}
