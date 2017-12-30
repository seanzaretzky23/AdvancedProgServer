/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "CommandsManager.h"
#include "PrintCommand.h"
#include "ListOfGamesCommand.h"
using namespace std;

CommandsManager::CommandsManager() {
    commandsMap["print"] = new PrintCommand();
    commandsMap["list_games"] = new ListOfGamesCommand();
    // Add more commands...
}
void CommandsManager::executeCommand(string command, vector<string> args, int clientSocket) {
    //checking if the command key exists in the map (if valid command)
    if (commandsMap.count(command)) {
        Command *commandObj = commandsMap[command];
        commandObj->execute(args, clientSocket);
    }
}
CommandsManager::~CommandsManager() {
    map<string, Command *>::iterator it;
    for (it = commandsMap.begin(); it != commandsMap.end(); it++) {
        delete it->second;
    }
}