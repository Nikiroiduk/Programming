#include "Card.h"
#include <vector>
#pragma once

using std::vector;
class Deck
{
private:
	vector<Card> _deck;
public:
	Deck();
	void shuffleCards();
	//Card getRandomCard();
};
