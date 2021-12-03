#include "GameController.h"
#include "ConsoleView.h"

GameController::GameController() {
	srand(time(0));
	_game = Game();
	_minStake = 100;
	launch();
}

vector<Card> GameController::getRandomHand() {
	auto result = vector<Card>();
	for (int i = 0; i < 2; ++i) {
		result.push_back(getRandomCard());
	}
	return result;
}

Card GameController::getRandomCard() {
	auto tmp = vector<Card>();
	for (auto item : _game.getDecks()) {
		tmp.push_back(item.getRandomCard());
	}
	int rnd = rand() % tmp.capacity();
	return tmp[rnd];
}

void GameController::launch() {

	auto name = ConsoleView::InputPlayerName();
	auto money = ConsoleView::InputPlayerMoney();
	if (money < 100) {
		ConsoleView::Print("You have " + to_string(money) + ", but you need > 100!");
		return;
	}

	_game.setDecks(vector<Deck>(3));
	_game.setPlayer(name, money);

	_game.setDealer("Dealer", 0);
	start();
}

void GameController::start() {
	auto player = _game.getPlayer();
	auto dealer = _game.getDealer();

	string answer = "y";
	while (answer == "y") {
		auto stake = ConsoleView::InputPlayerStake();
		while (stake < _minStake || stake > player->getMoney()) {
			if (stake < _minStake) {
				ConsoleView::Print("Your stake must be at least 100!");
			}
			if (stake > player->getMoney()) {
				ConsoleView::Print("Your stake can't be higher then " + to_string(player->getMoney()) + "!");
			}
			stake = ConsoleView::InputPlayerStake();
		}

		player->setStake(stake);

		player->setHand(getRandomHand());
		player->clearSecondHand();
		dealer->setHand(getRandomHand());

		game();

		ConsoleView::PrintPlayerInfo(*player);
		if (player->getMoney() < _minStake) {
			ConsoleView::Print("You don't have enough money to continue playing!");
			return;
		}

		answer = ConsoleView::InputPlayerAnswer();
	}
}


void GameController::game() {
	auto gameOver = false;
	auto answer = -1;
	auto player = _game.getPlayer();
	auto dealer = _game.getDealer();
	bool isSplit = isSplitable();
	auto pts = 0;

	while (!gameOver) {	
		ConsoleView::PrintTable(_game, gameOver);
		answer = ConsoleView::InputGameAction(isSplit);
		switch (answer)
		{
		case 1:
			player->addCard(getRandomCard());
			try {
				if (countPoints(player->getHand()) > 21)
					throw exception("Bust");
			}
			catch (exception exc) {
				gameOver = true;
				ConsoleView::PrintTable(_game, gameOver);
				ConsoleView::Print("\nIt's bust, you lost " + to_string(player->getStake()) + "!");
			}
			break;
		case 2:
			pts = countPoints(dealer->getHand());
			while (pts <= 16) {
				dealer->addCard(getRandomCard());
				pts = countPoints(dealer->getHand());
			}

			gameOver = true;
			ConsoleView::PrintTable(_game, gameOver);

			if (pts < countPoints(player->getHand()) || pts > 21) {
				player->addMoney(player->getStake() * 2);
				ConsoleView::Print("\nCongrats! You win and get " + to_string(player->getStake() * 2));
			}
			else if (pts == countPoints(player->getHand())) {
				player->addMoney(player->getStake());
				ConsoleView::Print("\nDraw!");
			}
			else {
				ConsoleView::Print("\nYou lose!");
			}
			break;
		case 3:
			if (isSplit && player->getMoney() >= player->getStake() * 2) {
				if (splitedGame()) gameOver = true;
			}
			else {
				ConsoleView::Print("Mmmm?!");
			}
			break;
		default:
			continue;
			break;
		}
		isSplit = false;
	}
}

bool GameController::splitedGame() {
	bool firstHandGameOver = false;
	bool secondHandGameOver = false;
	int firstHandState = -1;
	int secondHandState = -1;
	int pts = 0;
	bool isSplit = false;
	bool fls = false;
	auto player = _game.getPlayer();
	auto dealer = _game.getDealer();
	auto answer = -1;

	Card tmp = player->getCard();
	player->addSecondCard(tmp);
	player->addSecondCard(getRandomCard());
	player->addCard(getRandomCard());
	player->setStake(player->getStake());

	while (!firstHandGameOver){
		ConsoleView::PrintSplitedTable(_game, fls);
		answer = ConsoleView::InputGameAction(isSplit);
		switch (answer)
		{
		case 1:
			player->addCard(getRandomCard());
			try {
				if (countPoints(player->getHand()) > 21)
					throw exception("Bust");
			}
			catch (exception exc) {
				firstHandGameOver = true;
				ConsoleView::PrintSplitedTable(_game, fls);
				ConsoleView::Print("\nIt's bust, you lost " + to_string(player->getStake()) + "!");
			}
			break;
		case 2:
			firstHandGameOver = true;
			pts = countPoints(dealer->getHand());
			while (pts <= 16) {
				dealer->addCard(getRandomCard());
				pts = countPoints(dealer->getHand());
			}

			if (pts < countPoints(player->getHand()) || pts > 21) {
				firstHandState = 1;
				player->addMoney(player->getStake() * 2);
			}
			else if (pts == countPoints(player->getHand())) {
				firstHandState = 2;
				player->addMoney(player->getStake());
			}
			else {
				firstHandState = 0;
			}
			break;
		default:
			continue;
			break;
		}
	}
	while (!secondHandGameOver) {
		ConsoleView::PrintSplitedTable(_game, fls);
		answer = ConsoleView::InputGameAction(isSplit);
		switch (answer)
		{
		case 1:
			player->addSecondCard(getRandomCard());
			try {
				if (countPoints(player->getSecondHand()) > 21)
					throw exception("Bust");
			}
			catch (exception exc) {
				secondHandGameOver = true;
				ConsoleView::PrintSplitedTable(_game, fls);
				ConsoleView::Print("\nIt's bust, you lost " + to_string(player->getStake()) + "!");
			}
			break;
		case 2:
			secondHandGameOver = true;

			pts = countPoints(dealer->getHand());
			while (pts <= 16) {
				dealer->addCard(getRandomCard());
				pts = countPoints(dealer->getHand());
			}

			if (pts < countPoints(player->getSecondHand()) || pts > 21) {
				secondHandState = 1;
				player->addMoney(player->getStake() * 2);
			}
			else if (pts == countPoints(player->getSecondHand())) {
				secondHandState = 2;
				player->addMoney(player->getStake());
			}
			else {
				secondHandState = 0;
			}
			break;
		default:
			continue;
			break;
		}
	}

	ConsoleView::PrintSplitedTable(_game, firstHandGameOver);
	switch (firstHandState)
	{
	case 0:
		ConsoleView::Print("You first hand lose!");
		break;
	case 1:
		ConsoleView::Print("Congrats! You first hand win and get " + to_string(player->getStake() * 2));
		break;
	case 2:
		ConsoleView::Print("First hand draw!");
		break;
	}

	switch (secondHandState)
	{
	case 0:
		ConsoleView::Print("You second hand lose!");
		break;
	case 1:
		ConsoleView::Print("Congrats! You second hand win and get " + to_string(player->getStake() * 2));
		break;
	case 2:
		ConsoleView::Print("Second hand draw!");
		break;
	}

	return true;
}

int GameController::countPoints(vector<Card> hand) {
	auto sum = 0;
	for (auto item : hand) {
		sum += item.getValue();
	}
	return sum;
}

bool GameController::isSplitable() {
	auto hand = _game.getPlayer()->getHand();

	if (hand[0].getRank() == hand[1].getRank()) {
		return true;
	}
	return false;
}

