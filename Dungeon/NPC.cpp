#include "NPC.h"


NPC::NPC(): Object("NPC",0, "NPC"){
    this->askCopper=false;
    this->askLadder=false;
    this->askFire=false;
    this->askFireAttack=false;
}

NPC::NPC(bool askCopper, bool askLadder,bool askFire, bool askFireAttack): Object("NPC",0,"NPC"){
    this->askCopper=askCopper;
    this->askLadder=askLadder;
    this->askFire=askFire;
    this->askFireAttack=askFireAttack;
}

char NPC::response(){
    return '0';
}

char NPC::response(int Lv, string playerTag){
    if(playerTag == "Villager"){
        cout << "You could dress up in different types of clothing and try to escape the dungeon." << endl;
        cout << "NPC: Quickly go home and dress up!" << endl;
    }
    else if( playerTag == "Knight")
        cout << "You could attack monster that will block you and to attack boss to escape." << endl;
    else if( playerTag == "Archer"){
        static int metArcher=0;
        metArcher++;
        if(Lv < 3  || metArcher%2==1)
            cout << "You could attack monster that will block you and to attack boss to escape." << endl;
        else {
            cout << "Fire can enhance attack." << endl;
            askFireAttack=true;
        }
    }
    else if( playerTag == "Wizard"){
        static int metWizard = 0;
        metWizard++;
        if(metWizard % 3 == 1 && askLadder) cout << "You could froze dwarf to stop him from breaking ladders." << endl;
        else {
                cout << "You could set fire." << endl;
                askFire=true;
        }
    }
    else if( playerTag == "Worker"){
        askCopper=true;
        static int metWorker = 0;
        metWorker++;
        if(metWorker % 3 == 1) cout << "You could cut down tree and mine copper to upgrade factory." << endl;
        else if(metWorker % 3 == 2) cout << "The block where you have mined will grow trees, and where you cut down tree will grow copper" << endl;
        else{
                cout << "You could build ladder to enter boss room quicker." << endl;
                askLadder=true;
        }
    }
    return '0';
}
