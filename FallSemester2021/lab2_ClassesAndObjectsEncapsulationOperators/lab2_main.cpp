﻿#include "Vector.h"
#include "Fraction.h"
#include "Conditioner.h"
#include <stdio.h>

void Exercise1() {
	printf("Exercise 1\n");

	Vector* vec = new Vector(18);
	(*vec).print();
	(*vec).sort();
	(*vec).print();
	++(*vec);
	(*vec).print();
	--(*vec);
	(*vec).print();
	(*vec)--;
	(*vec).print();
	(*vec)++;
	(*vec).print();
	Matrix mat = (*vec).convertToMatrix(2, 9);
	mat.print();
	mat++;
	mat.print();
	mat--;
	mat.print();
	(++mat).print();
	(--mat).print();
}

	int	Fraction::counter = 0;
void Exercise2() {
	printf("\n\nExercise 2");


	Fraction x(0.05);
	Fraction y(.2);
	Fraction a(.0004);
	Fraction b(10.05);

	y.reduce();					// 1/5
	a.reduce();					// 1/2500
	b.reduce();					// 10 1/20

	x.printAsFraction(2.3231);  // 2 3231/10000
	x.printAsFraction();		// 5/100
	x.reduce();
	x.printAsFraction();		// 1/20

	char t[] = "3.14";
	x.printAsFraction(t);		//3 14/100

	Fraction d = (x + y);
	d.printAsFraction();		// 25/100
	d.reduce();
	d.printAsFraction();		// 1/4

	Fraction e = (x - y);
	e.printAsFraction();		// -15/100
	e.reduce();
	e.printAsFraction();		// 3/-20

	Fraction i = (x * y);
	i.printAsFraction();		// 1/100
	i.reduce();
	i.printAsFraction();		// 1/100

	Fraction h = (x / y);
	h.printAsFraction();		// 25/100
	h.reduce();
	h.printAsFraction();		// 1/4

	printf("\n\nAmountOfElements Fraction: %d", Fraction::counter);
}

void Exercise3() {
	printf("\n\nExercise 3\n");
	Conditioner* conditionerHeap_1 = new Conditioner("Nord", "DBL_2875", 50, 21, 0, "2007");
	Conditioner* conditionerHeap_2 = new Conditioner("Bombass", "ASdk", 88, 31, 1, "1997");

	Conditioner conditionerStack;
	conditionerStack.setFirm("Nord");
	conditionerStack.setMass(50);
	conditionerStack.setModel("DBL_44");
	conditionerStack.setReleaseYear("2008");
	conditionerStack.setState(1);
	conditionerStack.setTemp(30);


	conditionerHeap_1->printState();
	conditionerHeap_2->printState();
	conditionerStack.printState();

	conditionerHeap_1->mode(1, 31);
	conditionerHeap_1->mode(1, 29);
	conditionerHeap_1->mode(0, 22);
	conditionerHeap_1->mode(0, 20);
	conditionerHeap_1->printState();

	conditionerHeap_1->serialize();
	conditionerHeap_1->deserialize();


	conditionerHeap_1->serialize("test.txt");
	conditionerHeap_1->deserialize("test.txt");

	delete conditionerHeap_1;
	delete conditionerHeap_2;
}

int main() {
	/*
	Написать классы Vector и Matrix для хранения и обработки одномерных и
	двумерных массивов, соответственно.Реализовать задание 2 лабораторной работы №1
	с помощью созданных классов.Все функции оформить в виде методов классов.
	В коде отразить следующее :
	- Выделение и освобождение динамической памяти производить в конструкторах и
	деструкторах классов, соответственно.
	- В классе Vector перегрузить оператор индексации[].В классе Matrix добавить
	методы T at(int i, int j) const и setAt(int i, int j, T val), которые
	позволяют получить и установить значение элемента массива с индексом[i][j], T –
	это тип элементов массива по варианту(int или double).
	- Перегрузить операторы инкремента и декремента(как префиксного, так и
	постфиксного).Смысл инкремента / декремента всего массива заключается в
	инкременте / декременте каждого элемента массива.
	*/
	Exercise1();

	/*
	Написать класс Fraction для представления обыкновенных дробей(как отношения
	двух целых чисел x / y).Перегрузить операторы + , -, *, / для дробей.Реализовать метод
	void reduce() для сокращения дроби, а также статические методы :
	- int gcd(int n, int m)
	функция для нахождения наибольшего общего делителя чисел n и m;
	- void printAsFraction(double decimal_fraction)
	- void printAsFraction(char* decimal_fraction)
	перегруженные методы вывода десятичной дроби в виде обыкновенной
	(например, при значении decimal_fraction = 0.43 на экране должно
		вывестись 43 / 100, при 0.25 – 1 / 4 и т.д.).
	Также реализовать в виде статического члена класса счетчик всех созданных на
	данный момент в программе экземпляров дробей.
	Продемонстрировать работу созданного класса.Создать несколько объектов дробей.
	Произвести операции сложения, вычитания, умножения и деления дробей.Вывести
	на экран результаты.Показать также результаты работы статических методов класса.
	*/
	Exercise2();

	/*
	Написать собственный класс, в соответствии с вариантом.Продемонстрировать в коде
	инкапсуляцию данных, применение конструкторов без параметров и с параметрами
	для инициализации данных.Класс должен содержать метод serialize() для
	сохранения данных класса в файл и метод deserialize() для чтения данных класса
	из файла по умолчанию в текущей директории, а также перегруженные методы
	serialize(const std::string & filename) и deserialize(const std::string &
	filename) для работы с файлом с указанным в параметре именем.

	Вариант №5
	Класс КОНДИЦИОНЕР.
	Данные: фирма, модель, вес, температура, режим, год выпуска.
	Создать 2 кондиционера в куче и проинициализировать их с помощью конструкторов с
	параметрами. Еще один кондиционер создать отдельно в стеке и установить его данные
	с помощью сеттеров. В главной функции проимитировать настройку кондиционеров
	персоналом помещений – установить каждому режим; если выбран режим охлаждения,
	то установить также температуру. Проделать эту процедуру три раза. Вывести
	информацию об использовании кондиционеров – режим, в котором на данный момент
	работает техника, среднее изменение температуры за весь период настройки.
	*/
	Exercise3();

	return 0;
}