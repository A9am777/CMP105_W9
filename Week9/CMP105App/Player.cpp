#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
}

void Player::draw(sf::RenderWindow* dHandle)
{
	bullets.render(dHandle);
}

void Player::update(float dt)
{
	move(velocity * dt);
	bullets.update(dt);
}

void Player::handleInput(float dt)
{
	velocity = sf::Vector2f(0,0);
	if (input->isKeyDown(sf::Keyboard::W))
	{
		velocity.y -= 300;
	}
	if (input->isKeyDown(sf::Keyboard::A))
	{
		velocity.x -= 300;
	}
	if (input->isKeyDown(sf::Keyboard::S))
	{
		velocity.y += 300;
	}
	if (input->isKeyDown(sf::Keyboard::D))
	{
		velocity.x += 300;
	}

	if (input->isKeyDown(sf::Keyboard::R))
	{
		bullets.spawn(sf::Vector2f(input->getMouseX(),input->getMouseY())-getPosition(), getPosition());
	}
}

void Player::setScreenSize(sf::Vector2u scrnSz)
{
	bullets.setScreenSize(scrnSz);
}
