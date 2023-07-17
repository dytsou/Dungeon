#include "Monster.h"

Monster::Monster():
    GameCharacter("NoName",0,"Monster",0,0,0,0){
    this->locate=-1;
}

Monster::Monster(string name, int Lv, string tag, int maxHealth, int health, int attack, int defense, int locate):
    GameCharacter(name, Lv, tag, maxHealth, health, attack, defense){
    this->locate=locate;
}
char Monster::response(){
    cout << this->getTag() << ":Lv." << this->getLv() << "  Health: " << this->getHealth() << "/" << this->getMaxHealth();
    cout << "  Attack: " << this->getAttack() << "  Defense: " <<  this->getDefense() << endl;
    return '0';
}
