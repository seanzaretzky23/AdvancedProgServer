/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "GameHandler.h"
#define BUFFER_SIZE 4096
using namespace std;

GameHandler::GameHandler(const GameStats * const existingGameStats): gameStats(existingGameStats) {
    this->letPlayersPlayAGame();
}

void GameHandler::letPlayersPlayAGame() {
    //if there are less than two players that the server established connection with
    if (this->gameStats->getFirstClientSocket() == -1 || this->gameStats->getSecondClientSocket() == -1)
        throw "the GameHandler needs to connect to two players in order for a game to take place";

    OnGoingGamesStatsManager *onGoingGamesStatsManager = OnGoingGamesStatsManager::getInstanceOfOnGoingGameStatsManager();

    WhichPlayer whosTurn = First;
    int numberOfBytesTransferred;
    char buffer[BUFFER_SIZE];
    const char NoMove[] = "NoMove";
    const char End[] = "End";
    buffer[0] = '0' + First;
    buffer[1] = '\0';
    numberOfBytesTransferred = write(this->gameStats->getFirstClientSocket(), buffer, strlen(buffer) + 1); // !!!!! changed from sizeOf(buffer)!!!!!!!!!!!!!!!
    if (numberOfBytesTransferred == -1) {
        //first player disconnected
        onGoingGamesStatsManager->removeGame(this->gameStats);
        return;
    }
    buffer[0] = '0' + Second;
    numberOfBytesTransferred = write(this->gameStats->getSecondClientSocket(), buffer, strlen(buffer) + 1);
    if (numberOfBytesTransferred == -1) {
        //second player disconnected
        onGoingGamesStatsManager->removeGame(this->gameStats);
        return;
    }
    while (true) {
        memset(buffer, '\0', BUFFER_SIZE);
        if (whosTurn == First) {
            numberOfBytesTransferred = read(this->gameStats->getFirstClientSocket(), buffer, BUFFER_SIZE);
            //checking if input from client is valid (received)
            if (this->errorInReadingFromClient(numberOfBytesTransferred)) {
                //error detected
                break;
            }
            if (strcmp(buffer, NoMove) == 0) {
                this->switchTurn(whosTurn);
                continue;
            }
            if (strcmp(buffer, End) == 0) {
                break;
            }
            numberOfBytesTransferred = write(this->gameStats->getSecondClientSocket(), buffer, numberOfBytesTransferred);
            if (numberOfBytesTransferred == -1) {
                //second player disconnected
                onGoingGamesStatsManager->removeGame(this->gameStats);
                return;
            }
        } else {
            numberOfBytesTransferred = read(this->gameStats->getSecondClientSocket(), buffer, BUFFER_SIZE);
            //checking if input from client is valid (received)
            if (this->errorInReadingFromClient(numberOfBytesTransferred)) {
                //error detected
                break;
            }
            if (strcmp(buffer, NoMove) == 0) {
                this->switchTurn(whosTurn);
                continue;
            }
            if (strcmp(buffer, End) == 0) {
                break;
            }
            numberOfBytesTransferred = write(this->gameStats->getFirstClientSocket(), buffer, numberOfBytesTransferred);
            if (numberOfBytesTransferred == -1) {
                //first player disconnected
                onGoingGamesStatsManager->removeGame(this->gameStats);
                return;
            }
        }
        this->switchTurn(whosTurn);
    }
    //cout << "disconnecting from clients\n" << endl;
    onGoingGamesStatsManager->removeGame(this->gameStats);

}

bool GameHandler::errorInReadingFromClient(int numOfBytesReceived) {
    bool returnVal = false;
    switch(numOfBytesReceived) {
        case -1:
            cout << "Error reading from client" << endl;
            returnVal = true;
            break;
        case 0:
            //cout << "Client disconnected" << endl;
            returnVal = true;
            break;
        default:
            //reading from client succeded
            break;
    }
    return returnVal;
}

void GameHandler::switchTurn(WhichPlayer &turn) const{
    switch (turn) {
        case First:
            turn = Second;
            break;
        case Second:
            turn = First;
            break;
        default:
            break;
    }
}
