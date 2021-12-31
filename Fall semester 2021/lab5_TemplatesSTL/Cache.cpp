#include "Cache.h"
template Cache<int>;

template <typename T>
T Cache<T>::operator+=(const T& elem) {
	data.push_back(elem);
	return (T)0;
}

template <typename T>
void Cache<T>::put(T elem) {
	data.push_back(elem);
}

template <typename T>
bool Cache<T>::contains(T elem) {
	return find(data.begin(), data.end(), elem) != data.end();
}

template <>
string Cache<string>::operator+=(const string& elem) {
	data.push_back(elem);
	return "";
}

template <>
void Cache<string>::put(string elem) {
	try {
		if (data.size() >= 100) throw("Overflow exception");
	}
	catch (exception exc) {
		cout << "Cache caused an exception";
		return;
	}
	data.push_back(elem);
}

template <>
bool Cache<string>::contains(string elem) {
	StringFinder sf(elem.at(0));
	return find_if(data.begin(), data.end(), sf) != data.end();
}


