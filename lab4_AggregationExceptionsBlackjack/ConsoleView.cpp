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
	cout << "\nPlayer name: " << player.getName() << "\n";
	cout << "Player money: " << player.getMoney() << "\n";
}

void ConsoleView::printCard(Card& card) {
	auto rank = card.getRank();
	auto suit = card.getSuit();

	cout << "[";
	switch (rank)
	{
	case jack:
		cout << "J";
		break;
	case queen:
		cout << "Q";
		break;
	case king:
		cout << "K";
		break;
	case ace:
		cout << "A";
		break;
	default:
		cout << rank;
		break;
	}
	_setmode(_fileno(stdout), _O_U16TEXT);
	switch (suit)
	{
	case spade:
		wcout << L"\u2660";
		break;
	case heart:
		wcout << L"\u2665";
		break;
	case diamond:
		wcout << L"\u2666";
		break;
	case club:
		wcout << L"\u2663";
		break;
	}
	_setmode(_fileno(stdout), _O_TEXT);
	cout << "]";
}

void ConsoleView::PrintTable(Game& game) {
	auto player = game.getPlayer();
	auto dealer = game.getDealer();

	cout << "\n" << player->getName() << " hand: ";
	printCard(player->getHand()[0]);
	printCard(player->getHand()[1]);
	cout << "\nDealer hand: ";
	printCard(player->getHand()[0]);
	printCard(player->getHand()[1]);
}
