#ifndef GAMEMAP_H
#define GAMEMAP_H

#include <vector>
#include "Location.h"

class GameMap
{
    public:
        GameMap();
        void addLocation(Location* location);
        Location* getLocationByName(std::string name);
        std::vector<Location*> getLocations();
    private:
        std::vector<Location*> locations;
};

#endif