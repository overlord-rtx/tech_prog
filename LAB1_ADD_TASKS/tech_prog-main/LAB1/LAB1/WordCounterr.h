#pragma once
#include <map>
#include <string>

using namespace std;

class WordCounter
{
private:
	map<string, int> wordCounter;
	string word;
	void processWord();

public:
	void processSymbol(char symbol);
	void processLastWord();
	void printResult();
};
