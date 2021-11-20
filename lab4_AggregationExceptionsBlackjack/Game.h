#pragma once
#include "Player.h"
#include <string>
#include <vector>
#include "Deck.h"

using std::string;
using std::vector;

class Game
{
protected:
	Player _player;
	Player _dealer;
	vector<Deck> _decks;
public:
	Game() {};
	Player* getPlayer();
	void setPlayer(const string& name, int money = 0);
	Player* getDealer();
	void setDealer(const string& name, int money = 0);
	vector<Deck> getDecks() const;
	void setDecks(vector<Deck> decks);
};
