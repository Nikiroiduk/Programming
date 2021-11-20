#pragma once
#include <vector>
#include "Card.h"

using std::vector;
using std::srand;
using std::rand;
using std::time;

class Deck
{
private:
	vector<Card> _deck;
public:
	Deck();
	void shuffleCards();
	Card getRandomCard();
};
