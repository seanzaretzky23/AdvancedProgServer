/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "PrintCommand.h"
void PrintCommand::execute(vector<string> args) {
    for (int i = 0; i < args.size(); i++) {
        cout << args[i] << " ";
    }
    cout << endl;
}