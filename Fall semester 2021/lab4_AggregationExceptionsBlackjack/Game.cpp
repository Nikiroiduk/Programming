#include "Game.h"
#include "Player.h"
#include <iostream>


void Game::setPlayer(const std::string& name, int money) {
	_player = Player(name, money);
}

Player* Game::getPlayer() {
	return _player.get();
}

void Game::setDealer(const std::string& name, int money) {
	_dealer = Player(name, money);
}

Player* Game::getDealer() {
	return _dealer.get();
}

vector<Deck> Game::getDecks() const {
	return _decks;
}

void Game::setDecks(vector<Deck> decks) {
	_decks = decks;
}

