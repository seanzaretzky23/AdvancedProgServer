/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef UNTITLED_COMMAND_H
#define UNTITLED_COMMAND_H


#include <vector>
#include <string>

class Command {
public:
    //port is optional parameter describing the socket identifier of the client
    virtual void execute(std::vector<std::string> args, int socket = -1) = 0;
    virtual ~Command() {}
};


#endif //UNTITLED_COMMAND_H
