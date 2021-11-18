#include "Game.h"
#include "Player.h"
#include <iostream>


void Game::setPlayer(const std::string& name, int money) {
	_player = Player(name, money);
}

Player Game::getPlayer() const {
	return _player;
}

void Game::setDealer(const std::string& name, int money) {
	_dealer = Player(name, money);
}

Player Game::getDealer() const {
	return _dealer;
}

vector<Deck> Game::getDecks() const {
	return _decks;
}

void Game::setDecks(vector<Deck> decks) {
	_decks = decks;
}