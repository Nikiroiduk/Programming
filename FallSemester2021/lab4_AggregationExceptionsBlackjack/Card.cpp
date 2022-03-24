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

int Card::getValue() {
	return _value;
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
}

