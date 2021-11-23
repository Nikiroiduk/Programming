#pragma once
#include <iostream>
#include <io.h>
#include <fcntl.h>
#include "Rank.h"
#include "Suit.h"
#include "IComparable.h"

using std::ostream;

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
	//TODO: Тутачки что-то нужно придумать
	friend ostream& operator<<(ostream& out, const Card& card) {};
};
