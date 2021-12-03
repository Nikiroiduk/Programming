#pragma once
#include "Game.h"

using std::string;
using std::vector;
using std::exception;
using std::srand;
using std::rand;
using std::time;
using std::to_string;

class GameController
{
private:
	Game _game;
	int _minStake;
	vector<Card> getRandomHand();
	Card getRandomCard();
	//bool isBust(vector<Card> hand);
	bool isSplitable();
	int countPoints(vector<Card> hand);
	void start();
	void game();
	bool splitedGame();
public:
	GameController();
	void launch();
};

