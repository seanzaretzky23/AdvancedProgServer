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
    virtual void execute(vector<string> args);
};


#endif //UNTITLED_PRINTCOMMAND_H
