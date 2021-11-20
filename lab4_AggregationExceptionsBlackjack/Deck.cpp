#include "Deck.h"

Deck::Deck(){
	shuffleCards();
	srand(time(0));
}

void Deck::shuffleCards() {
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
