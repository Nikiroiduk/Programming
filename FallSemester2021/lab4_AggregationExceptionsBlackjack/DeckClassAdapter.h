#pragma once
#include "Deck.h"
#include "IFormattable.h"

using std::string;
using std::to_string;

class DeckClassAdapter : public Deck, public IFormattable
{
public:
	string format() override;
};

