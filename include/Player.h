#include <SFML/Graphics.hpp>
#include "Input.h"
#include <iostream>

#pragma once

#define PI 3.14159265359

struct playerHelper
{
	sf::CircleShape* _shape;
	sf::RectangleShape* _line;
	sf::Vector2f _origin;

	float _angle = 0.0f;
};

class Player
{
public:
	Player();
	~Player();

	void helperInit(playerHelper* helper);
	void Update();
	void Draw(sf::RenderWindow* window);

private:
	Input _input;
	playerHelper _helper;

	float _radius = 10.f;
	float _rayLength = 25.f;
	float _thickness = 2.f;
	float _velocity = 0.13f;
	float _rotVelocity = 0.12f;

	void RotateLeft();
	void RotateRight();

	void Forward();
	void Backward();
	void Left();
	void Right();

	void Move();
};

