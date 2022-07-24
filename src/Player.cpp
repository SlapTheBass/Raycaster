#include "Player.h"

Player::Player()
{
	helperInit(&_helper);
}

Player::~Player()
{

}

void Player::helperInit(playerHelper* ptrHelper)
{
	ptrHelper->_origin = { 200.f, 200.f };
	ptrHelper->_shape = new sf::CircleShape(_radius);
	ptrHelper->_shape->setPosition(ptrHelper->_origin);
	ptrHelper->_shape->setFillColor(sf::Color::Red);

	ptrHelper->_line = new sf::RectangleShape(sf::Vector2f(_thickness, _rayLength));
	ptrHelper->_line->setPosition(ptrHelper->_shape->getPosition().x + _radius, ptrHelper->_shape->getPosition().y + _radius);
	ptrHelper->_line->setFillColor(sf::Color::White);
}

void Player::RotateLeft()
{
	_helper._angle = _helper._angle - _rotVelocity;
	_helper._line->setRotation(_helper._angle);
}

void Player::RotateRight()
{
	_helper._angle = _helper._angle + _rotVelocity;
	_helper._line->setRotation(_helper._angle);
}

void Player::Forward()
{
	_helper._shape->setPosition(_helper._shape->getPosition().x - (sin(_helper._angle * PI / 180) * _velocity), _helper._shape->getPosition().y + (cos(_helper._angle * PI / 180) * _velocity));
	_helper._line->setPosition(_helper._line->getPosition().x - (sin(_helper._angle * PI / 180) * _velocity), _helper._line->getPosition().y + (cos(_helper._angle * PI / 180) * _velocity));
}

void Player::Backward()
{
	_helper._shape->setPosition(_helper._shape->getPosition().x + (sin(_helper._angle * PI / 180) * _velocity), _helper._shape->getPosition().y - (cos(_helper._angle * PI / 180) * _velocity));
	_helper._line->setPosition(_helper._line->getPosition().x + (sin(_helper._angle * PI / 180) * _velocity), _helper._line->getPosition().y - (cos(_helper._angle * PI / 180) * _velocity));
}

void Player::Left()
{
	_helper._shape->setPosition(_helper._shape->getPosition().x + (cos(_helper._angle * PI / 180) * _velocity), _helper._shape->getPosition().y + (sin(_helper._angle * PI / 180) * _velocity));
	_helper._line->setPosition(_helper._line->getPosition().x + (cos(_helper._angle * PI / 180) * _velocity), _helper._line->getPosition().y + (sin(_helper._angle * PI / 180) * _velocity));
}

void Player::Right()
{
	_helper._shape->setPosition(_helper._shape->getPosition().x - (cos(_helper._angle * PI / 180) * _velocity), _helper._shape->getPosition().y - (sin(_helper._angle * PI / 180) * _velocity));
	_helper._line->setPosition(_helper._line->getPosition().x - (cos(_helper._angle * PI / 180) * _velocity), _helper._line->getPosition().y - (sin(_helper._angle * PI / 180) * _velocity));
}

void Player::Move()
{
	switch (_input.pressedKey())
	{
	case eUP:
		Forward();
		break;

	case eUP_LEFT:
		RotateLeft();
		Forward();
		break;

	case eUP_RIGHT:
		RotateRight();
		Forward();
		break;

	case eDOWN:
		Backward();
		break;

	case eDOWN_LEFT:
		RotateLeft();
		Backward();
		break;

	case eDOWN_RIGHT:
		RotateRight();
		Backward();
		break;

	case eROT_LEFT:
		RotateLeft();
		break;

	case eROT_RIGHT:
		RotateRight();
		break;

	case eLEFT:
		Left();
		break;

	case eRIGHT:
		Right();
		break;

	default:
		break;
	}
}

void Player::Update()
{
	Move();
}

void Player::Draw(sf::RenderWindow* window)
{
	window->draw(*_helper._shape);
	window->draw(*_helper._line);
}