/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "PrintCommand.h"
using namespace std;
void PrintCommand::execute(vector<string> args, int socket) {
    for (int i = 0; i < args.size(); i++) {
        cout << args[i] << " ";
    }
    cout << endl;
}