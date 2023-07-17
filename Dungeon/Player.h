#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "GameCharacter.h"
#include "Room.h"
#include "Factory.h"
#include <cstdlib>
#include<iostream>
#include <time.h>
#include <vector>
using namespace std;

class Player: public GameCharacter{
public:
    Player();
    Player(string, int, string, int, int, int, int, int, int, int, int, int, int, bool);
    void setCurrentRoom(Room*);
    void setPreviousRoom(Room*);
    void setAttackMiss(int);
    void setBeAttackMiss(int);
    void setEscape(int);
    void setMoney(int);
    void setnCopper(int);
    void setnTree(int);
    Room* getCurrentRoom();
    Room* getPreviousRoom();
    int getAttackMiss();
    int getBeAttackMiss();
    int getMoney();
    int getnCopper();
    int getnTree();
    bool getHaveLadder();
    bool movement(char);//if block return F
    bool getAttackResult();
    bool getBeAttackResult();
    bool getEscapeResult();
    char response();
    friend class Dungeon;
private:
    Room* currentRoom;
    Room* previousRoom;
    int attackMiss;
    int beAttackMiss;
    int escape;
    int money;
    int nCopper;
    int nTree;
    bool haveLadder;
    bool haveOloo;
};

#endif // PLAYER_H_INCLUDED
