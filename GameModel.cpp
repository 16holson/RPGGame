#include "GameModel.h"

GameModel::GameModel()
{
    playerCharacter = nullptr;
    currentLocation = nullptr;
    gameMap = nullptr;
}
void GameModel::setPlayerCharacter(PlayerCharacter* playerCharacter)
{
    this->playerCharacter = playerCharacter;
}
PlayerCharacter* GameModel::getPlayerCharacter()
{
    return playerCharacter;
}
void GameModel::setCurrentLocation(Location* location)
{
    currentLocation = location;
}
Location* GameModel::getCurrentLocation()
{
    return currentLocation;
}
void GameModel::setGameMap(GameMap* gameMap)
{
    this->gameMap = gameMap;
}
GameMap* GameModel::getGameMap()
{
    return gameMap;
}
bool GameModel::movePlayer(std::string direction)
{
    Location* neighbor = currentLocation->getNeighbor(direction);
    if (neighbor != nullptr)
    {
        currentLocation = neighbor;
        return true;
    }
    return false;
}
void GameModel::addItemToLocation(Item* item)
{
    currentLocation->addItem(item);
}
void GameModel::removeItemFromLocation(Item* item)
{
    currentLocation->removeItem(item);
}
void GameModel::addItemToPlayerInventory(Item* item)
{
    playerCharacter->addItemToInventory(item);
}
void GameModel::removeItemFromPlayerInventory(Item* item)
{
    playerCharacter->removeItemFromInventory(item);
}
bool GameModel::attackEnemy(Enemy* enemy)
{
    int damage = playerCharacter->getAttackPower();
    enemy->takeDamage(damage);
    if(enemy->isDead())
    {
        currentLocation->removeEnemy(enemy);
        return true;
    }
    return false;
}

