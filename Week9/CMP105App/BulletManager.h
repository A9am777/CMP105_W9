#pragma once
#include "SFML/Graphics.hpp"
#include <math.h>
#include <vector>
#include "Ball.h"
#include "Framework/Vector.h"
class BulletManager
{
	public:
		BulletManager();
		~BulletManager();

		void spawn(sf::Vector2f, sf::Vector2f);
		void update(float);
		void deathCheck();
		void render(sf::RenderWindow*);

		void setScreenSize(sf::Vector2u);

	private:
		std::vector<Ball> bullets;
		sf::Texture tex;
		sf::Vector2u screenSiz;
};

