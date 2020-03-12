#pragma once
#include "SFML/Graphics.hpp"
#include <math.h>
#include <vector>
#include "Ball.h"
class BallManager
{
	public:
		BallManager();
		~BallManager();

		void spawn();
		void update(float);
		void deathCheck();
		void render(sf::RenderWindow*);

		void setScreenSize(sf::Vector2u);

	private:
		std::vector<Ball> balls;
		sf::Vector2f spawnPt;
		sf::Texture tex;
		sf::Vector2u screenSiz;
};

