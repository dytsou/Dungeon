#ifndef MONSTER_H_INCLUDED
#define MONSTER_H_INCLUDED

#include"GameCharacter.h"
#include<iostream>
using namespace std;

class Monster: public GameCharacter{
public:
    Monster();
    Monster(string, int, string, int, int, int, int, int);
    char response();
    int locate;
};

#endif // MONSTER_H_INCLUDED
