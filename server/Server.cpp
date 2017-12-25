/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "Server.h"
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>

using namespace std;

#define MAX_CONNECTED_CLIENTS 10
#define BUFFER_SIZE 4096

Server::Server(int port): port(port), serverSocket(0), clientSocketFirst(-1), clientSocketSecond(-1){
}
void Server::start() {

    // Create a socket point
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        throw "Error opening socket";
    }
    // Assign a local address to the socket
    struct sockaddr_in serverAddress;
    bzero((void *)&serverAddress, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(port);
    if (bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) == -1) {
        throw "Error on binding";
    }
}

void Server::connectToTwoPlayers() {
    // Define the client socket's structures
    struct sockaddr_in clientAddress1;
    socklen_t clientAddressLen1 = sizeof(clientAddress1);
    struct sockaddr_in clientAddress2;
    socklen_t clientAddressLen2 = sizeof(clientAddress2);
    this->clientSocketFirst = -1;
    this->clientSocketSecond = -1;

    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    cout << "Waiting for client connections..." << endl;

    while (this->clientSocketFirst == -1) {
        // trying to accept a new sender client connection
        this->clientSocketFirst = accept(serverSocket, (struct sockaddr *) &clientAddress1, &clientAddressLen1);
    }
    cout << "first player connected" << endl;
    while (this->clientSocketSecond == -1) {
        // trying to accept a new sender client connection
        this->clientSocketSecond = accept(serverSocket, (struct sockaddr *) &clientAddress2, &clientAddressLen2);
    }
    cout << "second player connected\n" << endl;

}

void Server::letPlayersPlayAGame() {
    //if there are less than two players that the server established connection with
    if (this->clientSocketFirst == -1 || this->clientSocketSecond == -1)
        throw "the server needs to connect to two players in order for a game to take place";

    WhichPlayer whosTurn = First;
    int numberOfBytesTransferred;
    char buffer[BUFFER_SIZE];
    const char NoMove[] = "NoMove";
    const char End[] = "End";
    buffer[0] = '0' + First;
    buffer[1] = '\n';
    numberOfBytesTransferred = write(this->clientSocketFirst, buffer, sizeof(buffer));
    if (numberOfBytesTransferred == -1) {
        throw "Error in initial writing to first player";
    }
    buffer[0] = '0' + Second;
    numberOfBytesTransferred = write(this->clientSocketSecond, buffer, sizeof(buffer));
    if (numberOfBytesTransferred == -1) {
        throw "Error in initial writing to second player";
    }
    while (true) {
        memset(buffer, '\0',
               BUFFER_SIZE);
        if (whosTurn == First) {
            numberOfBytesTransferred = read(this->clientSocketFirst, buffer, BUFFER_SIZE);
            //checking if input from client is valid (received)
            if (this->errorInReadingFromCLient(numberOfBytesTransferred)) {
                //error detected
                break;
            }
            if (strcmp(buffer, NoMove) == 0) {
                this->switchTurn(whosTurn);
                continue;
            }
            if (strcmp(buffer, End) == 0) {
                break;
            }
            numberOfBytesTransferred = write(this->clientSocketSecond, buffer, numberOfBytesTransferred);
            if (numberOfBytesTransferred == -1) {
                cout << "Error writing to second player" << endl;
                break;
            }
        } else {
            numberOfBytesTransferred = read(this->clientSocketSecond, buffer, BUFFER_SIZE);
            //checking if input from client is valid (received)
            if (this->errorInReadingFromCLient(numberOfBytesTransferred)) {
                //error detected
                break;
            }
            if (strcmp(buffer, "NoMove") == 0) {
                this->switchTurn(whosTurn);
                continue;
            }
            if (strcmp(buffer, "End") == 0) {
                break;
            }
            numberOfBytesTransferred = write(this->clientSocketFirst, buffer, numberOfBytesTransferred);
            if (numberOfBytesTransferred == -1) {
                cout << "Error writing to first player" << endl;
                break;
            }
        }
        this->switchTurn(whosTurn);
    }
    cout << "disconnecting from clients\n" << endl;
    close(this->clientSocketFirst);
    close(this->clientSocketSecond);
}

bool Server::errorInReadingFromCLient(int numOfBytesReceived) const{
    bool returnVal = false;
    switch(numOfBytesReceived) {
        case -1:
            cout << "Error reading from client" << endl;
            returnVal = true;
            break;
        case 0:
            cout << "Client disconnected" << endl;
            returnVal = true;
            break;
        default:
            //reading from client succeded
            break;
    }
    return returnVal;
}

void Server::switchTurn(WhichPlayer &turn) const{
    switch (turn) {
        case First:
            turn = Second;
            break;
        case Second:
            turn = First;
            break;
        default:
            break;
    }
}


void Server::stop() {
    close(serverSocket);
}