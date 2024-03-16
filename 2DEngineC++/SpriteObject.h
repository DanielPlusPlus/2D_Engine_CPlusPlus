#pragma once
#include "BitmapObject.h"
#include "AnimatedObject.h"

class SpriteObject : public BitmapObject, public AnimatedObject
{
    int framesNumber;
    int directionsNumber;
    int currentFrame;
    int frameWidth;
    int frameHeight;
    float frameDuration;

    void changeFrame(int direction);
    void changeDir();
    void changeBitmap(int index, sf::RenderWindow* window);
    void changeBitmap(int index);

public:
    SpriteObject(std::string filepath, int frames,int directions, float frameDuration);
    SpriteObject(std::vector<std::string> filepaths, float frameDuration);
    void animate(sf::Clock clock, int direction) override;
    void animateBitmaps(sf::Clock clock);
    void animateBitmaps(sf::Clock clock, sf::RenderWindow* window);
    ~SpriteObject();
};

