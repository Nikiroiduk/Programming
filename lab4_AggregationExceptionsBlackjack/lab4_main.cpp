#include <iostream>
#include "Card.h"
#include "Deck.h"

int main() {
	Deck x(1);
	x.print();
	std::cout << "\n";
	x.getRandomCard().print();
	return 0;
}