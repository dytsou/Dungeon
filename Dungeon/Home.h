#ifndef HOME_H_INCLUDED
#define HOME_H_INCLUDED

#include"Room.h"
#include"Factory.h"
#include"Player.h"
#include<iostream>
using namespace std;

class Home: public Room{
public:
    Home();
    Home(Room* r);
    char response(Player*,bool);
    Factory* armorFactory;
    Factory* arrowFactory;
    Factory* magicTower;
    Factory* axeFactory;
};



#endif // HOME_H_INCLUDED
