#include "BulletManager.h"

BulletManager::BulletManager()
{
	tex.loadFromFile("gfx/MushroomTrans.png");
	for (int i = 0; i < 40; i++)
	{
		bullets.push_back(Ball());
		bullets[i].setAlive(false);
		bullets[i].setTexture(&tex);
		bullets[i].setSize(sf::Vector2f(100, 100));
	}
}

BulletManager::~BulletManager()
{

}

#include <iostream>

void BulletManager::spawn(sf::Vector2f dir, sf::Vector2f pos)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (!bullets[i].isAlive())
		{
			bullets[i].setAlive(true);
			bullets[i].setPosition(pos);
			bullets[i].setVelocity(Vector::normalise(dir)*400.0f);
			return;
		}
	}
	Ball newB = Ball();
	newB.setAlive(false);
	newB.setTexture(&tex);
	newB.setSize(sf::Vector2f(100, 100));
	newB.setPosition(pos);
	newB.setVelocity(Vector::normalise(dir) * 400.0f);
	bullets.push_back(newB);
	std::cout << "new bullet spawned" << std::endl;
}

void BulletManager::update(float dt)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			bullets[i].update(dt);
		}
	}
	deathCheck();
}

void BulletManager::deathCheck()
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].getPosition().x < -bullets[i].getSize().x) { bullets[i].setAlive(false); }
		if (bullets[i].getPosition().y < -bullets[i].getSize().y) { bullets[i].setAlive(false); }
		if (bullets[i].getPosition().y > screenSiz.y) { bullets[i].setAlive(false); }
		if (bullets[i].getPosition().y > screenSiz.x) { bullets[i].setAlive(false); }
	}
}

void BulletManager::render(sf::RenderWindow* dHandle)
{
	for (int i = 0; i < bullets.size(); i++)
	{
		if (bullets[i].isAlive())
		{
			dHandle->draw(bullets[i]);
		}
	}
}

void BulletManager::setScreenSize(sf::Vector2u newSiz)
{
	screenSiz = newSiz;
}
