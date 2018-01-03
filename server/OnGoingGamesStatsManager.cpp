/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "OnGoingGamesStatsManager.h"

using namespace std;

pthread_mutex_t startGameOnGoingMutex;
pthread_mutex_t removeGameOnGoingMutex;
pthread_mutex_t gettingInstanceOnGoingMutex;
pthread_mutex_t terminateAllGamesOnGoingMutex;

OnGoingGamesStatsManager *OnGoingGamesStatsManager::instance = 0;

OnGoingGamesStatsManager::OnGoingGamesStatsManager() {
    pthread_mutex_init(&startGameOnGoingMutex, 0);
    pthread_mutex_init(&removeGameOnGoingMutex, 0);
    pthread_mutex_init(&gettingInstanceOnGoingMutex, 0);
    pthread_mutex_init(&terminateAllGamesOnGoingMutex, 0);
}

void OnGoingGamesStatsManager::startGame(GameStats *newGameStats) {
    pthread_t threadIdOfNewGame;
    OnGoingGamesInfo *onGoingGamesInfo = new OnGoingGamesInfo;
    onGoingGamesInfo->gameStats = newGameStats;
    onGoingGamesInfo->threadIdOfGame = threadIdOfNewGame;

    int rc = pthread_create(&(onGoingGamesInfo->threadIdOfGame), NULL, startNewGame, (onGoingGamesInfo->gameStats));
    if (rc) {
        cout << "Error: unable to create \"game session for clients (startNewGame)\" thread, " << rc <<
             " in OnGoingGamesStatsManager" << endl;
        //!!!!!!!!!!!!! what to do if a thread cannot be created !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    }
    pthread_mutex_lock(&startGameOnGoingMutex);
    this->onGoingGames.push_back(onGoingGamesInfo);
    pthread_mutex_unlock(&startGameOnGoingMutex);
}

void* OnGoingGamesStatsManager::startNewGame(void *infoForNewGame) {
    GameStats *gameStats = (GameStats *)infoForNewGame;
    GameHandler gameHandler(gameStats);
    gameHandler.letPlayersPlayAGame();
}

void OnGoingGamesStatsManager::stopAndTerminateAllGames() { // check if this method is okay !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    pthread_mutex_lock(&terminateAllGamesOnGoingMutex); //check if the mutex is really needed!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    for (vector<OnGoingGamesInfo *>::iterator it = onGoingGames.begin(); it != onGoingGames.end();) {
            close((*it)->gameStats->getFirstClientSocket());
            close((*it)->gameStats->getSecondClientSocket());
            pthread_cancel((*it)->threadIdOfGame);
            delete (*it)->gameStats;
            delete (*it);
            onGoingGames.erase(it);
            //break;
    }
    pthread_mutex_unlock(&terminateAllGamesOnGoingMutex);
}

bool OnGoingGamesStatsManager::removeGame(const GameStats * const gameStats) {
    bool removed = false;
    pthread_mutex_lock(&removeGameOnGoingMutex);
    for (vector<OnGoingGamesInfo *>::iterator it = onGoingGames.begin(); it != onGoingGames.end();) {
        if (((*it)->gameStats->getGameName() == gameStats->getGameName()) && ((*it)->gameStats->getFirstClientSocket() == gameStats->getFirstClientSocket())
                && ((*it)->gameStats->getSecondClientSocket() == gameStats->getSecondClientSocket())) { // maybe put it in a comparison method in gameStats !!!!!!!!!!!!!!!!
            close((*it)->gameStats->getFirstClientSocket());
            close((*it)->gameStats->getSecondClientSocket());
            delete (*it)->gameStats;
            delete (*it);
            onGoingGames.erase(it);
            removed = true;
            break;
        } else {
            ++it;
        }
    }
    pthread_mutex_unlock(&removeGameOnGoingMutex);
    return removed;
}

OnGoingGamesStatsManager* OnGoingGamesStatsManager::getInstanceOfOnGoingGameStatsManager() { //maybe needed mutex here!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //double check for saving mutex resources
    if (OnGoingGamesStatsManager::instance == 0) {
        pthread_mutex_lock(&gettingInstanceOnGoingMutex);
        if (OnGoingGamesStatsManager::instance == 0) {
            OnGoingGamesStatsManager::instance = new OnGoingGamesStatsManager;
        }
        pthread_mutex_unlock(&gettingInstanceOnGoingMutex);
    }
    return OnGoingGamesStatsManager::instance;
}

OnGoingGamesStatsManager::~OnGoingGamesStatsManager() {
    //not sure if its ok to free the allocated memory for the instance here !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    if (instance != 0) {
        delete instance;
        instance = 0;
    }
}