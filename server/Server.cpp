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

pthread_mutex_t waitingForClientConnectionsMutex;

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

    //need to remove this and handle this all in handle client !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    InfoForHandleClient infoForHandleClient;
    infoForHandleClient.commandsManager = &(this->commandsManager);
    //need to remove this and handle this all in handle client !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // Start listening to incoming connections
    listen(serverSocket, MAX_CONNECTED_CLIENTS);
    pthread_mutex_lock(&waitingForClientConnectionsMutex);
    cout << "Waiting for client connections..." << endl;
    pthread_mutex_unlock(&waitingForClientConnectionsMutex);
    while (true) {
        // Define the client socket's structures
        struct sockaddr_in clientAddress;
        socklen_t clientAddressLen = sizeof(clientAddress);
        int clientSocket = -1;

        //cout << "Waiting for client connections..." << endl;

        // trying to accept a new sender client connection
        clientSocket = accept(serverSocket, (struct sockaddr *) &clientAddress, &clientAddressLen);

        if (clientSocket == -1) {
            throw "Error on accept";
        }
        //cout << "client connection established" << endl;
        pthread_t clientRequest; // maybe need to do it with new because every iteration the variable may be erased!!!!!!!!!!!!!!!!!!!!!!!!!
        infoForHandleClient.clientSocket = clientSocket;
        InfoForHandleClient *info = new InfoForHandleClient;
        info->commandsManager = infoForHandleClient.commandsManager;
        info->clientSocket = infoForHandleClient.clientSocket;
        int rc = pthread_create(&clientRequest, NULL, handleClient, (void *)info); // &infoForHandleClient may cause problems!!!!!!!!!!!!!!!!!!!!
        if (rc) {
            cout << "Error: unable to create \"handle clients\" thread, " << rc << endl;
            close(info->clientSocket);
            delete info;
            continue;
        }
        this->threadsVec.push_back(clientRequest);
    }

}

void *Server::handleClient(void *info) {
    InfoForHandleClient *infoForHandleClient = (InfoForHandleClient *)info;
    int clientSocket = infoForHandleClient->clientSocket;
    CommandsManager *comManager = infoForHandleClient->commandsManager;
    delete (InfoForHandleClient *)info;
    int numberOfBytesTransferred;
    char buffer[BUFFER_SIZE];
    memset(buffer, '\0', BUFFER_SIZE);
    numberOfBytesTransferred = read(clientSocket, buffer, BUFFER_SIZE);
    //checking if input from client is valid (received)
    bool readingFailed = errorInReadingFromClient(numberOfBytesTransferred);
    if (!readingFailed) {
        StringCommandParser commandParser;
        try {
            StringCommandParser::comData commandData = commandParser.strToNameAndArgc(string(buffer));
            string command = commandData.comName;
            vector<string> commandArgs = commandData.comArgs;
            comManager->executeCommand(command, commandArgs, clientSocket);
        } catch(const char *) {
            //invalid command string received from client
            close(clientSocket);
        }
    } else {
        close(clientSocket);
    }
}

bool Server::errorInReadingFromClient(int numOfBytesReceived){
    bool returnVal = false;
    switch(numOfBytesReceived) {
        case -1:
            cout << "Error reading from client" << endl;
            returnVal = true;
            break;
        case 0:
            //cout << "Client disconnected" << endl;
            returnVal = true;
            break;
        default:
            //reading from client succeded
            break;
    }
    return returnVal;
}


void Server::stop() {
    for (vector<pthread_t>::iterator it = this->threadsVec.begin(); it != this->threadsVec.end();) {
        pthread_cancel(*it);
        this->threadsVec.erase(it);
    }
    close(this->serverSocket);
}
