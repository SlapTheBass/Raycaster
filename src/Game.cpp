#include "Game.h"

Game::Game()
{
	_mainWindow = new sf::RenderWindow(sf::VideoMode(640, 480), "Raycaster");
    _mainWindow->setKeyRepeatEnabled(true);
    _player = new Player();
    _level = new Level();
}

Game::~Game()
{

}

void Game::Update()
{
    _player->Update();
}

void Game::Draw()
{
    _mainWindow->clear();
    _level->Draw(_mainWindow);
    _player->Draw(_mainWindow);
    _mainWindow->display();
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

        Update();

        Draw();
    }
}
