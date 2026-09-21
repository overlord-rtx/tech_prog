#include "WordNormalizer.h"

#include <algorithm>
#include <cctype>

string WordNormalizer::normalizeWord(string word)
{
	while (word.empty() == false && ispunct(static_cast<unsigned char> (word.front() ) ) )
	{
		word.erase(word.begin());
	}

	while (word.empty() == false && ispunct(static_cast<unsigned char> (word.back() ) ) )
	{
		word.pop_back();
	}

	transform(word.begin(), word.end(), word.begin(), [](unsigned char symbol)
		{
			return static_cast<char> (tolower(symbol)) ;
		});

	return word;
}
