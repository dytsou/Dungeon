#include "GameCharacter.h"

GameCharacter::GameCharacter(): Object("NoName",0,"NoTag"){
    this->maxHealth = 0;
    this->health = 0;
    this->attack = 0;
    this->defense = 0;
}

GameCharacter::GameCharacter(string name, int Lv, string tag, int maxHealth, int health, int attack, int defense):
    Object(name, Lv, tag){
        this->maxHealth = maxHealth;
        this->health = health;
        this->attack = attack;
        this->defense = defense;
}

void GameCharacter::setMaxHealth(int maxHealth){
     this->maxHealth = maxHealth;
}

void GameCharacter::setHealth(int health){
    this->health = health;
}

void GameCharacter::setAttack(int attack){
    this->attack = attack;
}

void GameCharacter::setDefense(int defense){
    this->defense = defense;
}

int GameCharacter::getMaxHealth(){
    return maxHealth;
}

int GameCharacter::getHealth(){
    return health;
}

int GameCharacter::getAttack(){
    return attack;
}

int GameCharacter::getDefense(){
    return defense;
}

bool GameCharacter::checkisDead(){
    if (this->health <= 0) return true;
    else return false;
}
