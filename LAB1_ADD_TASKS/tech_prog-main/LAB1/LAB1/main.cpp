#include <chrono>
#include <iostream>
#include <clocale>

#include "Reader.h"
#include "WordCounterr.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	auto start = chrono::steady_clock::now();

	WordCounter wordCounter;
	Reader fileReader;

	if (fileReader.readFile("input.txt", wordCounter) == false)
	{
		cout << "Error: can`t open file input.txt." << endl;
		cin.get();

		return 1;
	}

	wordCounter.printResult();

	auto end = chrono::steady_clock::now();

	chrono::duration<double> elapsed = end - start;

	cout << "Duration of work: " << elapsed.count() << " sec\n";

	cin.ignore();
	cin.get();

	return 0;
}

// 1 классы 2 хроно 3 чтение блочно