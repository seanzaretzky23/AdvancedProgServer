//
// Created by sean on 12/31/17.
//

#ifndef ADVANCEDPROGSERVER_STARTGAMECOMMAND_H
#define ADVANCEDPROGSERVER_STARTGAMECOMMAND_H
#include "Command.h"
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <sstream>

class StartGameCommand: public Command {
public:
    //starts a new game (if name is valid) with the name of game provided in the first argument !!!!!! and returns reply to client if creation succeeded (0 if succeded otherwise failed (1 or something else))
    virtual void execute(std::vector<std::string> args, int clientSocket);
};


#endif //ADVANCEDPROGSERVER_STARTGAMECOMMAND_H
