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

void Player::Rotate()
{
	float tempAngle = sf::Mouse::getPosition().x * _rotVelocity;

	_helper._angle = tempAngle;
	_helper._line->setRotation(_helper._angle);
}

void Player::Forward()
{
	_helper._shape->setPosition(_helper._shape->getPosition().x - (sin(_helper._angle * PI / 180) * _velocity),
		                        _helper._shape->getPosition().y + (cos(_helper._angle * PI / 180) * _velocity));

	_helper._line->setPosition(_helper._line->getPosition().x - (sin(_helper._angle * PI / 180) * _velocity),
		                       _helper._line->getPosition().y + (cos(_helper._angle * PI / 180) * _velocity));
}

void Player::Backward()
{
	_helper._shape->setPosition(_helper._shape->getPosition().x + (sin(_helper._angle * PI / 180) * _velocity),
		                        _helper._shape->getPosition().y - (cos(_helper._angle * PI / 180) * _velocity));

	_helper._line->setPosition(_helper._line->getPosition().x + (sin(_helper._angle * PI / 180) * _velocity),
		                       _helper._line->getPosition().y - (cos(_helper._angle * PI / 180) * _velocity));
}

void Player::Left()
{
	_helper._shape->setPosition(_helper._shape->getPosition().x + (cos(_helper._angle * PI / 180) * _velocity),
		                        _helper._shape->getPosition().y - (sin(_helper._angle * PI / 180) * _velocity));

	_helper._line->setPosition(_helper._line->getPosition().x + (cos(_helper._angle * PI / 180) * _velocity),
		                       _helper._line->getPosition().y - (sin(_helper._angle * PI / 180) * _velocity));
}

void Player::Right()
{
	_helper._shape->setPosition(_helper._shape->getPosition().x - (cos(_helper._angle * PI / 180) * _velocity),
		                        _helper._shape->getPosition().y + (sin(_helper._angle * PI / 180) * _velocity));

	_helper._line->setPosition(_helper._line->getPosition().x - (cos(_helper._angle * PI / 180) * _velocity),
		                       _helper._line->getPosition().y + (sin(_helper._angle * PI / 180) * _velocity));
}

void Player::Move()
{
	switch (_input.pressedKey())
	{
	case eUP:
		Rotate();
		Forward();
		break;

	case eDOWN:
		Rotate();
		Backward();
		break;

	case eLEFT:
		Rotate();
		Left();
		break;

	case eRIGHT:
		Rotate();
		Right();
		break;

	default:
		Rotate();
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

sf::Vector2f Player::GetPosition()
{
	return sf::Vector2f(_helper._shape->getPosition().x + _radius, _helper._shape->getPosition().y - _radius);
}