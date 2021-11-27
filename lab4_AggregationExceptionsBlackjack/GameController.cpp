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
		//Test [J][J]
		//result.push_back(Card(11, 2 + i));
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
	//auto player = _game.getPlayer();
	//player->setHand(getRandomHand());

	_game.setDealer("Dealer", 0);
	//auto dealer = _game.getDealer();
	//dealer->setHand(getRandomHand());

	//auto playerInfo = _game.getPlayer();
	//ConsoleView::PrintPlayerInfo(*playerInfo);
	//ConsoleView::PrintTable(_game);
	//ConsoleView::Print("That's all...");
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
		dealer->setHand(getRandomHand());

		//TODO: Game
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
	auto isSplited = false;
	auto pts = 0;
	bool hand = true;

	while (!gameOver) {
		ConsoleView::PrintTable(_game, gameOver, isSplited);
		answer = ConsoleView::InputGameAction(isSplit);
		hand = isSplited ? !hand : hand;
		switch (answer)
		{
			case 1:
				//Hit
				//TODO: Split logic
				hand ? player->addCard(getRandomCard()) : player->addSecondCard(getRandomCard());
				try {
					if (countPoints(player->getHand()) > 21)
						throw exception("Bust");
				}
				catch (exception exc) {
					gameOver = true;
					ConsoleView::PrintTable(_game, gameOver, isSplited);
					ConsoleView::Print("\nIt's bust, you lost " + to_string(player->getStake()) + "!");
				}
			break;
			case 2:
				//Stand
				//TODO: Split logic
				pts = countPoints(dealer->getHand());
				while (pts <= 16) {
					dealer->addCard(getRandomCard());
					pts = countPoints(dealer->getHand());
				}

				gameOver = true;
				ConsoleView::PrintTable(_game, gameOver, isSplited);

				if (pts < countPoints(player->getHand()) || pts > 21) {
					player->addMoney(player->getStake() * 2);
					ConsoleView::Print("\nCongrats! You win and get " + to_string(player->getStake() * 2));
				}
				else if (pts == countPoints(player->getHand())) {
					player->addMoney(player->getStake());
					ConsoleView::Print("\nDraw");
				}
				else {
					ConsoleView::Print("\nYou lose!");
				}
			break;
			case 3:
				isSplited = true;
				if (isSplit) {
					Card tmp = player->getCard();
					player->addSecondCard(tmp);
					player->addSecondCard(getRandomCard());
					player->addCard(getRandomCard());
				}
				else {
					ConsoleView::Print("Mmmm?!");
				}
			break;
		}
		isSplit = false;
	}
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

