#include "Room.h"

Room::Room():
    Object("NoName",0,"room"){
    this->state = '-';
    this->index = -1;
    this->visible = false;
}

Room::Room(int index, char state, bool visible):
    Object("NoName",0,"room"){
    this->state = state;
    this->index = index;
    this->visible = visible;
}

char Room::response(){
    return '0';
}
