#include "Player.h"
#include "Room.h"

Player::Player():
    GameCharacter("NoName", 0, "Villager", 20, 20, 2, 2){
    this->attackMiss = 50;
    this->beAttackMiss = 0;
    this->escape=0;
    this->money = 0;
    this->nCopper=0;
    this->nTree=0;
    this->haveLadder = false;
}
Player::Player(string name, int Lv, string tag, int maxHealth, int health, int attack, int attackMiss, int defense, int beAttackMiss, int escape, int money,int nCopper, int nTree, bool haveLadder):
     GameCharacter(name, Lv, tag, maxHealth, health, attack, defense){
        this->attackMiss = attackMiss;
        this->beAttackMiss = beAttackMiss;
        this->escape=escape;
        this->money = money;
        this->nCopper=nCopper;
        this->nTree=nTree;
        this->haveLadder = haveLadder;

}

void Player::setCurrentRoom(Room* currentRoom){
    this->currentRoom = currentRoom;
}

void Player::setPreviousRoom(Room* previousRoom){
    this->previousRoom = previousRoom;
}

void Player::setAttackMiss(int attackMiss){
    this->attackMiss = attackMiss;
}

void Player::setBeAttackMiss(int beAttackMiss){
    this->beAttackMiss = beAttackMiss;
}

void Player::setEscape(int escape){
    this->escape=escape;
}

void Player::setMoney(int money){
    this->money = money;
}
void Player::setnCopper(int nCopper){
    this->nCopper = nCopper;
}
void Player::setnTree(int nTree){
    this->nTree = nTree;
}

Room* Player::getCurrentRoom(){
    return currentRoom;
}

Room* Player::getPreviousRoom(){
    return previousRoom;
}

int Player::getAttackMiss(){
    return attackMiss;
}

int Player::getBeAttackMiss(){
    return beAttackMiss;
}

int Player::getMoney(){
    return money;
}
int Player::getnCopper(){
    return nCopper;
}
int Player::getnTree(){
    return nTree;
}

bool Player::getHaveLadder(){
    return haveLadder;
}

bool Player::movement(char c){//if block return F;
    switch(c){
        case 'w':
        case 'W':
            if(currentRoom->upRoom != nullptr){
                previousRoom = currentRoom;
                currentRoom = currentRoom->upRoom;
                return true;
            }
            else return false;
        case 's':
        case 'S':
            if(currentRoom->downRoom != nullptr){
                previousRoom = currentRoom;
                currentRoom = currentRoom->downRoom;
                return true;
            }
            else return false;
        case 'a':
        case 'A':
            if(currentRoom->leftRoom != nullptr){
                previousRoom = currentRoom;
                currentRoom = currentRoom->leftRoom;
                return true;
            }
            else return false;
        case 'd':
        case 'D':
            if(currentRoom->rightRoom != nullptr){
                previousRoom = currentRoom;
                currentRoom = currentRoom->rightRoom;
                return true;
            }
            else return false;
        case '0':
            return true;
        default:
            return false;
    }
}

bool Player::getAttackResult(){
    srand(time(NULL));
    int x = rand() % 100;
    if(x > this->attackMiss) return true;
    else return false;
}

bool Player::getBeAttackResult(){
    srand(time(NULL));
    int x = rand() % 100;
    if(x > this->beAttackMiss) return true;
    else return false;
}

bool Player::getEscapeResult(){
    srand(time(NULL));
    int x = rand() % 100;
    if(x < this->escape) return true;
    else return false;
}

char Player::response(){
    cout << this->getTag() << ":Lv." << this->getLv() << "  Health: " << this->getHealth() << "/" << this->getMaxHealth();
    cout << "  Attack: " << this->getAttack() << " (" << this->getAttackMiss() << "% miss)  Defense: " <<  this->getDefense() << " (" << this->getBeAttackMiss() << "% lucky)\n";
    return '0';
}
