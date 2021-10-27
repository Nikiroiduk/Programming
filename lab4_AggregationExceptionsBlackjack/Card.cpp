#include "Card.h"
#include <io.h>
#include <fcntl.h>

Card::Card(int rank, int suit) {
	this->suit = suit;
	this->rank = rank;
	this->value = getCardValue();
}

int Card::getCardValue() {
	switch (rank)
	{
	case jack:
		return 10;
		break;
	case queen:
		return 10;
		break;
	case king:
		return 10;
		break;
	case ace:
		return 11;
		break;
	default:
		return rank;
		break;
	}
}

void Card::print() {
	switch (rank)
	{
	case jack:
		std::cout << "J";
		break;
	case queen:
		std::cout << "Q";
		break;
	case king:
		std::cout << "K";
		break;
	case ace:
		std::cout << "A";
		break;
	default:
		std::cout << rank;
		break;
	}
	_setmode(_fileno(stdout), _O_U16TEXT);
	switch (suit)
	{
	case spade:
		std::wcout << SPADE;
		break;
	case heart:
		std::wcout << HEART;
		break;
	case diamond:
		std::wcout << DIAMOND;
		break;
	case club:
		std::wcout << CLUB;
		break;
	}
	_setmode(_fileno(stdout), _O_TEXT);
}