#include "Deck.h"

Deck::Deck(){
	shuffleCards();
}

void Deck::shuffleCards() {
	std::srand(std::time(0));
		for (int i = 0; i < 4; ++i) {
			for (int j = 2; j < 15; ++j) {
				_deck.push_back(Card(j, i));
			}
		}
}

//Card Deck::getRandomCard() {
//	int rnd = std::rand() % _deck.size();
//	Card tmp = _deck[rnd];
//	_deck.erase(_deck.begin() + rnd);
//	return tmp;
//}
