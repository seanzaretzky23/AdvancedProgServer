/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef ADVANCEDPROGSERVER_GAMESTATS_H
#define ADVANCEDPROGSERVER_GAMESTATS_H

#include "string"

/*
 * class responsible for the game stats holding of specific game (its name the the sockets of the players in the game)
 */
class GameStats {
public:
    /**************************************************************
    * function name: GameStats class constructor
    * Input: std::string gameName, int firstClientSocket
    * function operation: creates instance of gameStats class
    *   with the specified member values
    **************************************************************/
    GameStats(std::string gameName, int firstClientSocket);
    /**************************************************************
    * function name: GameStats class constructor
    * Input: std::string gameName
    * function operation: creates instance of gameStats class
    *   with the specified member values
    **************************************************************/
    GameStats(std::string gameName);
    //copy constructor
    /**************************************************************
    * function name: GameStats class copy constructor
    * Input: const GameStats &gameStatsToCopy
    * function operation: creates instance of gameStats class
    *   with the member values equal to the reference of gameStats received
    **************************************************************/
    GameStats(const GameStats &gameStatsToCopy);
    /**************************************************************
    * function name: GameStats class empty constructor
    * Input: no input
    * function operation: creates instance of gameStats class
    *   with the default member values
    **************************************************************/
    GameStats();
    /**************************************************************
    * function name: getGameName
    * Input: no input
    * @return std::string
    * function operation: returns the name of the game represented in
    *   gameStats instance
    **************************************************************/
    std::string getGameName() const;
    /**************************************************************
    * function name: getFirstClientSocket
    * Input: no input
    * @return int
    * function operation: returns the socket of the first player
    *   represented in gameStats instance
    **************************************************************/
    int getFirstClientSocket() const;
   /**************************************************************
   * function name: getSecondClientSocket
   * Input: no input
   * @return int
   * function operation: returns the socket of the second player
   *   represented in gameStats instance
   **************************************************************/
    int getSecondClientSocket() const;
   /**************************************************************
   * function name: setSecondClientSocket
   * Input: int secondClientSocket
   * @return void
   * function operation: setts the value of second client socket
   *    as the value received
   **************************************************************/
    void setSecondClientSocket(int secondClientSocket);

   /**************************************************************
   * function name: operator==
   * Input: GameStats gameStats
   * @return bool
   * function operation: returns true if the received gameStats' instance
   *    game name is equal to current instance's game name
   **************************************************************/
    bool operator==(GameStats gameStats) const;

private:
    std::string gameName;
    int firstClientSocket;
    int secondClientSocket;

};


#endif
