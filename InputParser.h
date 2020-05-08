#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <string>

class InputParser {
public:
    int parseWorkersLine(std::string line);
    int parseMapChar(char c);
};

#endif // INPUTPARSER_H
