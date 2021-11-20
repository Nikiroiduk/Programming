#include "GameController.h"
#include "ConsoleView.h"

GameController::GameController() {
	_game = Game();
	launch();
}

vector<Card> GameController::getRandomHand() {
	//TODO: Fix random generator (this thing doesn't work)
	auto result = vector<Card>();
	for (int i = 0; i < 2; ++i) {
		srand(i + time(0));	
		auto tmp = vector<Card>();
		for (auto item : _game.getDecks()) {
			tmp.push_back(item.getRandomCard());
		}
		int rnd = rand() % tmp.capacity();
		result.push_back(tmp[rnd]);
	}
	return result;
}

void GameController::launch() {
	_game.setDecks(vector<Deck>(3));

	auto name = ConsoleView::InputPlayerName();
	auto money = ConsoleView::InputPlayerMoney();


	//TODO: Fix konstantin: (*(xxxxx))
	_game.setPlayer(name, money);
	auto player = _game.getPlayer();
	(*(player)).setHand(getRandomHand());

	_game.setDealer("Dealer", 1000);
	auto dealer = _game.getDealer();
	(*(dealer)).setHand(getRandomHand());

	auto playerInfo = _game.getPlayer();
	ConsoleView::PrintPlayerInfo((*(playerInfo)));
	ConsoleView::PrintTable(_game);
}