#include "Reader.h"
#include "WordCounterr.h"

#include <fstream>

using namespace std;

bool Reader::readFile(const string& fileName, WordCounter& counter)
{
    ifstream inputFile(fileName, ios::binary);

    if (!inputFile.is_open())
    {
        return false;
    }

    const streamsize bufferSize = 1;
    char buffer[1];

    while (inputFile.read(buffer, bufferSize) || inputFile.gcount() > 0)
    {
        streamsize bytesRead = inputFile.gcount();

        for (streamsize i = 0; i < bytesRead; ++i)
        {
            counter.processSymbol(buffer[i]);
        }
    }

    counter.processLastWord();

    return true;
}
