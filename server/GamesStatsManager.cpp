/****************************************************************
* Student name: sean zaretzky(209164086), yaniv zimmer (318849908)
* Course Exercise Group: 03, 05
*****************************************************************/

#include "GamesStatsManager.h"
using namespace std;

GamesStatsManager *GamesStatsManager::instance = 0;

GamesStatsManager::GamesStatsManager() {}

void GamesStatsManager::addGame(GameStats newGame) {
    this->games.push_back(newGame);
}

bool GamesStatsManager::gameExists(std::string gameName) const {
    if (find(this->games.begin(), this->games.end(), GameStats(gameName)) == this->games.end()) {
        return false;
    }
    return true;
}

bool GamesStatsManager::removeGame(std::string gameName) {
    if (this->gameExists(gameName)) {
        this->games.erase(find(this->games.begin(), this->games.end(), GameStats(gameName)));
        return true;
    }
    return false;
}

GamesStatsManager* GamesStatsManager::getInstanceOfGameStatsManager() {
    if (GamesStatsManager::instance == 0)
    {
        GamesStatsManager::instance = new GamesStatsManager;
    }
    return GamesStatsManager::instance;
}

const vector<GameStats> GamesStatsManager::getGames() const {
    vector<GameStats> vec(this->games);
    return vec;
}

GamesStatsManager::~GamesStatsManager() {
    //not sure if its ok to free the allocated memory for the instance here
}