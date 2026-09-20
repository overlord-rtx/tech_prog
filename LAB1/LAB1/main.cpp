#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

string toLowerCase(string word)
{
	string result;

	for (size_t i = 0; i < word.length();)
	{
		unsigned char first = word[i];

		if ((first == 0xD0 || first == 0xD1) && i + 1 < word.length() )
		{
			unsigned char second = word[i + 1];

			// Ё на ё
			if (first == 0xD0 && second == 0x81)
			{
				result += "\xD1\x91";
				i += 2;
			}
			// А-П на а-п
			else if (first == 0xD0 && second >= 0x90 && second <= 0x9F)
			{
				result += static_cast<char>(first);
				result += static_cast<char>(second + 0x20);
				i += 2;
			}
			// Р-Я на р-яя
			else if (first == 0xD0 && second >= 0xA0 && second <= 0xAF)
			{
				result += static_cast <char> (0xD1);
				result += static_cast <char> (second - 0x20);
				i += 2;
			}
			else
			{
				result += static_cast <char> (first);
				result += static_cast <char> (second);
				i += 2;
			}
		}
		else
		{
			result = result + static_cast <char> (tolower(static_cast <unsigned char> (word[i]) ) );
			i++;
		}
	}

	return result;
}



string normalizeWord(string word)
{

	while (word.empty() == false && ispunct(static_cast <unsigned char> (word.front() ) ) )
	{
		word.erase(word.begin() );
	}

	while (word.empty() == false && ispunct(static_cast <unsigned char> (word.back() ) ) )
	{
		word.pop_back();
	}

	word = toLowerCase(word);
	return word;
}


bool containsWordSymbol(const string& word)
{
	for (size_t i = 0; i < word.length(); i++)
	{
		unsigned char symbol = word[i];

		if (isalnum(symbol) )
		{
			return true;
		}

		// русская быква нчаинется с d0 или d1
		if ((symbol == 0xD0 || symbol == 0xD1) &&
			i + 1 < word.length() )
		{
			return true;
		}
	}

	return false;
}


int main()
{
	setlocale(LC_ALL, "");

	ifstream inputFile("input.txt");

	if (!inputFile.is_open())
	{
		cerr << "Ошибка: не удалось открыть файл input.txt." << endl;

		cin.get();

		return 1;
	}

	map<string, vector<int>> wordPositions;

	string word;

	int position = 0;
	while (inputFile >> word)
	{
		word = normalizeWord(word);

		if (containsWordSymbol(word) == false)
		{
			continue;
		}
		wordPositions[word].push_back(position);

		position++;
	}

	inputFile.close();

	for (const auto& key_value : wordPositions)
	{
		cout << key_value.first << " – ";

		for (size_t i = 0; i < key_value.second.size(); i++)
		{
			cout << key_value.second[i];

			if (i + 1 < key_value.second.size())
			{
				cout << ", ";
			}
		}

		cout << endl;
	}

	cin.ignore();
	cin.get();

	return 0;
}
