#pragma once

using namespace std;

#include <vector>
#include <string>

class CommandParser
{
private:
    static vector<string> split(string str, char delimiter);
public:
    CommandParser() = delete;
    static void parseCommand(string commandToParse);
    static void parseLoginCommand(vector<string> commandParameters);
};




