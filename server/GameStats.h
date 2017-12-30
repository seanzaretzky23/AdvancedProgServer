//
// Created by sean on 12/28/17.
//

#ifndef ADVANCEDPROGSERVER_GAMESTATS_H
#define ADVANCEDPROGSERVER_GAMESTATS_H

#include "string"

class GameStats {
public:
    GameStats(std::string gameName, int firstCLientSocket);
    GameStats(std::string gameName);
    std::string getGameName() const;
    int getFirstClientSocket() const;
    int getSecondClientSocket() const;
    void setSecondClientSocket(int secondClientSocket);

    bool operator==(GameStats gameStats) const;

private:
    std::string gameName;
    int firstClientSocket;
    int secondClientSocket;

};


#endif //ADVANCEDPROGSERVER_GAMESTATS_H
