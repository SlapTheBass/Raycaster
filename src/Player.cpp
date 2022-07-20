#include "Player.h"

Player::Player()
{
	helperInit(&_helper);
}

void Player::helperInit(playerHelper* ptrHelper)
{
	ptrHelper->_origin = { 500.f, 500.f };
	ptrHelper->_shape = new sf::CircleShape(_radius);
	ptrHelper->_shape->setFillColor(sf::Color::Red);

	ptrHelper->_line = new sf::RectangleShape(sf::Vector2f(_thickness, _rayLength));
	ptrHelper->_line->setPosition(ptrHelper->_shape->getPosition().x + _radius, ptrHelper->_shape->getPosition().y + _radius);
	ptrHelper->_line->setFillColor(sf::Color::White);
}

void Player::Rotate()
{
	switch (_input.pressedKey())
	{
	case eLEFT:
		_helper._line->setRotation(_helper._angle--);
		break;

	case eRIGHT:
		_helper._line->setRotation(_helper._angle++);
		break;

	default:
		break;
	}
}

void Player::Move()
{
	switch (_input.pressedKey())
	{
	case eUP:
		_helper._shape->setPosition(_helper._shape->getPosition().x + sin(_helper._angle), _helper._shape->getPosition().y + cos(_helper._angle));
		_helper._line->setPosition(_helper._line->getPosition().x + sin(_helper._angle), _helper._line->getPosition().y + cos(_helper._angle));
		break;

	case eDOWN:

		break;

	default:
		break;
	}
}

void Player::Update()
{
	Rotate();
	Move();
}

void Player::Draw(sf::RenderWindow* window)
{
	window->draw(*_helper._shape);
	window->draw(*_helper._line);
}