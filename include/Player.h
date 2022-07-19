#include <SFML/Graphics.hpp>

#pragma once

class Player
{
public:
	Player();
	~Player();

	void Update();
	void Draw(sf::RenderWindow* window);

private:
	sf::CircleShape* _shape;
};

