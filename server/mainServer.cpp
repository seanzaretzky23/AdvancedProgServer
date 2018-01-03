/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "Server.h"
#include "FileReader.h"
#include "OnGoingGamesStatsManager.h"
#include "PendingGamesStatsManager.h"
#include <pthread.h>
#include <stdlib.h>

#define CONFIG_FILE "configFileServer.txt"
using namespace std;

void *askServerToReceiveClientsMethod(void *parameter) {
    Server *server = (Server *)parameter;
    server->acceptPlayersConnections();
}

int main() {
    string strPort;
    FileReader fileReader;
    try {
        strPort = fileReader.ReadPort(CONFIG_FILE);
    } catch (const char * exc) {
        cout << "error in mainServer: " << exc << endl;
        exit (-1);
    }
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
         * enabling the server to finish and exit
         */
        string str = string("");
        while (true) {
            cout << "for stopping and closing the server type exit" << endl;
            cin >> str;
            //if we received exit command
            if (str == "exit") {
                OnGoingGamesStatsManager *onGoingGamesStatsManager = OnGoingGamesStatsManager::getInstanceOfOnGoingGameStatsManager();
                onGoingGamesStatsManager->stopAndTerminateAllGames();
                PendingGamesStatsManager *pendingGamesStatsManager = PendingGamesStatsManager::getInstanceOfPendingGameStatsManager();
                pendingGamesStatsManager->stopAndTerminateAllGames();
                server.stop();
                pthread_cancel(acceptingClientsThread);
                cout << "server is terminating after exit command" << endl;
                exit (0);
            } else {
                cout << "incorrect termination command\n" << endl;
            }
        }
        //void *returnValue;
        //pthread_join(acceptingClientsThread, &returnValue);

    } catch (const char *msg) {
        cout << "Cannot start server. Reason: " << msg << endl;
        exit(-1);
    }
}
