/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef UNTITLED_COMMANDSMANAGER_H
#define UNTITLED_COMMANDSMANAGER_H

#include <map>
#include "Command.h"
#include "PrintCommand.h"
#include "ListOfGamesCommand.h"
#include "StartGameCommand.h"
#include "JoinGameCommand.h"

class CommandsManager {
public:
    /**************************************************************
    * function name: CommandsManager class constructor
    * Input: no input
    * function operation: returns an instance of the CommandManager
    **************************************************************/
    CommandsManager();
    /**************************************************************
    * function name: CommandsManager class destructor
    * Input: no input
    * function operation: destroys the instance of CommandManager
    **************************************************************/
    ~CommandsManager();
    /**************************************************************
    * function name: executeCommand
    * Input: std::string command, std::vector<std::string> args,
    *   int clientSocket
    * @return void
    * function operation: executes the command received with received
    *   arguments using provided client socket, if command invalid
    *   closes the socket without further operation
    **************************************************************/
    void executeCommand(std::string command, std::vector<std::string> args, int clientSocket);
private:
    //the map of valid command names at the command objects matching them
    std::map<std::string, Command *> commandsMap;
};


#endif
