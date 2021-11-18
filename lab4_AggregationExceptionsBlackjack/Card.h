#include <iostream>
#include "IPrintable.h"
#pragma once

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

class Card : public IPrintable
{
private:
	int _suit = -1;
	int _rank = -1;
	int _value = 0;
	int getCardValue();
public:
	Card(int rank, int suit);
	//TODO: The model is used for output. Don't do like this...
	void print() const override;
};

