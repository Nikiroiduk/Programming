#include "Deck.h"

Deck::Deck(int numOfDecks) {
	std::srand(std::time(0));
	for (int k = 0; k < numOfDecks; ++k) {
		for (int i = 0; i < 4; ++i) {
			for (int j = 2; j < 15; ++j) {
				deck.push_back(Card(j, i));
			}
		}
	}
}

Card Deck::getRandomCard() {
	int rnd = std::rand() % deck.size();
	Card tmp = deck[rnd];
	deck.erase(deck.begin() + rnd);
	return tmp;
}

void Deck::print() {
	for (int i = 0; i < deck.size(); ++i) {
		deck[i].print();
		std::cout << " ";
	}
}