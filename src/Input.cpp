#include "Input.h"

Input::Input()
{
	_keyHandler = eNONE;
}

Input::~Input()
{

}

E_keys Input::pressedKey()
{
	if (_keyboard.isKeyPressed(sf::Keyboard::W) || _keyboard.isKeyPressed(sf::Keyboard::Up))
	{
		_keyHandler = eUP;
	}
	else if (_keyboard.isKeyPressed(sf::Keyboard::S) || _keyboard.isKeyPressed(sf::Keyboard::Down))
	{
		_keyHandler = eDOWN;
	}
	else if (_keyboard.isKeyPressed(sf::Keyboard::A) || _keyboard.isKeyPressed(sf::Keyboard::Left))
	{
		_keyHandler = eLEFT;
	}
	else if (_keyboard.isKeyPressed(sf::Keyboard::D) || _keyboard.isKeyPressed(sf::Keyboard::Right))
	{
		_keyHandler = eRIGHT;
	}
	else if (_keyboard.isKeyPressed(sf::Keyboard::LShift) || _keyboard.isKeyPressed(sf::Keyboard::RShift))
	{
		_keyHandler = eSHIFT;
	}
	else if (_keyboard.isKeyPressed(sf::Keyboard::LControl) || _keyboard.isKeyPressed(sf::Keyboard::RControl))
	{
		_keyHandler = eCTRL;
	}
	else if (_keyboard.isKeyPressed(sf::Keyboard::Space))
	{
		_keyHandler = eSPACE;
	}
	else if (_keyboard.isKeyPressed(sf::Keyboard::Escape))
	{
		_keyHandler = eESC;
	}
	else
	{
		_keyHandler = eNONE;
	}

	return _keyHandler;
}