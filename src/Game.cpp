#include "Game.h"

Game::Game()
{
	_mainWindow = new sf::RenderWindow(sf::VideoMode(640, 480), "Raycaster");
    _player = new Player();
}

void Game::Run()
{
    while (_mainWindow->isOpen())
    {
        sf::Event event;
        while (_mainWindow->pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                _mainWindow->close();
        }

        _player->Update();

        _mainWindow->clear();
        _player->Draw(_mainWindow);
        _mainWindow->display();
    }
}
