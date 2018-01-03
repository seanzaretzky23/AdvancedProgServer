/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef ADVANCEDPROGSERVER_JOINGAMECOMMAND_H
#define ADVANCEDPROGSERVER_JOINGAMECOMMAND_H

#include "Command.h"
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <sstream>

/**
 * class responsible for the join command of server protocol
 */
class JoinGameCommand: public Command {
public:
    //joins the client to an existing game (if name is valid) with the name of game provided in the first argument !!!!!! and returns reply to client if joining succeeded (0 if succeded otherwise failed (-1))
    /**************************************************************
    * function name: execute
    * Input: vector<std::string> args, int clientSocket
    * @return void
    * Function operation: execute the command using
    * the given arguments, check if there is a game with a
    * waiting player in the name that was given. if so join
    * the client to that game
    * else (invalid arguments writes error message to client).
    **************************************************************/
    virtual void execute(std::vector<std::string> args, int clientSocket);
};


#endif
