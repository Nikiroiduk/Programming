#include <iostream>;
#include <cmath>;
#include <cstring>;

void print1DArray(int* array, int length) {
	std::cout << "\n";
	std::cout << "[";
	for (int i = 0; i < length; i++) {
		std::cout << *(array + i) << ((i == length - 1) ? "" : " ");
	}
	std::cout << "]";
}

void print2DArray(int** array, int width, int height) {
	std::cout << "\n";
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			std::cout.width(5);
			std::cout << *(*(array + i) + j);
		}
		std::cout << "\n";
	}
}

void processArray(int arr[], int length, int* count, int* result) {
	std::fill(arr, arr + length, 1);

	int tens = 0;
	for (int i = 0, two = 0, three = 0, resultArrElement = 0; i < length; i++) {
		arr[i] = (i % 2 == 0 ? pow(2, ++two) : pow(3, ++three));
		if (arr[i] > 9 && arr[i] < 100) {
			result[resultArrElement] = arr[i];
			resultArrElement++;
			tens++;
		}
	}

	*count = tens;
}

void exercise_1() {
	std::cout << "Exercise 1";

	const int length = 16;

	int array[length] = {};
	int count = 0;
	int result[length] = {};
	processArray(array, length, &count, result);

	print1DArray(array, length);
	print1DArray(result, count);
	std::cout << "\ncount = " << count;
}

void createArray(int* array, int length) {
	for (int i = 0; i < length; i++) {
		*(array + i) = ((i + 1) % 2 == 0 ? -(pow(i, 2) + 1) : pow(i, 2) + 1);
	}
}

void sort(int* arr, int size)
{
	int i, key, j;
	for (i = 1; i < size; i++)
	{
		key = *(arr + i);
		j = i - 1;

		while (j >= 0 && *(arr + j) < key)
		{
			*(arr + (j + 1)) = *(arr + j);
			j = j - 1;
		}
		*(arr + (j + 1)) = key;
	}
}

int** convert1Dto2D(int* array, int length, int width, int height) {
	int** resultArray = new int* [(height)];
	for (int i = 0; i < height; i++) {
		*(resultArray + i) = new int[(width)];
	}

	for (int i = 0, count = 0; i < height; i++) {
		for (int j = 0; j < width; j++, count++) {
			*(*(resultArray + i) + j) = *(array + count);
		}
	}

	return resultArray;
}

void exercise_2() {
	std::cout << "\n\nExercise 2";
	const int length = 18;
	const int width = 2;
	const int height = 9;


	int* array = new int[(length)];
	createArray(array, length);
	print1DArray(array, length);

	sort(array, length);
	int** array2D = convert1Dto2D(array, length, width, height);

	printf("\n=>");
	print2DArray(array2D, height, width);

	delete[] array;

	for (int i = 0; i < height; i++) {
		delete[] array2D[i];
	}
	delete[] array2D;
}

char* strcpyCopy(char* dest, const char* src) {
	char* temp = dest;
	while ((*dest++ = *src++) != '\0');

	return temp;
}

//Не костыль
char* unconstchar(const char* s) {
	if (!s)
		return NULL;
	int i;
	char* res = NULL;
	res = (char*)malloc(strlen(s) + 1);
	if (!res) {
		fprintf(stderr, "Memory Allocation Failed! Exiting...\n");
		exit(EXIT_FAILURE);
	}
	else {
		for (i = 0; s[i] != '\0'; i++) {
			res[i] = s[i];
		}
		res[i] = '\0';
		return res;
	}
}

void strcpyTest(const char* dest, const char* src) {
	std::cout.width(30);
	std::cout.fill('.');
	std::cout << "\ndest: " << dest << std::endl;
	std::cout << "src: " << src << std::endl;
	std::cout << "Original strcpy: " << strcpy(unconstchar(dest), src) << std::endl;
	std::cout << "My strcpy: " << strcpyCopy(unconstchar(dest), src) << std::endl;
};

void exercise_3() {
	std::cout << "\nExercise 3\n";

	strcpyTest("Word", "Hole");
	strcpyTest("Hello, World!", "Bye!");
	strcpyTest("Hell", "Hello!");
	strcpyTest("\0hmmm", "ok");
	strcpyTest("", "emptyDest");
}

int main() {
	/*
	Объявить массив из n = 16 целых чисел, проинициализировать единицами.
	Функция processArray() должна заполнить элементы массива с четными индексами
	степенями двойки(1, 2, 4, 8, 16, …), с нечетными индексами – степенями
	тройки(3, 9, 27, …).Также подсчитать и вернуть count – количество двузначных чисел в массиве и
	сформировать выходной массив, содержащий только такие числа. Вывести на экран
	результирующие массивы.
	*/
	exercise_1();

	/*
	Преобразование: 1D → 2D. Одномерный массив из 18 целых чисел необходимо
	отсортировать в порядке убывания и разложить по двумерной сетке 9х2 слева направо и
	сверху вниз.
	Инициализация: заполнить массив числами x[i] = i
	2+1 и все элементы с четными
	индексами домножить на -1.
	Вывод на экран: на каждый элемент массива отвести 5 позиций.
	*/
	exercise_2();

	/*
	Функция strcpy.
	Формат char* strcpy(char* dest, const char* src).
	Функция копирует строку src в строку dest.
	*/
	exercise_3();

	return 0;
}