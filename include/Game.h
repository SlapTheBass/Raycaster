#pragma once

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Level.h"
#include "TextureManager.h"
#include "SoundManager.h"
#include "Utilities.h"

namespace game
{
	typedef enum E_GameState
	{
		eOnInit = 0,
		eMenu,
		eRun,
		eClose
	};

	typedef enum E_Menu
	{
		eStart = 0,
		eSettings,
		eSave,
		eLoad,
		eQuit
	};
}

class Game
{
public:
	Game();
	~Game();

	void Init();
	void Run();
	void Close();

private:
	sf::RenderWindow* _mainWindow;
	Player* _player;
	Level* _level;

	void Update();
	void Draw();
};

