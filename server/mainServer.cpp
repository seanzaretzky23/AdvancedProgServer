/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "Server.h"
#include "FileReader.h"
#include <pthread.h>
#include <stdlib.h>

#define CONFIG_FILE "configFileServer.txt"
using namespace std;

void *askServerToReceiveClientsMethod(void *parameter) {
    Server *server = (Server *)parameter;
    server->acceptPlayersConnections();
}

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
        pthread_t acceptingClientsThread;
        int rc = pthread_create(&acceptingClientsThread, NULL, askServerToReceiveClientsMethod, &server);
        if (rc) {
            cout << "Error: unable to create \"accepting clients\" thread, " << rc << endl;
            exit(-1);
        }
        /**
         * add code for receiving exit command to terminate the server using its stop method add close all client sockets and threads
         */
        void *returnValue;
        pthread_join(acceptingClientsThread, &returnValue);

    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}
