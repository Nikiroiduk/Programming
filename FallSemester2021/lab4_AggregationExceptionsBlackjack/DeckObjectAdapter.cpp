#include "DeckObjectAdapter.h"

string DeckObjectAdapter::format() {
	return "\nRandom cards values: " + to_string(deck.getRandomCard().getValue())
		+ " " + to_string(deck.getRandomCard().getValue());
}