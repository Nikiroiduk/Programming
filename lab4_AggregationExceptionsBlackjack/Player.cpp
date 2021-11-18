#include "Player.h"

Player::Player() {}

Player::Player(const string& name, int money) {
	_name = name;
	_money = money;
}

vector<Card> Player::getHand() const {
	return _hand;
}

int Player::getMoney()  const {
	return _money;
}

int Player::getStake() const {
	return _stake;
}

void Player::setStake(int stake) {
	_stake = stake;
}

void Player::addCard(Card card) {
	_hand.push_back(card);
}

void Player::clearHand() {
	_hand.clear();
}
