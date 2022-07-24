#pragma once

#include "Utilities.h"
#include <SFML/Graphics.hpp>

class Input
{
public:
	Input();
	~Input();

	E_keys pressedKey();

private:
	E_keys _keyHandler;
	sf::Keyboard _keyboard;
};

