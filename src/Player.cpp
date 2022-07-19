#include "Player.h"

Player::Player()
{
	_shape = new sf::CircleShape(10.f);
	_shape->setFillColor(sf::Color::Red);
}

void Player::Draw(sf::RenderWindow* window)
{
	window->draw(*_shape);
}