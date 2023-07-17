#include "Object.h"
#include "Dungeon.h"
#include "Home.h"
#include <iostream>
using namespace std;

int main()
{
    Dungeon p;
    p.startGame();
    system("pause");
    while(true){
        p.runDungeon();
        if(p.checkGameLogic()) break;
    }
    system("cls");
    if(p.isAlive()){
        cout << "Congradulations!!" <<endl;
        cout << "You spent " << p.getRound() << " rounds to get out of Dungeon." << endl;
    }
    else cout << "You lose!" << endl;
    return 0;
}
