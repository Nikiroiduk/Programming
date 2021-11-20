#pragma once
#include <iostream>
#include "Rank.h"
#include "IComparable.h"

class Card : public IComparable<Card>
{
private:
	int _suit = -1;
	int _rank = -1;
	int _value = 0;
	int getCardValue();
public:
	Card(int rank, int suit);
	int getSuit();
	int getRank();
	bool operator==(const Card& card1) override;
};

