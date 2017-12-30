//
// Created by sean on 12/28/17.
//

#include "GameStats.h"
using namespace std;

GameStats::GameStats(string gameName, int firstCLientSocket): gameName(gameName), firstClientSocket(firstCLientSocket) {
}

GameStats::GameStats(std::string gameName): gameName(gameName){}

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
