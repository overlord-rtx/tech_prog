#pragma once
#include <string>

using namespace std;

class WordCounter;

class Reader
{
private:
	const int BUFFER_SIZE = 64;
public:
	bool readFile(const string& fileName, WordCounter& counter);
};
