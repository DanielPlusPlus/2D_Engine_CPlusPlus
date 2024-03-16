#include "Engine.h"

void Engine::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 800), "Game Engine", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
}

void Engine::initVariables()
{
	this->window = nullptr;
	this->bitmapHandler = new BitmapHandler("BG.jpg");
	this->player = new Player("BlueSlimeSpriteSheet (2).png", 8, 5);
	this->spriteObject = new SpriteObject("fire1_64.png", 10, 6, 0.006f);
	this->spriteObject->translate(500, 500);
	this->spriteObject->scale(2.0f, 2.0f);
}


Engine::Engine()
{
	this->initVariables();
	this->initWindow();
}

Engine::~Engine()
{
	delete this->window;
}

void Engine::pollEvent()
{
	while (this->window->pollEvent(this->event)) {
		this->player->handleInput(this->window, this->event);
		switch (event.type) {
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}

void Engine::update()
{
	this->pollEvent();
}

void Engine::render(sf::Clock clock)
{
    this->window->clear(sf::Color(40, 50, 60, 50));
	this->window->display();
}

void Engine::run()
{
	sf::Clock clock;
	while (this->window->isOpen()) {

		this->update();

		this->render(clock);
	}
}
