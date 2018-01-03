/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "StringCommandParser.h"
using namespace std;


StringCommandParser::comData StringCommandParser::strToNameAndArgc(string str) {
    istringstream iss(str);
    comData data;
    bool commandWordWasSpecified = false;
    data.comName = "";
    string tok;
    iss >> tok;
    if (tok.empty())
        throw "no command word was specified";
    data.comName.append(tok);
    tok = "";
    while(iss) {
        iss >> tok;
        if (!(tok.empty())) {
            data.comArgs.push_back(tok);
        }
        tok = "";
    }
    return data;
}
