/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef ADVANCEDPROGSERVER_STRINGCOMMANDPARSER_H
#define ADVANCEDPROGSERVER_STRINGCOMMANDPARSER_H
#include <iostream>
#include <string.h>
#include <vector>
#include <sstream>

class StringCommandParser {

public:

    //struct to hold the command name and its arguments
    struct comData
    {
        std::string comName;
        std::vector<std::string> comArgs;
    };

    //parses the string into comData meaning extracts the command name and its arguments separately, throws exception if no command name was specified
    /**************************************************************
    * function name: strToNameAndArgc
    * Input:string str
    * @return comData
    * function operation:parses the string into
    * comData, meaning extracts the command name
    * and its arguments separately, throws exception
    * if no command name was specified
    **************************************************************/
    comData strToNameAndArgc(std::string str);

};


#endif
