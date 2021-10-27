#include <iostream>
#pragma once

#define SPADE L"\u2660"
#define CLUB L"\u2663"
#define HEART L"\u2665"
#define DIAMOND L"\u2666"
enum Suit {
	spade,
	club,
	heart,
	diamond
};

enum Rank {
	two = 2,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	jack,
	queen,
	king,
	ace
};

class Card
{
private:
	int suit = -1;
	int rank = -1;
	int value = 0;
	int getCardValue();
public:
	Card(int rank, int suit);
	void print();
};

