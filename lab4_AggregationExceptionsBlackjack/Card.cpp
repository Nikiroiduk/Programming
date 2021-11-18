#include "Card.h"
#include <io.h>
#include <fcntl.h>

using std::cout;
using std::wcout;
Card::Card(int rank, int suit) {
	_suit = suit;
	_rank = rank;
	_value = getCardValue();
}

int Card::getCardValue() {
	switch (_rank)
	{
	case jack:
	case queen:
	case king:
		return 10;
		break;
	case ace:
		return 11;
		break;
	default:
		return _rank;
		break;
	}
}

void Card::print() const {
	cout << "[";
	switch (_rank)
	{
	case jack:
		cout << "J";
		break;
	case queen:
		cout << "Q";
		break;
	case king:
		cout << "K";
		break;
	case ace:
		cout << "A";
		break;
	default:
		cout << _rank;
		break;
	}
	_setmode(_fileno(stdout), _O_U16TEXT);
	switch (_suit)
	{
	case spade:
		wcout << L"\u2660";
		break;
	case heart:
		wcout << L"\u2665";
		break;
	case diamond:
		wcout << L"\u2666";
		break;
	case club:
		wcout << L"\u2663";
		break;
	}
	_setmode(_fileno(stdout), _O_TEXT);
	cout << "]";
}