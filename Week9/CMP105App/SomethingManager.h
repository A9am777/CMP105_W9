#pragma once
#include "SFML/Graphics.hpp"
#include <math.h>
#include <vector>
#include "Ball.h"
class SomethingManager
{
	public:
		SomethingManager();
		~SomethingManager();

		void spawn();
		void update(float);
		void deathCheck();
		void render(sf::RenderWindow*);

		void setScreenSize(sf::Vector2u);

	private:
		std::vector<Ball> balls;
		sf::Texture tex;
		sf::Vector2u screenSiz;
};

