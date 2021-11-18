#pragma once
#include <string>
#include <vector>
#include <iostream>

using std::string;
using std::vector;
using std::cout;
using std::cin;

class ConsoleView
{
public:
	static string InputPlayerName();
	static int InputPlayerMoney();
	static int InputPlayerStake();
};

