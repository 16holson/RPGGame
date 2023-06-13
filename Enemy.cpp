#include "Enemy.h"

Enemy::Enemy(std::string name, int maxHealth, int attackPower)
{
    this->name = name;
    this->maxHealth = maxHealth;
    this->currentHealth = currentHealth;
    this->attackPower = attackPower;
}
std::string Enemy::getName()
{
    return name;
}
int Enemy::getMaxHealth()
{
    return maxHealth;
}
int Enemy::getCurrentHealth()
{
    return currentHealth;
}
int Enemy::getAttackPower()
{
    return attackPower;
}

void Enemy::takeDamage(int damage)
{
    currentHealth -= damage;
    if (currentHealth < 0)
    {
        currentHealth = 0;
    }
}