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
    //socket is optional parameter describing the socket identifier of the client
    /**************************************************************
    * function name: execute
    * Input: std::vector<std::string> args, int socket = -1
    * @return void
    * function operation: executes the command with the given parameters
    **************************************************************/
    virtual void execute(std::vector<std::string> args, int socket = -1) = 0;
    /**************************************************************
    * function name: Command class destructor
    * Input: no input
    * function operation: destroys the class instance
    **************************************************************/
    virtual ~Command() {}
};


#endif //UNTITLED_COMMAND_H
