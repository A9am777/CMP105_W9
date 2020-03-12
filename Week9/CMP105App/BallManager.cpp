#include "BallManager.h"

BallManager::BallManager()
{
	spawnPt = sf::Vector2f(300,300);
	tex.loadFromFile("gfx/Beach_Ball.png");
	for (int i = 0; i < 20; i++)
	{
		balls.push_back(Ball());
		balls[i].setAlive(false);
		balls[i].setTexture(&tex);
		balls[i].setSize(sf::Vector2f(100, 100));
	}
}

BallManager::~BallManager()
{

}

#include <iostream>

void BallManager::spawn()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (!balls[i].isAlive())
		{
			balls[i].setAlive(true);
			balls[i].setPosition(spawnPt);
			balls[i].setVelocity(sf::Vector2f(rand()%300-150, rand() % 300 - 150));
			return;
		}
	}
	Ball newB = Ball();
	newB.setAlive(false);
	newB.setTexture(&tex);
	newB.setSize(sf::Vector2f(100, 100));
	balls.push_back(newB);
	std::cout << "new ball spawned" << std::endl;
}

void BallManager::update(float dt)
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

void BallManager::deathCheck()
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].getPosition().x < -balls[i].getSize().x) { balls[i].setAlive(false); }
		if (balls[i].getPosition().y < -balls[i].getSize().y) { balls[i].setAlive(false); }
		if (balls[i].getPosition().y > screenSiz.y) { balls[i].setAlive(false); }
		if (balls[i].getPosition().y > screenSiz.x) { balls[i].setAlive(false); }
	}
}

void BallManager::render(sf::RenderWindow* dHandle)
{
	for (int i = 0; i < balls.size(); i++)
	{
		if (balls[i].isAlive())
		{
			dHandle->draw(balls[i]);
		}
	}
}

void BallManager::setScreenSize(sf::Vector2u newSiz)
{
	screenSiz = newSiz;
}
