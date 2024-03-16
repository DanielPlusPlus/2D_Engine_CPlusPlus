#include "Player.h"

Player::Player(std::string filepath,int frames, int directions) : SpriteObject(filepath, frames,directions, 0.001f)
{
	this->frames = frames;
	this->directions = directions;
	this->currentDirection = 0;
	this->frameHeight = texture.getSize().y / directions;
	this->idle = true;
}

void Player::handleInput(sf::RenderWindow* window, sf::Event event)
{
	if (event.type == sf::Event::KeyPressed) {
		changeDirection(event);
	}
	if (event.type == sf::Event::KeyReleased) {
		if (event.key.code == sf::Keyboard::Right || event.key.code == sf::Keyboard::Left ||
			event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down) {
			idle = true;
			spriteRect.top = 0;
			this->speedx = 0;
			this->speedy = 0;
		}
	}
}

void Player::updateAnimation(sf::Clock clock)
{
	if (idle) {
		currentDirection = 0;
		animate(clock, currentDirection);
	}
	else if (!idle) {
		animate(clock, currentDirection);
	}


}

void Player::changeDirection(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Down) {
		if (spriteRect.top == 0 || spriteRect.top == frameHeight || spriteRect.top == 2 * frameHeight || spriteRect.top == 3 * frameHeight) {
			spriteRect.top = 4 * frameHeight;
			this->speedy = 10;
			idle = false;
			currentDirection = 4;
		}
			if (spriteRect.top == 4 * frameHeight) {
				this->speedy = 10;
				sprite.move(speedx, speedy);
			}
		}
		if (event.key.code == sf::Keyboard::Up) {
			if (spriteRect.top == 0 || spriteRect.top == frameHeight || spriteRect.top == 2 * frameHeight || spriteRect.top == 4 * frameHeight) {
				spriteRect.top = 3 * frameHeight;
				this->speedy = -10;
				idle = false;
				currentDirection = 3;
			}
			if (spriteRect.top == 3 * frameHeight) {
				this->speedy = -10;
				sprite.move(speedx, speedy);
			}
		}
		if (event.key.code == sf::Keyboard::Left) {
			if (spriteRect.top == 0 || spriteRect.top == frameHeight || spriteRect.top == 3 * frameHeight || spriteRect.top == 4 * frameHeight) {
				spriteRect.top = 2 * frameHeight;
				this->speedx = -10;
				idle = false;
				currentDirection = 2;
			}
			if (spriteRect.top == 2 * frameHeight) {
				this->speedx = -10;
				sprite.move(speedx, speedy);
			}
		}
		if (event.key.code == sf::Keyboard::Right) {
			if (spriteRect.top == 0 || spriteRect.top == 2 * frameHeight || spriteRect.top == 3 * frameHeight || spriteRect.top == 4 * frameHeight) {
				spriteRect.top = frameHeight;
				this->speedx = 10;
				idle = false;
				currentDirection = 1;
			}
			if (spriteRect.top == frameHeight) {
				this->speedx = 10;
				sprite.move(speedx, speedy);
			}
		}
	}


Player::~Player()
{

}
