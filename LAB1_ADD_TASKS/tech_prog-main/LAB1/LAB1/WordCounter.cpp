#include "WordCounterr.h"
#include "WordNormalizer.h"

#include <iostream>
#include <cctype>

using namespace std;

void WordCounter::processWord()
{
	word = WordNormalizer::normalizeWord(word);

	if (word.empty() == false)
	{
		wordCounter[word]++;
	}

	word.clear();
}

void WordCounter::processSymbol(char symbol)
{
	unsigned char unsignedSymbol =
		static_cast<unsigned char> (symbol);

	if (isspace(unsignedSymbol))
	{
		if (word.empty() == false)
		{
			processWord();
		}
	}
	else
	{
		word += symbol;
	}
}

void WordCounter::processLastWord()
{
	if (word.empty() == false)
	{
		processWord();
	}
}

void WordCounter::printResult()
{
	cout << "Result of counting words" << endl;

	for (const auto& key_value : wordCounter)
	{
		cout << key_value.first
			<< " - "
			<< key_value.second
			<< endl;
	}
}
