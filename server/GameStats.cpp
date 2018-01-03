/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "GameStats.h"
using namespace std;

GameStats::GameStats(string gameName, int firstClientSocket): gameName(gameName), firstClientSocket(firstClientSocket),
                                                              secondClientSocket(-1){
}

GameStats::GameStats(std::string gameName): gameName(gameName), firstClientSocket(-1), secondClientSocket(-1) {}

GameStats::GameStats(const GameStats &gameStatsToCopy) {
    this->gameName = gameStatsToCopy.gameName;
    this->firstClientSocket = gameStatsToCopy.firstClientSocket;
    this->secondClientSocket = gameStatsToCopy.secondClientSocket;
}

GameStats::GameStats(): gameName(""), firstClientSocket(-1), secondClientSocket(-1) {}

string GameStats::getGameName() const {
    return string(this->gameName);
}

int GameStats::getFirstClientSocket() const {
    return this->firstClientSocket;
}

int GameStats::getSecondClientSocket() const {
    return this->secondClientSocket;
}

void GameStats::setSecondClientSocket(int secondClientSocket) {
    this->secondClientSocket = secondClientSocket;
}

bool GameStats::operator==(GameStats gameStats) const {
    return this->gameName == gameStats.getGameName();
}
