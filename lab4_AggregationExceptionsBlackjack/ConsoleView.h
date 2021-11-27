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

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::wcout;

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
	static void PrintTable(Game& game, bool& isGameOver, bool& isSplited);
};

