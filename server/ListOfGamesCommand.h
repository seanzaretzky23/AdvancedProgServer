/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef ADVANCEDPROGSERVER_LISTOFGAMESCOMMAND_H
#define ADVANCEDPROGSERVER_LISTOFGAMESCOMMAND_H

#include "Command.h"
#include <sys/socket.h>
#include <unistd.h>
#include <cstring>
#include <iostream>
#include <sstream>

class ListOfGamesCommand: public Command {
public:
    //returns the list of games as games names with ',' in between words and the word listOfGames in the beginning
    virtual void execute(std::vector<std::string> args, int clientSocket);

};


#endif //ADVANCEDPROGSERVER_LISTOFGAMESCOMMAND_H
