#include "Deck.h"

Deck::Deck(){
	srand(time(0));
	newDeck();
}

void Deck::newDeck() {
	for (int i = 0; i < 4; ++i) {
		for (int j = 2; j < 15; ++j) {
			_deck.push_back(Card(j, i));
		}
	}
}

Card Deck::getRandomCard() {
	int rnd = rand() % _deck.size();
	Card tmp = _deck[rnd];
	_deck.erase(_deck.begin() + rnd);
	return tmp;
}
