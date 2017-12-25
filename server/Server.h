/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#ifndef ADVANCEDPROGSERVER_SERVER_H
#define ADVANCEDPROGSERVER_SERVER_H
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
    * function operation: connects to two clients
    *************************************************************/
    void connectToTwoPlayers();

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
    int clientSocketFirst; // the socket's file descriptor of the first player to connect to the server!!!!!!!!!!!magic number!!!!!!!!!!!!!!!!!
    int clientSocketSecond; // the socket's file descriptor of the second player to connect to the server!!!!!!!!!!!magic number!!!!!!!!!!!!!!!

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
    bool errorInReadingFromCLient(int numOfBytesReceived) const;
};
#endif //ADVANCEDPROGSERVER_SERVER_H
