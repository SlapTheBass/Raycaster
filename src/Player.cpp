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
		_helper._line->setRotation(_helper._angle = _helper._angle - 0.1f);
		if (_helper._angle >= 360)
		{
			_helper._angle = 0;
		}
		else if (_helper._angle <= 0)
		{
			_helper._angle = 360;
		}
		break;

	case eRIGHT:
		_helper._line->setRotation(_helper._angle = _helper._angle + 0.1f);
		if (_helper._angle >= 360)
		{
			_helper._angle = 0;
		}
		else if (_helper._angle <= 0)
		{
			_helper._angle = 360;
		}
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
		if (_helper._angle >= 270 && _helper._angle < 360) //First quarter
		{
			_helper._shape->setPosition(_helper._shape->getPosition().x + (sin(_helper._angle) * 0.1f), _helper._shape->getPosition().y + (cos(_helper._angle) * 0.1f));
		    _helper._line->setPosition(_helper._line->getPosition().x + (sin(_helper._angle) * 0.1f), _helper._line->getPosition().y + (cos(_helper._angle) * 0.1f));
		}
		else if (_helper._angle >= 90 && _helper._angle < 180) //Second qurter
		{
			/*_helper._shape->setPosition(_helper._shape->getPosition().x + (sin(_helper._angle) * 0.2f), _helper._shape->getPosition().y + (cos(_helper._angle) * 0.2f));
			_helper._line->setPosition(_helper._line->getPosition().x + (sin(_helper._angle) * 0.2f), _helper._line->getPosition().y + (cos(_helper._angle) * 0.2f));*/
		}
		break;

	case eDOWN:
		if (_helper._angle >= 0 && _helper._angle <= 90)
		{
			_helper._shape->setPosition(_helper._shape->getPosition().x - (sin(_helper._angle) * 0.2f), _helper._shape->getPosition().y - (cos(_helper._angle) * 0.2f));
			_helper._line->setPosition(_helper._line->getPosition().x - (sin(_helper._angle) * 0.2f), _helper._line->getPosition().y - (cos(_helper._angle) * 0.2f));
		}

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