/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "Server.h"
#include "FileReader.h"
#include <stdlib.h>
#include <sstream>

#define CONFIG_FILE "configFileServer.txt"
using namespace std;
int main() {
    FileReader fileReader;
    string strPort = fileReader.ReadPort(CONFIG_FILE);
    //converting port to int
    int port;
    stringstream convert(strPort);
    if(!(convert >> port))
        throw "invalid port description";
    Server server(port);
    try {
        server.start();
        /*while(true) {
            server.acceptPlayersConnections();
            try {
                server.letPlayersPlayAGame();
            } catch (const char *msg){
                cout << "Error accured during game session. Reason: " << msg << endl;
                exit(-1);
            }
            cout << "starting new game phase with two new open places for players\n" << endl;
        }*/
        server.acceptPlayersConnections();
    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}
