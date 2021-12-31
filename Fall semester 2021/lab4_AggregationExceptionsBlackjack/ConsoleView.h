#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "Player.h"
#include "Game.h"
#include "Card.h"
#include "Suit.h"
#include "Rank.h"
#include <stdexcept>
#include <algorithm>

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::wcout;
using std::invalid_argument;
using std::for_each;

class ConsoleView
{
public:
	static string InputPlayerName();
	static int InputPlayerMoney();
	static int InputPlayerStake();
	static string InputPlayerAnswer();
	static int InputGameAction(bool& state);
	static void Print(const string& string);
	static void PrintPlayerInfo(const Player& player);
	static void PrintTable(Game& game, bool& isGameOver);
	static void PrintSplitedTable(Game& game, bool& isGameOver);
};

