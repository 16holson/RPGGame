#include "GameMap.h"

GameMap::GameMap(){}
void GameMap::addLocation(Location* location)
{
    locations.push_back(location);
}
Location* GameMap::getLocationByName(std::string name)
{
    for(int i = 0; i < locations.size(); i++)
    {
        if(locations[i]->getName() == name)
        {
            return locations[i];
        }
    }
    return nullptr;
}
std::vector<Location*> GameMap::getLocations()
{
    return locations;
}
