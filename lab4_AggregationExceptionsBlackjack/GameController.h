#pragma once
#include "Game.h"

using std::string;
using std::vector;
using std::srand;
using std::rand;
using std::time;

class GameController
{
private:
	Game _game;
	vector<Card> getRandomHand();
public:
	GameController();
	void launch();
};

