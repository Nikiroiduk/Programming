#include "Card.h"
#include <vector>
#pragma once
class Deck
{
private:
	std::vector<Card> deck;
public:
	Deck(int numOfDecks);
	void print();
	Card getRandomCard();
};