#include "DataManager.h"
template DataManager<int>;
template DataManager<double>;
template DataManager<char>;

char DataManager<char>::popLower() {
	return tolower(pop());
}

char DataManager<char>::popUpper() {
	return toupper(pop());
}

void DataManager<char>::push(char elem) {
	bool test = false;
	for (auto item : pMks) {
		if (item == elem) {
			test = true;
			break;
		}
	}
	test ? data.push_front('_') : data.push_front(elem);
}

template <typename T>
void DataManager<T>::push(T elem) {
	if (data.size() == 64) writeToDump();
	data.push_front(elem);
}

template <typename T>
void DataManager<T>::push(T elems[], size_t n) {
	if (data.size() + n > 64) {
		writeToDump();
	}
	for (int i = 0; i < n; ++i) {
		data.push_front(elems[i]);
	}
}

template <typename T>
T DataManager<T>::peek() {
	auto size = data.size();
	return size % 2 == 0 ? data[0] : data[(int)(size / 2)];
}

template <typename T>
T DataManager<T>::pop() {
	auto size = data.size();
	if (size == 1) {
		auto tmp = data[0];
		data.clear();
		loadFromDump();
		return tmp;
	}
	else {
		auto index = (int)(size / 2);
		index = size % 2 == 0 ? --index : index;
		auto tmp = data[index];
		data.erase(data.begin() + index, data.begin() + index + 1);
		return tmp;
	}
}

template <typename T>
void DataManager<T>::writeToDump() {

	ofstream dump;
	dump.open("dump.dat", ofstream::in);

	if (dump.is_open()) {
		for (auto item : data) {
			dump << std::to_string(item) + "\n";
		}
	}

	dump.close();
	data.clear();
}

//TODO: check if dump isn't empty
template <typename T>
T DataManager<T>::loadFromDump() {
	ifstream dump;
	T line;
	dump.open("dump.dat", ifstream::in);

	if (dump.is_open()) {
		while (dump >> line) {
			line = line;
		}
		data.push_front(line);
	}

	dump.close();
	return 0;
}

