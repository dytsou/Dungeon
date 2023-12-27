#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include "Object.h"
class Room: public Object{
public:
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;
    char state;
    int index;
    bool visible;
    char response();
    Room();
    Room(int, char, bool);
};

#endif // ROOM_H_INCLUDED
