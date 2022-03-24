#include "DeckClassAdapter.h"

string DeckClassAdapter::format() {
	return "\nDeck size: " + to_string(_deck.size());
}

