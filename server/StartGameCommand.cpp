//
// Created by sean on 12/31/17.
//

#include "StartGameCommand.h"
#include "GamesStatsManager.h"

using namespace std;

void StartGameCommand::execute(std::vector<std::string> args, int clientSocket) {
    int numberOfBytesTransferred;
    const char *buffer;
    if (args.empty()) {
        cout << "Error writing starting new game after a start game command from client with socket: " << clientSocket
             << "\nbecause command wasn't provided with a name for the new game" << endl; // maybe erase this message!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        buffer = "1";
        numberOfBytesTransferred = write(clientSocket, buffer, strlen(buffer) + 1);
        if (numberOfBytesTransferred == -1) {
            stringstream ss;
            ss << clientSocket;
            cout << "Error writing error to client after request for creation of new game (client socket id:) " << clientSocket << endl;
        }
    } else {
        GameStats gameStats(args[0], clientSocket);
        GamesStatsManager *gamesStatsManager = GamesStatsManager::getInstanceOfGameStatsManager();
        gamesStatsManager->addGame(gameStats);
        buffer = "0";
        numberOfBytesTransferred = write(clientSocket, buffer, strlen(buffer) + 1);
        if (numberOfBytesTransferred == -1) {
            stringstream ss;
            ss << clientSocket;
            cout << "Error writing success message to client after request for creation of new game (client socket id:) " << clientSocket << endl;
        }
    }
}
