#ifndef ITEM_H  
#define ITEM_H

#include <string>

class Item
{
    public:
        Item(std::string name, std::string description);
        std::string getName();
        std::string getDescription();
    private:
        std::string name;
        std::string description;
};

#endif