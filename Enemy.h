#ifndef ENEMY_H
#define ENEMY_H

#include <string>

class Enemy
{
    public:
        Enemy(std::string name, int maxHealth, int attackPower);
        std::string getName();
        int getMaxHealth();
        int getCurrentHealth();
        int getAttackPower();
        void takeDamage(int damage);
        bool isDead();
    private:
        std::string name;
        int maxHealth;
        int currentHealth;
        int attackPower;
};

#endif