#include <SFML/Graphics.hpp>
#include "Input.h"

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
	void Rotate();
	void Move();

	Input _input;
	playerHelper _helper;

	float _radius = 10.f;
	float _rayLength = 25.f;
	float _thickness = 2.f;
};

