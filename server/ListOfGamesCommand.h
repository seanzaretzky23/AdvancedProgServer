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

/**
 * class responsible for the list_games command of server protocol
 */
class ListOfGamesCommand: public Command {
public:
    //returns the list of games as games names with ',' in between words and the word list_of_games in the beginning
    /**************************************************************
    * function name: execute
    * Input: std::vector<std::string> args, int clientSocket
    * @return void
    * function operation: returns to the specified client socket
    *   the list of currently open to join games
    **************************************************************/
    virtual void execute(std::vector<std::string> args, int clientSocket);

};


#endif
