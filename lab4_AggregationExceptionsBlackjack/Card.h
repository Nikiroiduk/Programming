#pragma once
#include <iostream>
#include "Rank.h"
#include "Suit.h"
#include "IComparable.h"

using std::ostream;

class Card : public IComparable<Card>
{
	friend ostream & operator<<(ostream & out, const Card & card);
private:
	int _suit = -1;
	int _rank = -1;
	int _value = 0;
	int getCardValue();
public:
	Card(int rank, int suit);
	int getSuit();
	int getRank();
	int getValue();
	bool operator==(const Card& card1) override;
};
