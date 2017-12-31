/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "ListOfGamesCommand.h"
#include "GamesStatsManager.h"

using namespace std;

void ListOfGamesCommand::execute(std::vector<std::string> args, int clientSocket) {
    int numberOfBytesTransferred;
    const char *buffer;
    GamesStatsManager *gamesStatsManager = GamesStatsManager::getInstanceOfGameStatsManager();
    vector<GameStats> listOfGames = gamesStatsManager->getGames();
    string strListOfGames = "listOfGames";
    for (vector<GameStats>::iterator it = listOfGames.begin(); it != listOfGames.end(); it++) {
        strListOfGames += "," + it->getGameName();
    }

    buffer = strListOfGames.c_str();
    numberOfBytesTransferred = write(clientSocket, buffer, strlen(buffer) + 1);
    if (numberOfBytesTransferred == -1) {
        stringstream ss;
        ss << clientSocket;
        cout << "Error writing List Of Games to client with the socket id: " << ss.str().c_str() << endl;
    }
}
