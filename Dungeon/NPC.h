#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include "Object.h"
#include "Player.h"
#include<iostream>
#include<string>
using namespace std;

class NPC: public Object{
public:
    NPC();
    NPC(bool, bool, bool, bool);
    char response();
    char response(int, string);
    friend class Dungeon;
private:
    bool askCopper;
    bool askLadder;
    bool askFire;
    bool askFireAttack;
};

#endif // NPC_H_INCLUDED
