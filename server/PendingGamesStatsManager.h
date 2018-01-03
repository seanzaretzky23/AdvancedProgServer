/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef ADVANCEDPROGSERVER_GAMEMANAGER_H
#define ADVANCEDPROGSERVER_GAMEMANAGER_H

#include "GameStats.h"
#include <vector>
#include <algorithm>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>

/*
 * responsible for pending (in waiting for second player) games. there is only one game with given name in the vector
 * implemented as singleton class
 */
class PendingGamesStatsManager {
public:
    /**************************************************************
    * function name: getInstanceOfPendingGameStatsManager
    * Input: no input
    * @return PendingGamesStatsManager * (the instance)
    * function operation: returns instance of PendingGamesStatsManager
     * if exist, or create on and returns it.
    **************************************************************/
    static PendingGamesStatsManager *getInstanceOfPendingGameStatsManager();
    /**************************************************************
    * function name:addGame
    * Input: GameStats newGame
    * @return void
    * function operation:add pending game to the vector of games
    **************************************************************/
    void addGame(GameStats newGame);

    //returns true if removal succeded and false if there is no game with the given name in the PendingGamesStatsManager (removal failed),
    //doesnt close the socket of the first client (the only valid client socket it has)
    /**************************************************************
    * function name:removeGame
    * Input: string gameName
    * @return bool
    * function operation:returns true if removal succeded and
    * false if there is no game with the given name in the
    * PendingGamesStatsManager (removal failed), doesnt close
    * the socket of the first client (the only valid client
    * socket it has)
    **************************************************************/
    bool removeGame(std::string gameName);

    /**************************************************************
    * function name:stopAndTerminateAllGames
    * Input: no input
    * @return void
    * function operation: terminate all the games by
    * running on the vector
    **************************************************************/
    void stopAndTerminateAllGames();

    /**************************************************************
    * function name:gameExists
    * Input: string gameName
    * @return bool
    * function operation: search for the game in the vector and
    * return true if it exist
    **************************************************************/
    bool gameExists(std::string gameName) const;

    /**************************************************************
    * function name:getGames
    * Input: none
    * @return const std::vector<GameStats>
    * function operation: returns the vector of games
    *   but with no changing permits
    **************************************************************/
    const std::vector<GameStats> getGames() const;

    /**************************************************************
    * function name:getGameStatsOfGame
    * Input: string gameName
    * @return GameStats *
    * function operation: returns pointer to the gameStats
    *   of game with specified name
    **************************************************************/
    GameStats *getGameStatsOfGame(std::string gameName);

    /**************************************************************
    * function name:~PendingGamesStatsManager
    * Input: no input
    * function operation: PendingGamesStatsManager destructor
    **************************************************************/
    ~PendingGamesStatsManager();
private:
    /**************************************************************
    * function name:PendingGamesStatsManager private constructor
    * Input: no input
    * function operation: initiates instance of PendingGamesStatsManager
    **************************************************************/
    PendingGamesStatsManager();
    std::vector<GameStats> games;
    //instance of the singleton class
    static PendingGamesStatsManager *instance;
};


#endif
