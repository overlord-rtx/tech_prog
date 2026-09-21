#include <algorithm>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <iterator>
#include <limits>
#include <random>
#include <vector>

// Проверка числа на простоту
bool isPrime(int number)
{
	if (number < 2)
	{
		return false;
	}

	for (int divisor = 2; divisor * divisor <= number; ++divisor)
	{
		if (number % divisor == 0)
		{
			return false;
		}
	}

	return true;
}

// Вывод элементов vector<int>
void printVector(const std::vector<int>& numbers)
{
	for (int number : numbers)
	{
		std::cout << number << ' ';
	}

	std::cout << std::endl;
}

// Задание а.
// возведение простые чисел в квадрат
void squarePrimes(std::vector<int>& numbers)
{
	std::transform(
		numbers.begin(),
		numbers.end(),
		numbers.begin(),
		[](int number)
	{
		if (isPrime(number))
		{
			return number * number;
		}

		return number;
	}
	);
}

// Задание b.
// сначала нечётные числа по возрастанию,
// затем чётные числа по убыванию
std::vector <int> sortOddEven(
	const std::vector <int> & numbers)
{
	std::vector<int> oddNumbers;
	std::vector<int> evenNumbers;

	std::copy_if(
		numbers.begin(),
		numbers.end(),
		std::back_inserter(oddNumbers),
		[] (int number)
	{
		return number % 2 != 0;
	}
	);


	std::copy_if(
		numbers.begin(),
		numbers.end(),
		std::back_inserter(evenNumbers),
		[] (int number)
	{
		return number % 2 == 0;
	}
	);


	std::sort(
		oddNumbers.begin(),
		oddNumbers.end()
	);

	std::sort(
		evenNumbers.begin(),
		evenNumbers.end(),
		std::greater<int>()
	);


	std::vector<int> result;

	result.insert(
		result.end(),
		oddNumbers.begin(),
		oddNumbers.end()
	);

	result.insert(
		result.end(),
		evenNumbers.begin(),
		evenNumbers.end()
	);

	return result;
}

// Задание c.
// поиск уникальных чисел в диапазоне [minValue, maxValue]
std::vector <int> uniqueInRange(
	const std::vector <int> & numbers,
	int minValue,
	int maxValue)
{
	std::vector<int> result;

	std::copy_if(
		numbers.begin(),
		numbers.end(),
		std::back_inserter(result),
		[minValue, maxValue] (int number)
	{
		return number >= minValue && number <= maxValue;
	}
	);

	std::sort(
		result.begin(),
		result.end()
	);

	result.erase(
		std::unique(
			result.begin(),
			result.end()
		),
		result.end()
	);

	return result;
}

int main()
{
	// установка кодировку UTF-8
	std::system("chcp 1251 > nul");


	std::random_device randomDevice;
	std::mt19937 generator(randomDevice() );
	std::uniform_int_distribution <int> distribution(1, 30);

	std::vector <int> numbers(10);

	std::generate(
		numbers.begin(),
		numbers.end(),
		[&generator, &distribution]()
	{
		return distribution(generator);
	}
	);

	std::cout << "Исходный случайный контейнер:" << std::endl;
	printVector(numbers);

	// Задание а
	squarePrimes(numbers);

	std::cout << std::endl;
	std::cout << "После возведения простых чисел в квадрат:" << std::endl;
	printVector(numbers);

	// Задание b
	std::vector<int> sortedNumbers = sortOddEven(numbers);

	std::cout << std::endl;
	std::cout << "Нечётные по возрастанию, " "затем чётные по убыванию:" << std::endl;
	printVector(sortedNumbers);

	// Задание c
	int minValue;
	int maxValue;

	std::cout << std::endl;
	std::cout << "Введите начало диапазона: ";
	std::cin >> minValue;

	std::cout << "Введите конец диапазона: ";
	std::cin >> maxValue;

	// меняем границы местами если пользователь ввел их в обратном порядке
	if (minValue > maxValue)
	{
		std::swap(minValue, maxValue);
	}

	std::vector<int> rangeNumbers = uniqueInRange(numbers, minValue, maxValue);

	std::cout << std::endl;
	std::cout << "Уникальные элементы из диапазона ["<< minValue << ", "<< maxValue << "]:"<< std::endl;

	if (rangeNumbers.empty())
	{
		std::cout << "Элементы не найдены." << std::endl;
	}
	else
	{
		printVector(rangeNumbers);
	}

	std::cout << std::endl;
	std::cout << "Нажмите Enter для выхода...";

	std::cin.ignore(std::numeric_limits <std::streamsize> ::max(), '\n' );

	std::cin.get();

	return 0;
}
