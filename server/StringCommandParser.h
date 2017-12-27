//
// Created by sean on 12/27/17.
//

#ifndef ADVANCEDPROGSERVER_STRINGCOMMANDPARSER_H
#define ADVANCEDPROGSERVER_STRINGCOMMANDPARSER_H
#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>

class StringCommandParser {

public:

    struct comData
    {
        std::string comName;
        std::vector<std::string> comArgs;
    };

    comData strToNameAndArgc(std::string str);
    int countCharInString(std::string str, char ch);

};


#endif //ADVANCEDPROGSERVER_STRINGCOMMANDPARSER_H
