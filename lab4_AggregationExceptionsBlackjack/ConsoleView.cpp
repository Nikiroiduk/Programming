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