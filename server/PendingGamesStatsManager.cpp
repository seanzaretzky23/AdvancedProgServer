/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "PendingGamesStatsManager.h"
using namespace std;
#include <iostream>

pthread_mutex_t addGameMutex;
pthread_mutex_t removeGamePendingMutex;
pthread_mutex_t terminateAllGamesPendingMutex;
pthread_mutex_t gettingInstancePendingMutex;
pthread_mutex_t getGamePendingMutex;
pthread_mutex_t gameExistsPendingMutex;
pthread_mutex_t getGamesVecPendingMutex;

PendingGamesStatsManager *PendingGamesStatsManager::instance = 0;

PendingGamesStatsManager::PendingGamesStatsManager() {
    pthread_mutex_init(&addGameMutex, 0);
    pthread_mutex_init(&removeGamePendingMutex, 0);
    pthread_mutex_init(&terminateAllGamesPendingMutex, 0);
    pthread_mutex_init(&gettingInstancePendingMutex, 0);
    pthread_mutex_init(&getGamePendingMutex, 0);
    pthread_mutex_init(&gameExistsPendingMutex, 0);
    pthread_mutex_init(&getGamesVecPendingMutex, 0);
}

void PendingGamesStatsManager::addGame(GameStats newGame) {
    pthread_mutex_lock(&addGameMutex);
    this->games.push_back(newGame);
    pthread_mutex_unlock(&addGameMutex);
}

bool PendingGamesStatsManager::gameExists(std::string gameName) const {
    pthread_mutex_lock(&gameExistsPendingMutex);
    if (find(this->games.begin(), this->games.end(), GameStats(gameName)) == this->games.end()) {
        pthread_mutex_unlock(&gameExistsPendingMutex);
        return false;
    }
    pthread_mutex_unlock(&gameExistsPendingMutex);
    return true;
}

void PendingGamesStatsManager::stopAndTerminateAllGames() {
    pthread_mutex_lock(&terminateAllGamesPendingMutex); //check if the mutex is really needed!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    for (vector<GameStats>::iterator it = games.begin(); it != games.end();) {
        //only need to close first client socket because second client didnt connect yet (the game was in the pending list)
        close(it->getFirstClientSocket());
        games.erase(it);
        //break;
    }
    pthread_mutex_unlock(&terminateAllGamesPendingMutex);
}

bool PendingGamesStatsManager::removeGame(std::string gameName) {
    if (this->gameExists(gameName)) {
        pthread_mutex_lock(&removeGamePendingMutex);
        this->games.erase(find(this->games.begin(), this->games.end(), GameStats(gameName)));
        pthread_mutex_unlock(&removeGamePendingMutex);
        return true;
    }
    return false;
}

GameStats *PendingGamesStatsManager::getGameStatsOfGame(std::string gameName) {
    pthread_mutex_lock(&getGamePendingMutex);
    if (this->gameExists(gameName)) {
        for (vector<GameStats>::iterator it = this->games.begin(); it != this->games.end(); it++) {
            if (it->getGameName() == gameName) {
                GameStats *returnGameStats = new GameStats((*it));
                pthread_mutex_unlock(&getGamePendingMutex); // !!!!!! needed to add before return!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                return returnGameStats;
            }
        }
    }
    pthread_mutex_unlock(&getGamePendingMutex);
    //game with the requested name doesnt exist
    return NULL;
}

PendingGamesStatsManager* PendingGamesStatsManager::getInstanceOfPendingGameStatsManager() {
    //double check for saving mutex resources
    if (PendingGamesStatsManager::instance == 0) {
        pthread_mutex_lock(&gettingInstancePendingMutex);
        if (PendingGamesStatsManager::instance == 0) {
            PendingGamesStatsManager::instance = new PendingGamesStatsManager;
        }
        pthread_mutex_unlock(&gettingInstancePendingMutex);
    }
    return PendingGamesStatsManager::instance;
}

const vector<GameStats> PendingGamesStatsManager::getGames() const {
    pthread_mutex_lock(&getGamesVecPendingMutex);
    vector<GameStats> vec(this->games);
    pthread_mutex_unlock(&getGamesVecPendingMutex);
    return vec;
}

PendingGamesStatsManager::~PendingGamesStatsManager() {
    //not sure if its ok to free the allocated memory for the instance here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    if (instance != 0) {
        delete instance;
        instance = 0;
    }
}