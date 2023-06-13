#include "Location.h"

Location::Location(std::string name, std::string description)
{
    this->name = name;
    this->description = description;
}
std::string Location::getName()
{
    return name;
}
std::string Location::getDescription()
{
    return description;
}
void Location::addNeighbor(std::string direction, Location* neighbor)
{
    neighbors[direction] = neighbor;
}
Location* Location::getNeighbor(std::string direction)
{
    if (neighbors.count(direction) > 0)
    {
        return neighbors[direction];
    }
    return nullptr;
}
void Location::addItem(Item* item)
{
    items.push_back(item);
}
void Location::removeItem(Item* item)
{
    for(int i = 0; i < items.size(); i++)
    {
        if(items[i] == item)
        {
            items.erase(items.begin() + i);
            break;
        }
    }
}
std::vector<Item*> Location::getItems()
{
    return items;
}
void Location::addEnemy(Enemy* enemy)
{
    enemies.push_back(enemy);
}
void Location::removeEnemy(Enemy* enemy)
{
    for(int i = 0; i < enemies.size(); i++)
    {
        if(enemies[i] == enemy)
        {
            enemies.erase(enemies.begin() + i);
            break;
        }
    }
}
std::vector<Enemy*> Location::getEnemies()
{
    return enemies;
}

Item* Location::getItemByName(std::string name)
{
    for(int i = 0; i < items.size(); i++)
    {
        if(items[i]->getName() == name.erase(name.find_last_not_of(" \n\r\t")+1))
        {
            return items[i];
        }
    }
    return nullptr;
}
Enemy* Location::getEnemyByName(std::string name)
{
    for(int i = 0; i < enemies.size(); i++)
    {
        if(enemies[i]->getName() == name.erase(name.find_last_not_of(" \n\r\t")+1))
        {
            return enemies[i];
        }
    }
    return nullptr;
}