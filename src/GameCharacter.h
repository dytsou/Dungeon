#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include "Object.h"
#include<iostream>
#include<string>
using namespace std;

class GameCharacter : public Object{
public:
    GameCharacter();
    GameCharacter(string, int, string, int, int, int, int);
    void setMaxHealth(int);
    void setHealth(int);
    void setAttack(int);
    void setDefense(int);
    int getMaxHealth();
    int getHealth();
    int getAttack();
    int getDefense();
    bool checkisDead();
private:
    int maxHealth;
    int health;
    int attack;
    int defense;
};

#endif // GAMECHARACTER_H_INCLUDED
