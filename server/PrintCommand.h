/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef UNTITLED_PRINTCOMMAND_H
#define UNTITLED_PRINTCOMMAND_H


#include "Command.h"
#include <iostream>

/**
 * class responsible for the print command of server protocol
 */
class PrintCommand: public Command {
public:
    /**************************************************************
    * function name: execute
    * Input: vector<std::string> args, int socket = -1 (default)
    * @return void
    * function operation: prints the vector args
    **************************************************************/
    virtual void execute(std::vector<std::string> args, int socket = -1);
};


#endif //UNTITLED_PRINTCOMMAND_H
