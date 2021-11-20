#include "Player.h"

Player::Player() {}

Player::Player(const string& name, int money) {
	_name = name;
	_money = money;
}

Player* Player::get() {
	return this;
}

string Player::getName() const {
	return _name;
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

void Player::setHand(vector<Card> hand) {
	_hand = hand;
}

void Player::clearHand() {
	_hand.clear();
}
