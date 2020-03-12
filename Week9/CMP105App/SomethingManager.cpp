#include "SomethingManager.h"

SomethingManager::SomethingManager()
{
	tex.loadFromFile("gfx/MushroomTrans.png");
	for (int i = 0; i < 40; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&tex);
		balls[i].setSize(sf::Vector2f(100, 100));
	}
}

SomethingManager::~SomethingManager()
{

}

#include <iostream>

void SomethingManager::spawn()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setPosition(sf::Vector2f(rand()%screenSiz.x,-balls[i].getSize().y));
			balls[i].setVelocity(sf::Vector2f(0, rand() % 300));
			return;
		}
	}
}

void SomethingManager::update(float dt)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			balls[i].update(dt);
		}
	}
	deathCheck();
}

void SomethingManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].getPosition().x < -balls[i].getSize().x) { balls[i].setAlive(false); }
		if (balls[i].getPosition().y < -balls[i].getSize().y) { balls[i].setAlive(false); }
		if (balls[i].getPosition().y > screenSiz.y) { balls[i].setAlive(false); }
		if (balls[i].getPosition().y > screenSiz.x) { balls[i].setAlive(false); }
	}
}

void SomethingManager::render(sf::RenderWindow* dHandle)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			dHandle->draw(balls[i]);
		}
	}
}

void SomethingManager::setScreenSize(sf::Vector2u newSiz)
{
	screenSiz = newSiz;
}
