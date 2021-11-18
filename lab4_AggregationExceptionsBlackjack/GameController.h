#pragma once
#include "Game.h"

using std::string;
using std::vector;

class GameController
{
private:
	Game _game;
public:
	GameController();
	void launch();
};

