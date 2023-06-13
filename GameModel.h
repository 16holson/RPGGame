#ifndef GAMEMODEL_H
#define GAMEMODEL_H

#include <string>
#include "PlayerCharacter.h"
#include "GameMap.h"

class GameModel
{
    public:
        GameModel();
        void setPlayerCharacter(PlayerCharacter* playerCharacter);
        PlayerCharacter* getPlayerCharacter();
        void setCurrentLocation(Location* location);
        Location* getCurrentLocation();
        void setGameMap(GameMap* gameMap);
        GameMap* getGameMap();
        bool movePlayer(std::string direction);
        void addItemToLocation(Item* item);
        void removeItemFromLocation(Item* item);
        void addItemToPlayerInventory(Item* item);
        void removeItemFromPlayerInventory(Item* item);
        bool attackEnemy(Enemy* enemy);
    private:
        PlayerCharacter* playerCharacter;
        Location* currentLocation;
        GameMap* gameMap;
};
#endif