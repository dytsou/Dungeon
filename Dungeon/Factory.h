#ifndef FACTORY_H_INCLUDED
#define FACTORY_H_INCLUDED

#include"Object.h"
#include<stdlib.h>
#include<cstdio>
#include<iostream>
using namespace std;

class Factory: public Object{
public:
    Factory();
    Factory(string, int, string);
    Factory(string, int, string, int, int);
    bool pushCopper();//T: has push
    bool pushTree();
    void setnCopper(int);
    void setnTree(int);
    int getnCopper();
    int getnTree();
    int getMaxCopper();
    int getMaxTree();
    int getMaxLv();
    bool upgradeFactory();
    char response();
    char response(bool);
private:
    int nCopper;
    int nTree;
    int maxCopper;
    int maxTree;
    int maxLv;
};

#endif // FACTORY_H_INCLUDED
