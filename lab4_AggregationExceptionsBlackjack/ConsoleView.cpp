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

void ConsoleView::PrintTable(Game& game, bool& isGameOver, bool& isSplited) {
	auto player = game.getPlayer();
	auto dealer = game.getDealer();

	auto playerHand = player->getHand();
	auto dealerHand = dealer->getHand();

	cout << "\nDealer hand: ";
	cout << dealerHand[0];
	if (isGameOver) {
		for (int i = 1; i < dealerHand.capacity(); ++i) {
			cout << dealerHand[i];
		}
	}
	else {
		cout << "[  ]";
	}
	cout << "\n" << player->getName() << " hand: ";
	for (auto item : playerHand) {
		cout << item;
	}
	if (isSplited) {
		cout << " ";
		for (auto item : player->getSecondHand()) {
			cout << item;
		}
	}
	//TODO: Logic of displaying the second card at the dealer
}

void ConsoleView::Print(const string& string) {
	cout << string << "\n";
}

ostream& operator<<(ostream& out, const Card& card) {
	auto rank = card._rank;
	auto suit = card._suit;
	string suits[] = { "\x03", "\x04", "\x05", "\x06" };

	cout << "[";
	switch (rank)
	{
	case jack:
		out << "J";
		break;
	case queen:
		out << "Q";
		break;
	case king:
		out << "K";
		break;
	case ace:
		out << "A";
		break;
	default:
		out << rank;
		break;
	}
	out << suits[static_cast<int>(card._suit)];
	out << "]";
	return out;
};

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


