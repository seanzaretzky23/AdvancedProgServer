/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "Server.h"
using namespace std;

#define MAX_CONNECTED_CLIENTS 10
#define BUFFER_SIZE 4096

struct InfoForHandleClient {
    int clientSocket;
    CommandsManager *commandsManager;
};

Server::Server(int port): port(port), serverSocket(0){
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

void Server::acceptPlayersConnections() {

    vector<pthread_t *> threads;
    //need to remove this and handle this all in handle client !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    InfoForHandleClient infoForHandleClient;
    infoForHandleClient.commandsManager = &(this->commandsManager);
    //need to remove this and handle this all in handle client !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    while (true) {
        // Define the client socket's structures
        struct sockaddr_in clientAddress;
        socklen_t clientAddressLen = sizeof(clientAddress);
        int clientSocket = -1;

        cout << "Waiting for client connections..." << endl;

        // trying to accept a new sender client connection
        clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);

        cout << "client connection established" << endl;
        if (clientSocket == -1) {
            throw "Error on accept";
        }
        pthread_t clientRequest;
        infoForHandleClient.clientSocket = clientSocket;
        int rc = pthread_create(&clientRequest, NULL, handleClient, &infoForHandleClient);
        if (rc) {
            cout << "Error: unable to create \"accepting clients\" thread, " << rc << endl;
            continue;
        }
        threads.push_back(&clientRequest);
        /*
        // Close communication with the client
        close(clientSocket); !!!!!!dont think it needs to be here
         */
    }

}

void *Server::handleClient(void *info) {
    InfoForHandleClient *infoForHandleClient = (InfoForHandleClient *)info;
    int clientSocket = infoForHandleClient->clientSocket;
    CommandsManager *comManager = infoForHandleClient->commandsManager;
    int numberOfBytesTransferred;
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);
    numberOfBytesTransferred = read(clientSocket, buffer, BUFFER_SIZE);
    //checking if input from client is valid (received)
    bool readingFailed = errorInReadingFromClient(numberOfBytesTransferred);
    if (!readingFailed) {
        StringCommandParser commandParser;
        StringCommandParser::comData commandData = commandParser.strToNameAndArgc(string(buffer));
        string command = commandData.comName;
        vector<string> commandArgs = commandData.comArgs;
        comManager->executeCommand(command, commandArgs, clientSocket);
    }
}

void Server::letPlayersPlayAGame() {
    /*
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
     */
}

bool Server::errorInReadingFromClient(int numOfBytesReceived){
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