#ifndef PLAYERCHARACTER_H
#define PLAYERCHARACTER_H

#include <string>
#include <vector>
#include "Item.h"

class PlayerCharacter
{
    public:
        PlayerCharacter(std::string name, int maxHealth, int attackPower);
        std::string getName();
        int getMaxHealth();
        int getCurrentHealth();
        int getAttackPower();
        void takeDamage(int damage);
        void addItemToInventory(Item* item);
        void removeItemFromInventory(Item* item);
        std::vector<Item*> getInventory();
        Item* getItemByName(std::string name);
    private:
        std::string name;
        int maxHealth;
        int currentHealth;
        int attackPower;
        std::vector<Item*> inventory;
};

#endif