#include "Card.h"

Card::Card(int rank, int suit) {
	_suit = suit;
	_rank = rank;
	_value = getCardValue();
}

int Card::getRank() {
	return _rank;
}

int Card::getSuit() {
	return _suit;
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

bool Card::operator==(const Card& card1) {
	if (this->_rank == card1._rank && this->_suit == card1._suit)
		return true;
	return false;
};

//ostream& Card::operator<<(ostream& out, const Card& card) {
//	out << "[";
//
//	switch (card._rank)
//	{
//	case jack:
//		out << "J";
//		break;
//	case queen:
//		out << "Q";
//		break;
//	case king:
//		out << "K";
//		break;
//	case ace:
//		out << "A";
//		break;
//	default:
//		out << _rank;
//		break;
//	}
//	_setmode(_fileno(stdout), _O_U16TEXT);
//	switch (_suit)
//	{
//	case spade:
//		out << L"\u2660";
//		break;
//	case heart:
//		out << L"\u2665";
//		break;
//	case diamond:
//		out << L"\u2666";
//		break;
//	case club:
//		out << L"\u2663";
//		break;
//	}
//	_setmode(_fileno(stdout), _O_TEXT);
//
//	out << "]";
//	
//	return out;
//}