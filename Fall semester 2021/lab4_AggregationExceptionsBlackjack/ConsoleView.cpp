#include "ConsoleView.h"

string ConsoleView::InputPlayerName() {
	string name;
	cout << "Input your name: ";
	cin >> name;
	return name;
}

int ConsoleView::InputPlayerMoney() {
	int money;
	cout << "Amount of money: ";
	cin >> money;
	return money;
}

int ConsoleView::InputPlayerStake() {
	int stake;
	cout << "Your stake?: ";
	cin >> stake;
	return stake;
}

void ConsoleView::PrintPlayerInfo(const Player& player) {
	cout << "\nYour money: " << player.getMoney() << "\n";
}

void ConsoleView::PrintTable(Game& game, bool& isGameOver) {
	auto player = game.getPlayer();
	auto dealer = game.getDealer();

	auto playerHand = player->getHand();
	auto dealerHand = dealer->getHand();

	cout << "\nDealer hand: ";
	cout << dealerHand[0];
	if (isGameOver) {
		for (auto item : dealerHand) {
			cout << item;
		}
	}
	else {
		cout << "[  ]";
	}
	cout << "\n" << player->getName() << " hand: ";
	for (auto item : playerHand) {
		cout << item;
	}
}

void ConsoleView::Print(const string& string) {
	cout << string << "\n";
}



string ConsoleView::InputPlayerAnswer() {
	string answer = "n";
	cout << "Play again? (y/n): ";
	cin >> answer;
	return answer;
}

int ConsoleView::InputGameAction(bool& state) {
	auto answer = -1;

	cout << (state ? "\n1. Hit\n2. Stand\n3. Split\n" : "\n1. Hit\n2. Stand\n");
	cin >> answer;
	return answer;
}

void ConsoleView::PrintSplitedTable(Game& game, bool& isGameOver) {
	auto player = game.getPlayer();
	auto dealer = game.getDealer();

	auto playerHand = player->getHand();
	auto playerSecondHand = player->getSecondHand();
	auto dealerHand = dealer->getHand();

	cout << "\nDealer hand: ";
	cout << dealerHand[0];
	if (isGameOver) {
		for (auto item : dealerHand) {
			cout << item;
		}
	}
	else {
		cout << "[  ]";
	}
	cout << "\n" << player->getName() << " hand: ";
	for (auto item : playerHand) {
		cout << item;
	}
	cout << "  ";
	for (auto item : playerSecondHand) {
		cout << item;
	}
}


