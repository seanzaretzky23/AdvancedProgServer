/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef ADVANCEDPROGSERVER_SERVER_H
#define ADVANCEDPROGSERVER_SERVER_H

#include "StringCommandParser.h"
#include "CommandsManager.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string>
#include <iostream>

class Server {
public:
    /**************************************************************
    * function name: Server builder
    * Input: int port
    * @return server instance with the received port
    **************************************************************/
    Server(int port);

    /**************************************************************
    * function name: start
    * Input: no input
    * @return void
    * function operation: starts the server
    **************************************************************/
    void start();

    /**************************************************************
    * function name: connectToTwoPlayers
    * Input: no input
    * @return void
    * function operation: accepts client connections
    *************************************************************/
    void acceptPlayersConnections();

    /******************************************************************
    * function name: letPlayersPlayAGame
    * Input: no input
    * @return void
    * function operation: conducts the game session between two players
    *******************************************************************/
    void letPlayersPlayAGame();

    /************************************************************************
    * function name: stop
    * Input: no input
    * @return void
    * function operation: executes stoping the server and closing connections
    *************************************************************************/
    void stop();
private:
    enum WhichPlayer {First = 1, Second = 2};

    int port;
    int serverSocket; // the socket's file descriptor
    CommandsManager commandsManager;

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
    bool errorInReadingFromClient(int numOfBytesReceived) const;

    void handleClient(int clientSocket);
};
#endif //ADVANCEDPROGSERVER_SERVER_H
