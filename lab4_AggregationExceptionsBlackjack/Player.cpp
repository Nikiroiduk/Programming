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

vector<Card> Player::getSecondHand() const {
	return _secondHand;
}

int Player::getMoney()  const {
	return _money;
}

int Player::getStake() const {
	return _stake;
}

void Player::setStake(int stake) {
	_money -= stake;
	_stake = stake;
}

void Player::addCard(Card card) {
	_hand.push_back(card);
}

void Player::addSecondCard(Card card) {
	_secondHand.push_back(card);
}

Card Player::getCard() {
	Card tmp = _hand.back();
	_hand.pop_back();
	return tmp;
}

void Player::addMoney(int money) {
	_money += money;
}

void Player::setHand(vector<Card> hand) {
	_hand = hand;
}

void Player::setSecondHand(vector<Card> hand) {
	_secondHand = hand;
}

void Player::clearHand() {
	_hand.clear();
}

void Player::clearSecondHand() {
	_secondHand.clear();
}


