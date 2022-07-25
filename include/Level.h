#pragma once

#include <SFML/Graphics.hpp>

struct floorHelper
{
	float thickness = 1.0f;
	float length = 1024.0f;
	
	std::vector<std::shared_ptr<sf::RectangleShape>> verticalLines;
	std::vector<std::shared_ptr<sf::RectangleShape>> horizontalLines;
};

class Level
{
public:
	Level();
	~Level();

	void Draw(sf::RenderWindow* window);

private:
	floorHelper _helper;

	int _xLineStep = 20;
	int _yLineStep = 20;

	void Generate();
	void Init();
	void drawHelper(sf::RenderWindow* window);
};

