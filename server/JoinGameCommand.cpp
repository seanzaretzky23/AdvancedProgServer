/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "JoinGameCommand.h"
#include "PendingGamesStatsManager.h"
#include "OnGoingGamesStatsManager.h"

using namespace std;

void JoinGameCommand::execute(std::vector<std::string> args, int clientSocket) {
    int numberOfBytesTransferred;
    const char *buffer;
    //name of game to join wasn't specified
    if (args.empty()) {
        cout << "Error after a join game command from client with socket: " << clientSocket
             << "\nbecause command wasn't provided with a name of the game"
             << endl; // maybe erase this message!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        buffer = "-1";
        numberOfBytesTransferred = write(clientSocket, buffer, strlen(buffer) + 1);
        if (numberOfBytesTransferred == -1) {
            stringstream ss;
            ss << clientSocket;
            cout << "Error writing error to client after request for joining to an existing game (client socket id:) "
                 << clientSocket << endl;
        }
        close(clientSocket);
    } else {
        string gameName = args[0];
        PendingGamesStatsManager *pendingGamesStatsManager = PendingGamesStatsManager::getInstanceOfPendingGameStatsManager();
        if (pendingGamesStatsManager->gameExists(gameName)){
            buffer = "0";
            numberOfBytesTransferred = write(clientSocket, buffer, strlen(buffer) + 1);
            if (numberOfBytesTransferred == -1) {
                stringstream ss;
                ss << clientSocket;
                cout << "Error writing success message to client after request for creation of new game (client socket id:) "
                     << clientSocket << endl;
                close(clientSocket); // added!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 3.1 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            } else { // added!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 3.1 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                GameStats *gameStats = pendingGamesStatsManager->getGameStatsOfGame(gameName);
                gameStats->setSecondClientSocket(clientSocket);
                OnGoingGamesStatsManager *onGoingGamesStatsManager = OnGoingGamesStatsManager::getInstanceOfOnGoingGameStatsManager();
                onGoingGamesStatsManager->startGame(gameStats);
                //removing the game from the pending list
                pendingGamesStatsManager->removeGame(gameName);
            }

            //game with specified name doesnt exist
        } else {
            buffer = "-1";
            numberOfBytesTransferred = write(clientSocket, buffer, strlen(buffer) + 1);
            if (numberOfBytesTransferred == -1) {
                stringstream ss;
                ss << clientSocket;
                cout << "Error writing error to client after request for joining to an existing game (client socket id:) "
                     << clientSocket << endl;
            }
            close(clientSocket);
        }
    }
}