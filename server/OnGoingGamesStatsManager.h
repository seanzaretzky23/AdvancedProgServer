/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef ADVANCEDPROGSERVER_ONGOINGGAMESSTATSMANAGER_H
#define ADVANCEDPROGSERVER_ONGOINGGAMESSTATSMANAGER_H

#include "GameStats.h"
#include "GameHandler.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <unistd.h>

struct OnGoingGamesInfo{
    GameStats *gameStats;
    pthread_t threadIdOfGame;
};

/*
 * responsible for on going (games that are in process, players play between them) games.
 * implemented as singleton class
 */
class OnGoingGamesStatsManager {
public:
    /**************************************************************
    * function name: getInstanceOfOnGoingGameStatsManager
    * @return OnGoingGamesStatsManager *
    * Function operation: returns pointer to the instance of the class
    **************************************************************/
    static OnGoingGamesStatsManager *getInstanceOfOnGoingGameStatsManager();

    /**************************************************************
    * function name: startGame
    * Input:GameStats *newGameStats
    * @return void
    * Function operation: creates new game and thread and put it
     * in the game in the thread.
    **************************************************************/
    void startGame(GameStats *newGameStats);

    //returns true if removal succeded and false if there is no game with the given name in the OnGoingGamesStatsManager (removal failed)
    //also closes the sockets of the players in the removed game
    /**************************************************************
    * function name: removeGame
    * Input:const GameStats * const gameStats
    * @return bool
    * Function operation: removes the game which's pointer received
    * returns true if removal succeded and
    * false if there is no game with the given name in the
    * OnGoingGamesStatsManager (removal failed)
    * also closes the sockets of the players in the removed game
    **************************************************************/
    bool removeGame(const GameStats * const gameStats);

    /**************************************************************
    * function name: stopAndTerminateAllGames
    * Input:none
    * @return void
    * Function operation: terminate all games
    **************************************************************/
    void stopAndTerminateAllGames();
    //bool gameExists(std::string gameName) const;
    //const std::vector<GameStats> getGames() const;
    //void stopAllOnGoingGames();
    /**************************************************************
    * function name: OnGoingGamesStatsManager class destructor
    **************************************************************/
    ~OnGoingGamesStatsManager();
private:
    /**************************************************************
    * function name: OnGoingGamesStatsManager private constructor
    * Input:none
    * @return instance of the OnGoingGamesStatsManager class
    **************************************************************/
    OnGoingGamesStatsManager();
    std::vector<OnGoingGamesInfo *> onGoingGames;
    /**************************************************************
    * function name: startNewGame
    * Input:const void *InfoForNewGame
    * @return void *
    * Function operation: static method that is used in the threads
    *   starting new game
    **************************************************************/
    static void *startNewGame(void *InfoForNewGame);
    //instance of the singleton class
    static OnGoingGamesStatsManager *instance;
};


#endif
