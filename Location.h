#ifndef LOCATION_H
#define LOCATION_H

#include <string>
#include <vector>
#include <map>
#include "Item.h"
#include "Enemy.h"

class Location
{
    public:
        Location(std::string name, std::string description);
        std::string getName();
        std::string getDescription();
        void addNeighbor(std::string direction, Location* neighbor);
        Location* getNeighbor(std::string direction);
        void addItem(Item* item);
        void removeItem(Item* item);
        std::vector<Item*> getItems();
        void addEnemy(Enemy* enemy);
        void removeEnemy(Enemy* enemy);
        std::vector<Enemy*> getEnemies();
        Item* getItemByName(std::string name);
        Enemy* getEnemyByName(std::string name);
    private:
        std::string name;
        std::string description;
        std::vector<Item*> items;
        std::vector<Enemy*> enemies;
        std::map<std::string, Location*> neighbors;
};

#endif