#ifndef DUNGEON_H_INCLUDED
#define DUNGEON_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <exception>
#include <cstdio>
#include <cstdlib>
#include "Player.h"
#include "Monster.h"
#include "NPC.h"
#include "Home.h"
#include "Room.h"
#include "Factory.h"
//#include "Record.h"

#include<stdlib.h>
#include<stdio.h>
using namespace std;

class Dungeon{
private:
    Player* player;
    Room* room;
    Home* home;
    NPC* npc;
    Monster* monster7;
    Monster* monster13;
    Monster* monster16;
    Monster* monster17;
    Monster* monster22;
    Monster* boss;
    int round;
public:
    Dungeon();

    Room* getRoom(int);

    Room* getHome();

    Player* getPlayer();

    /* Create a new player, and give him/her basic status */
    void createPlayer();

    void setMember();

    /* Create a map, which include several different rooms */
    void createMap();

    void printTitle();

    void printMap();
    void printMoveMap();

    char fight(Player*, Monster*);

    /* Deal with player's moving action */
    void handleMovement();

    /* Deal with player's interaction with objects in that room */
    void handleEvent();


    /* Deal with all game initial setting       */
    /* Including create player, create map etc  */
    void startGame();

    /* Check whether the to end the game*/
    bool checkGameLogic();

    /*he/she dead */
    bool isAlive();

    /* Deal with the whole game process */
    void runDungeon();

    void resetRound();
    int getRound();

    void homeEvent();


};


#endif // DUNGEON_H_INCLUDED
