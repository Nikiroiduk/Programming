#pragma once
#include <string>
#include <vector>
#include "Card.h"

using std::string;
using std::vector;

class Player
{
private:
	string _name = "Undefined";
	vector<Card> _hand = vector<Card>();
	int _money = 0;
	int _stake = 0;
public:
	Player();
	Player(const string& name, int money);
	Player* get();
	void setStake(int stake);
	string getName() const;
	vector<Card> getHand() const;
	int getMoney() const;
	int getStake() const;
	void clearHand();
	void addCard(Card card);
	void setHand(vector<Card> hand);
};

