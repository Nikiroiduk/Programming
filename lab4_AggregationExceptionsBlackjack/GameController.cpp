#include "GameController.h"
#include "ConsoleView.h"

GameController::GameController() {
	_game = Game();
	launch();
}


void GameController::launch() {
	auto name = ConsoleView::InputPlayerName();
	auto money = ConsoleView::InputPlayerMoney();

	_game.setPlayer(name, money);
}