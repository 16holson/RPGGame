#include "PlayerCharacter.h"

PlayerCharacter::PlayerCharacter(std::string name, int maxHealth, int attackPower)
{
    this->name = name;
    this->maxHealth = maxHealth;
    this->currentHealth = maxHealth;
    this->attackPower = attackPower;
}
std::string PlayerCharacter::getName()
{
    return name;
}
int PlayerCharacter::getMaxHealth()
{
    return maxHealth;
}
int PlayerCharacter::getCurrentHealth()
{
    return currentHealth;
}
int PlayerCharacter::getAttackPower()
{
    return attackPower;
}

void PlayerCharacter::takeDamage(int damage)
{
    currentHealth -= damage;
    if(currentHealth < 0)
    {
        currentHealth = 0;
    }
}
void PlayerCharacter::addItemToInventory(Item* item)
{
    inventory.push_back(item);
}
void PlayerCharacter::removeItemFromInventory(Item* item)
{
    for(int i = 0; i < inventory.size(); i++)
    {
        if(inventory[i] == item)
        {
            inventory.erase(inventory.begin() + i);
            break;
        }
    }
}
std::vector<Item*> PlayerCharacter::getInventory()
{
    return inventory;
}

Item* PlayerCharacter::getItemByName(std::string name)
{
    for(int i = 0; i < inventory.size(); i++)
    {
        if(inventory[i]->getName() == name)
        {
            return inventory[i];
        }
    }
    return nullptr;
}