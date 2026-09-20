#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

string normalizeWord(string word)
{
	while (word.empty() == false && ispunct(static_cast<unsigned char> (word.front())))
	{
		word.erase(word.begin() );
	}

	while (word.empty() == false && ispunct(static_cast<unsigned char> (word.back())))
	{
		word.pop_back();
	}

	transform(word.begin(), word.end(), word.begin(),
		[](unsigned char symbol)
	{
		return static_cast <char> (tolower(symbol) );
	});

	return word;
}

int main()
{
	setlocale(LC_ALL, "");

	ifstream inputFile("input.txt");

	if (inputFile.is_open() == false)
	{
		cout << "Ошибка: не удалось открыть файл input.txt." << endl;
		cin.get();

		return 1;
	}

	map<string, int> wordCounter;
	string word;

	while (inputFile >> word)
	{
		word = normalizeWord(word);

		if (word.empty() == false)
		{
			wordCounter[word]++;
		}
	}

	inputFile.close();

	cout << "Результаты подсчёта слов:" << endl;

	for (const auto& key_value : wordCounter)
	{
		cout << key_value.first << " - " << key_value.second << endl;
	}

	cin.ignore();
	cin.get();

	return 0;
}
