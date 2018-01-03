/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef ADVANCEDPROGSERVER_STARTGAMECOMMAND_H
#define ADVANCEDPROGSERVER_STARTGAMECOMMAND_H

#include "Command.h"
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <sstream>

/**
 * class responsible for the start command of server protocol
 */
class StartGameCommand: public Command {
public:
    //starts a new game (if name is valid) with the name of game provided in the first argument !!!!!! and returns reply to client if creation succeeded (0 if succeded otherwise failed (-1))
    /**************************************************************
    * function name: execute
    * Input: std::vector<std::string> args, int clientSocket
    * @return void
    * function operation: starts a new game (if name is valid)
    * with the name of game provided in the first argument
    * and returns reply to client if creation succeeded
    * (0 if succeded otherwise failed (-1))
    **************************************************************/
    virtual void execute(std::vector<std::string> args, int clientSocket);
};


#endif
