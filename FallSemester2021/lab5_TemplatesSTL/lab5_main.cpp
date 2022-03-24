#include <iostream>
#include <vector>
#include <ranges>
#include <functional>
#include "DataManager.h"
#include "TextAnalyzer.h"
#include "Book.h"
#include "BookSorter.cpp"
#include "BookFinder.cpp"
#include "Cache.h"

using std::cout;
using std::endl;
using std::ostream_iterator;
using std::vector;
using std::sort;
using std::find_if;
using std::count_if;
using std::greater;
using std::bind2nd;

void Exercise1() {
	cout << "EXERCISE 1\n" << endl;
	DataManager<int> dmInt;
	DataManager<char> dmChar;
	DataManager<double> dmDouble;

	cout << "INT DATA MANAGER" << endl;
	dmInt.push(1);
	dmInt.push(2);
	dmInt.push(3);
	dmInt.push(4);
	dmInt.push(5);
	cout << dmInt << endl;
	cout << dmInt.peek() << " *peek*" << endl;
	cout << dmInt.pop() << " *pop*" << endl;
	cout << dmInt << endl;
	cout << dmInt.pop() << " *pop*" << endl;
	cout << dmInt << endl;
	int a[] = { 1, 2, 3, 4, 5 };
	dmInt.push(a, 5);
	cout << dmInt << endl;
	dmInt.push(88);
	cout << dmInt << endl;
	cout << dmInt.pop() << " *pop*" << endl;
	ostream_iterator<int>(cout << dmInt);

	cout << "\n\nCHAR DATA MANAGER" << endl;
	dmChar.push('a');
	dmChar.push('1');
	dmChar.push('c');
	dmChar.push(',');
	dmChar.push('\\');
	cout << dmChar << endl;
	cout << dmChar.popLower() << " *pop*" << endl;
	cout << dmChar << endl;
	cout << dmChar.popUpper() << " *pop*" << endl;
	ostream_iterator<int>(cout << dmChar);

	cout << "\n\nDOUBLE DATA MANAGER" << endl;
	dmDouble.push(1.1);
	dmDouble.push(2.2);
	dmDouble.push(3.3);
	dmDouble.push(4.4);
	cout << dmDouble << endl;
	cout << dmDouble.pop() << " *pop*" << endl;
	cout << dmDouble << endl;
	cout << dmDouble.peek() << " *peek*" << endl;
	cout << dmDouble.pop() << " *pop*" << endl;
	cout << dmDouble << endl;
	cout << dmDouble.pop() << " *pop*" << endl;
	cout << dmDouble << endl;
	cout << dmDouble.pop() << " *pop*" << endl;
	cout << dmDouble << "*loaded from dump*" << endl;
	ostream_iterator<int>(cout << dmDouble);
}

void Exercise2() {
	cout << "\n\nEXERCISE 2\n" << endl;
	auto analyze = TextAnalyzer("smallFile(200_Lines).txt");
	cout << analyze << endl;
}

void Exercise3() {
	cout << "EXERCISE 3\n" << endl;
	auto books = vector<Book>();
	books.push_back(Book("ULYSSES", "James Joyce", 1922));
	books.push_back(Book("THE GREAT GATSBY", "F. Scott Fitzgerald", 1925));
	books.push_back(Book("A PORTRAIT OF THE ARTIST AS A YOUNG MAN", "James Joyce", 1914));
	books.push_back(Book("LOLITA", "Vladimir Nabokov", 1955));
	books.push_back(Book("BRAVE NEW WORLD", "Aldous Huxley", 1932));
	books.push_back(Book("THE SOUND AND THE FURY", "William Faulkner", 1929));
	books.push_back(Book("CATCH-22", "Joseph Heller", 1961));
	books.push_back(Book("DARKNESS AT NOON", "Arthur Koestler", 1940));
	books.push_back(Book("SONS AND LOVERS", "D.H. Lawrence", 1913));

	cout << "BOOKS IN ALPHABETICAL ORDER" << endl;
	BookSorter bs;
	sort(books.begin(), books.end(), bs);
	for (auto item : books) {
		cout << item.getAuthor() << " - " << item.getName() << endl;
	}

	cout << "\nBOOKS IN RANGE" << endl;
	BookFinder bf(1900, 1920);
	vector<Book>::iterator finder = find_if(books.begin(), books.end(), bf);
	while (finder != books.end()) {
		cout << finder->getAuthor() << " - " << finder->getName() << endl;
		finder = std::find_if(++finder, books.end(), bf);
	}
}

void Exercise4() {
	cout << "\nEXERCISE 4\n" << endl;
	auto books = vector<Book>();
	books.push_back(Book("ULYSSES", "James Joyce", 1922));
	books.push_back(Book("THE GREAT GATSBY", "F. Scott Fitzgerald", 1925));
	books.push_back(Book("A PORTRAIT OF THE ARTIST AS A YOUNG MAN", "James Joyce", 1914));
	books.push_back(Book("LOLITA", "Vladimir Nabokov", 1955));
	books.push_back(Book("BRAVE NEW WORLD", "Aldous Huxley", 1932));
	books.push_back(Book("THE SOUND AND THE FURY", "William Faulkner", 1929));
	books.push_back(Book("CATCH-22", "Joseph Heller", 1961));
	books.push_back(Book("DARKNESS AT NOON", "Arthur Koestler", 1940));
	books.push_back(Book("SONS AND LOVERS", "D.H. Lawrence", 1913));

	cout << "NUMBER OF BOOKS PUBLISHED AFTER 1920" << endl;
	cout << count_if(books.begin(), books.end(), [](Book& b) {return b.getYear() >= 1920;}) << endl;
}

void Exercise5() {
	cout << "\nEXERCISE 5\n" << endl;
	Cache<int> cacheInt;
	Cache<string> cacheString;

	cacheInt.put(10);
	cacheInt.put(245);
	cacheInt.put(123);
	cacheInt.put(634);
	cacheInt += 22;
	cacheInt += 55;
	cacheInt += 88;
	cout << cacheInt << endl;
	cacheInt.contains(88) ? cout << "Cache contains number 88" << endl : cout << "Cache don't contain number 88";

	cacheString.put("Test");
	cacheString += "meh";
	cacheString += "meh1";
	cacheString += "meh2";
	cout << cacheString << endl;
	cacheString.contains("mmm") ? cout << "Cache contains string[0]==m" << endl : cout << "Cache don't contain string[0]==m";
}

int main() {
	/*
		Написать шаблонный класс DataManager<T> для специфической работы с набором 
		однотипных данных (максимальная вместимость равна 64 элементам). В набор можно 
		добавлять данные (метод push(T elem) для добавления одного элемента и метод 
		push(T elems[], size_t n) для добавления группы из n элементов), считывать без 
		извлечения (метод T peek()) и извлекать (метод T pop()) по некоторым алгоритмам 
		(в соответствии с вариантом, приложение А). Если набор заполнен на 100% и 
		поступает команда добавления нового элемента(ов), то данные полностью 
		выгружаются (дописываются) в специальный файл dump.dat, а сам массив очищается 
		и новые данные записываются уже в обновленный набор. Если из массива удаляется 
		последний элемент, то он заполняется ранее выгруженными в файл данными (если 
		файл не пуст).
		Необходимо также реализовать явную специализацию шаблонного класса для 
		символьного типа. В ней надо запрограммировать следующее: при добавлении 
		символа в набор все знаки пунктуации должны автоматически заменяться на символ 
		подчеркивания; добавить методы char popUpper() и char popLower(), которые 
		позволяют при извлечении символа из набора привести его к верхнему или нижнему 
		регистру, соответственно.
		В функции main() продемонстрировать применение шаблонного класса DataManager
		для типов int, double и char. Элементы контейнера должны выводиться на консоль с 
		помощью std::ostream_iterator.

		push(): данные пишутся в начало набора, остальные смещаются вправо;
		peek(): возвращает центральный элемент в наборе или 0, если число элементов четно;
		pop(): извлекает средний элемент из набора (если элементов четное число, то первый
		элемент слева от центра раздела набора).
	*/
	Exercise1();

	/*
		Написать код для чтения произвольного текстового файла и вывода на экран всех слов 
		размером более 3 букв, встречающихся в нем не менее 7 раз, в порядке убывания 
		частоты встречаемости (приложение А). В качестве разделителей слов рассматривать 
		пробел, точку, запятую, тире, двоеточие, восклицательный знак, точку с запятой. 
		Использовать контейнер std::map.
	*/
	Exercise2();

	/*
		Создать класс книги Book, в котором хранится название, автор и год издания книги. В 
		главной функции создать коллекцию книг (приложение А). Продемонстрировать 
		сортировку книг по автору (первичный ключ) и названию (вторичный ключ).
		Продемонстрировать поиск в коллекции: найти все книги, год издания которых 
		находится в указанном диапазоне. Использовать контейнер std::vector и функторы.
	*/
	Exercise3();

	/*
		Подсчитать и вывести на консоль количество всех книг новее 2005 года, используя 
		только стандартные алгоритмы и функторы STL (подcказка: std::count_if, 
		std::greater<>, std::bind2nd).
	*/
	Exercise4();

	/*
		Написать шаблонный класс кэша данных Cache<T> с методом добавления элемента в 
		кеш put(T elem) и его аналогом – оператором +=, а также методом проверки наличия 
		элемента в кеше bool contains(T elem). Написать явную специализацию шаблона 
		для типа std::string с такими нюансами: метод contains() должен возвращать true
		по совпадению первого символа строки; метод add() должен генерировать 
		исключение, если в кеше уже есть 100 строк. В главной функции инстанцировать 
		Cache с типами int и std::string, добавить в каждый несколько элементов и 
		продемонстрировать для каждого работу метода contains() (см. Приложение А).
	*/
	Exercise5();

	/*
		Модифицировать код игры «Блек-джек» из лабораторной работы № 4: использовать
		библиотеку STL для работы с коллекциями объектов.
	*/
	return 0;
}

