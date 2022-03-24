#pragma once
#include "Deck.h"
#include "IFormattable.h"

using std::string;
using std::to_string;

class DeckObjectAdapter : public IFormattable
{
private:
	Deck deck = Deck();
public:
	string format() override;
};

