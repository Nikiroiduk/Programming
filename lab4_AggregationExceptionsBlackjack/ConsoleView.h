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
private:
	static void printCard(Card& card);
public:
	static string InputPlayerName();
	static int InputPlayerMoney();
	static int InputPlayerStake();

	static void PrintPlayerInfo(const Player& player);
	static void PrintTable(Game& game);
};

