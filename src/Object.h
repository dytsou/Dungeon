#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED

#include<iostream>
#include<string>
using namespace std;

class Object{
public:
    Object();
    Object(string, int, string);
    void setName(string);
    void setLv(int);
    void setTag(string);
    string getName();
    int getLv();
    string getTag();
    virtual char response()=0;
private:
     string name;
     int Lv;
     string tag;
};

#endif // OBJECT_H_INCLUDED
