/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef ADVANCEDPROGSERVER_GAMEHANDLER_H
#define ADVANCEDPROGSERVER_GAMEHANDLER_H

#include "GameStats.h"
#include "OnGoingGamesStatsManager.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <cstring>

/*
 * this class is responsible for handling game flow between two clients
 */
class GameHandler {
public:
    /******************************************************************
    * function name: GameHandler constructor
    * Input: const GameStats &gameStats
    * @return instance of GameHandler
    * function operation: creates a game which's settings specified in
    *   gameStats (it's name and the players' sockets)
    *******************************************************************/
    GameHandler(const GameStats * const gameStats);

    /******************************************************************
    * function name: letPlayersPlayAGame
    * Input: no input
    * @return void
    * function operation: conducts the game session between two players
    *******************************************************************/
    void letPlayersPlayAGame();
private:
    enum WhichPlayer {First = 1, Second = 2};

    const GameStats * const gameStats;

    /************************************************************************
    * function name: switchTurn
    * Input: WhichPlayer &turn
    * @return void
    * function operation: switches the turn (with respect to the enum)
    *************************************************************************/
    void switchTurn(WhichPlayer &turn) const;

    /************************************************************************************
    * function name: errorInReadingFromCLient
    * Input: int numOfBytesReceived
    * @return bool
    * function operation: method responsible of checking for errors in input from clients
    *   checks if numOfBytesReceived is 0 (client disconnected) or 1 (error reading)after
    *   read then return true else (everything fine) return true
    *************************************************************************************/
    bool errorInReadingFromClient(int numOfBytesReceived);

};

#endif
