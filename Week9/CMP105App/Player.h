#pragma once
#include "Framework/GameObject.h"
#include "SFML/Graphics.hpp"
#include "BulletManager.h"
class Player :
public GameObject
{
	public:
		Player();
		~Player();

		void draw(sf::RenderWindow*);
		void update(float) override;
		void handleInput(float) override;

		void setScreenSize(sf::Vector2u);
	private:
		BulletManager bullets;
};

