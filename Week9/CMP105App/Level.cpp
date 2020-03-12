#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	srand(time(0));
	balz.setScreenSize(window->getSize());
	some.setScreenSize(window->getSize());

	pTex.loadFromFile("gfx/Goomba.png");
	player.setTexture(&pTex);
	player.setSize(sf::Vector2f(75,75));
	player.setInput(input);
	player.setScreenSize(window->getSize());
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		balz.spawn();
	}
	if (input->isMouseLDown())
	{
		some.spawn();
	}
	player.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	balz.update(dt);
	some.update(dt);
	player.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	balz.render(window);
	some.render(window);
	window->draw(player);
	player.draw(window);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}