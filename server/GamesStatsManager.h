/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef ADVANCEDPROGSERVER_GAMEMANAGER_H
#define ADVANCEDPROGSERVER_GAMEMANAGER_H

#include "GameStats.h"
#include "vector"
#include "algorithm"

/*
 * resoponsible for pending (in waiting for second player) games. there is only one game with given name in the vector
 * implemented as singleton class
 */
class GamesStatsManager {
public:
    static GamesStatsManager *getInstanceOfGameStatsManager();
    void addGame(GameStats newGame);
    //returns true if removal succeded and false if there is no game with the given name in the GamesStatsManager (removal failed)
    bool removeGame(std::string gameName);
    bool gameExists(std::string gameName) const;
    const std::vector<GameStats> getGames() const;
    ~GamesStatsManager();
private:
    GamesStatsManager();
    std::vector<GameStats> games;

    static GamesStatsManager *instance;
};


#endif //ADVANCEDPROGSERVER_GAMEMANAGER_H
