/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef UNTITLED_PRINTCOMMAND_H
#define UNTITLED_PRINTCOMMAND_H


#include "Command.h"
#include <iostream>

class PrintCommand: public Command {
public:
    virtual void execute(std::vector<std::string> args, int socket = -1);
};


#endif //UNTITLED_PRINTCOMMAND_H
