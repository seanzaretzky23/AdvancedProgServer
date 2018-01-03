/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "ListOfGamesCommand.h"
#include "PendingGamesStatsManager.h"

using namespace std;

void ListOfGamesCommand::execute(std::vector<std::string> args, int clientSocket) {
    int numberOfBytesTransferred;
    const char *buffer;
    bool firstWord = true;
    PendingGamesStatsManager *gamesStatsManager = PendingGamesStatsManager::getInstanceOfPendingGameStatsManager();
    vector<GameStats> listOfGames = gamesStatsManager->getGames();
    string strListOfGames = "list_of_games: ";
    for (vector<GameStats>::iterator it = listOfGames.begin(); it != listOfGames.end(); it++) {
        if (firstWord) {
            strListOfGames += it->getGameName();
            firstWord = false;
        } else {
            strListOfGames += ", " + it->getGameName();
        }
    }

    buffer = strListOfGames.c_str();
    numberOfBytesTransferred = write(clientSocket, buffer, strlen(buffer) + 1);
    if (numberOfBytesTransferred == -1) {
        stringstream ss;
        ss << clientSocket;
        cout << "Error writing List Of Games to client with the socket id: " << ss.str().c_str() << endl;
    }
    close(clientSocket); //check if it needs to be here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
}
