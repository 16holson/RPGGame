#include <iostream>
#include <string>
#include "GameModel.h"
#include "GameMap.h"
#include "Location.h"
#include "Item.h"
#include "Enemy.h"

int main()
{
    //Initialize game model
    GameModel gameModel;
    PlayerCharacter* playerCharacter = new PlayerCharacter("Player", 100, 10);
    gameModel.setPlayerCharacter(playerCharacter);

    //Create game map
    GameMap gameMap;

    Location* location1 = new Location("Location 1", "This is location 1.");
    Item* item1 = new Item("Item 1", "This is item 1.");
    location1->addItem(item1);
    gameMap.addLocation(location1);

    Location* location2 = new Location("Location 2", "This is location 2.");
    Item* item2 = new Item("Item 1", "This is item 2.");
    location2->addItem(item2);
    gameMap.addLocation(location2);
    
    Location* location3 = new Location("Location 3", "This is location 3.");
    Item* item3 = new Item("Item 3", "This is item 3.");
    location3->addItem(item3);
    gameMap.addLocation(location3);

    gameModel.setGameMap(&gameMap);
    gameModel.setCurrentLocation(location1);

    //Game loop
    while(true)
    {
        //Print current location and description
        std::cout << "Current location: " << gameModel.getCurrentLocation()->getName() << std::endl;
        std::cout << gameModel.getCurrentLocation()->getDescription() << std::endl;

        //Print items in current location
        std::vector<Item*> items = gameModel.getCurrentLocation()->getItems();
        if(items.size() > 0)
        {
            std::cout << "Items in this location:" << std::endl;
            for(int i = 0; i < items.size(); i++)
            {
                std::cout << "- " << items[i]->getName() << ": " << items[i]->getDescription() << std::endl;
            }
        }

        //Print enemies in current location
        std::vector<Enemy*> enemies = gameModel.getCurrentLocation()->getEnemies();
        if(enemies.size() > 0)
        {
            std::cout << "Enemies in this location:" << std::endl;
            for(int i = 0; i < enemies.size(); i++)
            {
                std::cout << "- " << enemies[i]->getName() << " (HP: " << enemies[i]->getCurrentHealth() << ")" << std::endl;
            }
        }

        //Prompt user for input
        std::cout << "Enter a command (move, take, drop, attack, quit): ";
        std::string command;
        std::cin >> command;

        //Process user input
        if(command == "move")
        {
            std::cout << "Enter a direction (north, south, east, west): ";
            std::string direction;
            std::cin >> direction;
            if(gameModel.movePlayer(direction))
            {
                std::cout << "Moved to " << gameModel.getCurrentLocation()->getName() << std::endl;
            }
            else
            {
                std::cout << "Cannot move in that direction." << std:: endl;
            }
        }
        else if(command == "take")
        {
            std::cout << "Enter an item name: ";
            std::string itemName;
            std::cin >> itemName;
            Item* item = gameModel.getCurrentLocation()->getItemByName(itemName);
            if(item != nullptr)
            {
                gameModel.addItemToPlayerInventory(item);
                gameModel.removeItemFromLocation(item);
                std::cout << "Took " << item->getName() << std::endl;
            }
            else
            {
                std::cout << "Item not found" << std::endl;
            }
        }
        else if(command == "drop")
        {
            std::cout << "Enter an item name: ";
            std::string itemName;
            std::cin >> itemName;
            Item* item = playerCharacter->getItemByName(itemName);
            if(item != nullptr)
            {
                gameModel.addItemToLocation(item);
                gameModel.removeItemFromPlayerInventory(item);
                std::cout << "Dropped" << item->getName() << std::endl;
            }
            else
            {
                std::cout << "Item not found." << std::endl;
            }
        }
        else if(command == "attack")
        {
            std::cout << "Enter an enemy name: ";
            std::string enemyName;
            std::cin >> enemyName;
            Enemy* enemy = gameModel.getCurrentLocation()->getEnemyByName(enemyName);
            if(enemy != nullptr)
            {
                if(gameModel.attackEnemy(enemy))
                {
                    std::cout << "Defeated " << enemy->getName() << std::endl;
                }
                else
                {
                    std::cout << "Attacked " << enemy->getName() << " (HP: " << enemy->getCurrentHealth() << ")" << std::endl;
                }
            }
            else
            {
                std::cout << "Enemy not found" << std::endl;
            }
        }
        else if(command == "quit")
        {
            break;
        }
        else
        {
            std::cout << "Invalid command" << std::endl;
        }

        //Check if player is dead
        if(playerCharacter->getCurrentHealth() == 0)
        {
            std::cout << "You have died." << std::endl;
            break;
        }
    }
    return 0;
}
