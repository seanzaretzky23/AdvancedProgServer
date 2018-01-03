/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "StartGameCommand.h"
#include "PendingGamesStatsManager.h"

using namespace std;

void StartGameCommand::execute(std::vector<std::string> args, int clientSocket) {
    int numberOfBytesTransferred;
    const char *buffer;
    if (args.empty()) {
        cout << "Error writing starting new game after a start game command from client with socket: " << clientSocket
             << "\nbecause command wasn't provided with a name for the new game" << endl; // maybe erase this message!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        buffer = "-1";
        numberOfBytesTransferred = write(clientSocket, buffer, strlen(buffer) + 1);
        if (numberOfBytesTransferred == -1) {
            stringstream ss;
            ss << clientSocket;
            cout << "Error writing error to client after request for creation of new game (client socket id:) " << clientSocket << endl;
        }
        close(clientSocket);
    } else {
        string gameName = args[0];
        GameStats gameStats(gameName, clientSocket);
        PendingGamesStatsManager *gamesStatsManager = PendingGamesStatsManager::getInstanceOfPendingGameStatsManager();
        if (!(gamesStatsManager->gameExists(gameName))) {
            buffer = "0";
            numberOfBytesTransferred = write(clientSocket, buffer, strlen(buffer) + 1);
            if (numberOfBytesTransferred == -1) {
                stringstream ss;
                ss << clientSocket;
                cout << "Error writing success message to client after request for creation of new game (client socket id:) "
                        << clientSocket << endl;
                close(clientSocket); // added!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 3.1 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            } else {   // added!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! 3.1 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                gamesStatsManager->addGame(gameStats);
            }
        } else {
            buffer = "-1";
            numberOfBytesTransferred = write(clientSocket, buffer, strlen(buffer) + 1);
            if (numberOfBytesTransferred == -1) {
                stringstream ss;
                ss << clientSocket;
                cout << "Error writing error to client after request for starting to a new game (client socket id:) "
                     << clientSocket << endl;
            }
            close(clientSocket);
        }
    }
}
