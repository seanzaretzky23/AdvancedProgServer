/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef UNTITLED_COMMANDSMANAGER_H
#define UNTITLED_COMMANDSMANAGER_H

#include <map>
#include "Command.h"

class CommandsManager {
public:
    CommandsManager();
    ~CommandsManager();
    void executeCommand(std::string command, std::vector<std::string> args, int clientSocket);
private:
    std::map<std::string, Command *> commandsMap;
};


#endif //UNTITLED_COMMANDSMANAGER_H
