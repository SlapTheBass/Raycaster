#include "Level.h"

Level::Level()
{
	Init();
}

Level::~Level()
{

}

void Level::Init()
{
	for (int i = 0; i < 60; ++i)
	{
		std::shared_ptr<sf::RectangleShape> line = std::make_shared<sf::RectangleShape>(sf::Vector2f(_helper.thickness, _helper.length));
		line->setFillColor(sf::Color(14,128,11));
		line->setPosition((i * _xLineStep), 0.0f);
		_helper.verticalLines.push_back(line);
	}

	for (int i = 0; i < 60; ++i)
	{
		std::shared_ptr<sf::RectangleShape> line = std::make_shared<sf::RectangleShape>(sf::Vector2f(_helper.thickness, _helper.length));
		line->setFillColor(sf::Color(14, 128, 11));
		line->setRotation(-90);
		line->setPosition(0.0f, (i * _yLineStep));
		_helper.horizontalLines.push_back(line);
	}
}

void Level::drawHelper(sf::RenderWindow* window)
{
	for (auto line : _helper.horizontalLines)
	{
		window->draw(*line);
	}

	for (auto line : _helper.verticalLines)
	{
		window->draw(*line);
	}
}

void Level::Draw(sf::RenderWindow* window)
{
	drawHelper(window);
}

