#pragma once
#include <iostream>
#include "Rank.h"
#include "Suit.h"
#include "IComparable.h"

using std::ostream;
using std::string;
using std::cout;

class Card : public IComparable<Card>
{
	friend ostream& operator<<(ostream& out, const Card& card) {
		auto rank = card._rank;
		auto suit = card._suit;
		string suits[] = { "\x03", "\x04", "\x05", "\x06" };

		cout << "[";
		switch (rank)
		{
		case jack:
			out << "J";
			break;
		case queen:
			out << "Q";
			break;
		case king:
			out << "K";
			break;
		case ace:
			out << "A";
			break;
		default:
			out << rank;
			break;
		}
		out << suits[static_cast<int>(card._suit)];
		out << "]";
		return out;
	};
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
