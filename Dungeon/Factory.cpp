#include"Factory.h"

Factory::Factory(): Object("NoName", 0, "Factory"){
    this->maxCopper=0;
    this->maxTree=0;
    this->nCopper=0;
    this->nTree=0;
    this->maxLv=0;
}

Factory::Factory(string name, int Lv, string tag): Object(name, Lv, tag){
    if(name == "ArmorFactory"){//3c,1t
        this->maxCopper=3;
        this->maxTree=1;
        this->maxLv=3;
    }
    else if(name == "ArrowFactory"){//1c,2t
        this->maxCopper=1;
        this->maxTree=2;
        this->maxLv=5;
    }
    else if(name == "MagicTower"){//3t
        this->maxCopper=0;
        this->maxTree=3;
        this->maxLv=3;
    }
    else if(name == "AxeFactory"){//2c,2t
        this->maxCopper=2;
        this->maxTree=2;
        this->maxLv=3;
    }
    this->nCopper=0;
    this->nTree=0;
}

Factory::Factory(string name, int Lv, string tag, int nCopper,int nTree):
    Object(name, Lv, tag){
        if(name == "ArmorFactory"){//3c,1t
        this->maxCopper=3;
        this->maxTree=1;
    }
    else if(name == "ArrowFactory"){//1c,2t
        this->maxCopper=1;
        this->maxTree=2;
    }
    else if(name == "MagicTower"){//3t
        this->maxCopper=0;
        this->maxTree=3;
    }
    else if(name == "AxeFactory"){//2c,2t
        this->maxCopper=2;
        this->maxTree=2;
    }
        this->nCopper=nCopper;
        this->nTree=nTree;
}

void Factory::setnCopper(int nCopper){
    this->nCopper = nCopper;
}

void Factory::setnTree(int nTree){
    this->nTree = nTree;
}

int Factory::getnCopper(){
    return nCopper;
}

int Factory::getnTree(){
    return nTree;
}

int Factory::getMaxCopper(){
    return maxCopper;
}

int Factory::getMaxTree(){
    return maxTree;
}

int Factory::getMaxLv(){
    return maxLv;
}

bool Factory::pushCopper(){
     if(nCopper < maxCopper && getLv()<getMaxLv()){//3c,1t
        this->nCopper++;
        return true;
     }
     else return false;
}

bool Factory::pushTree(){
     if(nTree < maxTree && getLv()<getMaxLv()){//3c,1t
        this->nTree++;
        return true;
     }
     else return false;
}

bool Factory::upgradeFactory(){
    if(nCopper == maxCopper && nTree == maxTree && getLv()<getMaxLv()){
        setLv(getLv() +1);
        nCopper=0;
        nTree=0;
        return true;
    }
    else return false;
}

char Factory::response(){
    return '0';
}

char Factory::response(bool askCopper){
    cout << getName() << ": Lv." << getLv();
    if(askCopper && getLv()<getMaxLv()) printf(" Copper: %d/%d Wood: %d/%d", getnCopper(), getMaxCopper(), getnTree(), getMaxTree());
    cout << endl;
    return '0';
}
