#include "Object.h"

Object::Object(){
    this->name="NoName";
    this->Lv=0;
    this->tag="NoTag";
}

Object::Object(string name, int Lv, string tag){
    this->name = name;
    this->Lv = Lv;
    this->tag = tag;
}

void Object::setName(string name){
    this->name = name;
}

void Object::setLv(int Lv){
    this->Lv = Lv;
}

void Object::setTag(string tag){
    this->tag = tag;
}

string Object::getName(){
    return this->name;
}

int Object::getLv(){
    return this->Lv;
}

string Object::getTag(){
    return this->tag;
}


