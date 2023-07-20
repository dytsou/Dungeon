#include"Home.h"

Home::Home(){

}

Home::Home(Room* r){
    this->upRoom = nullptr;
    this->downRoom = nullptr;
    this->leftRoom = nullptr;
    this->rightRoom = r;
    this->index = 0;
    this->state='H';
    this->visible=true;
}

char Home::response(Player* player, bool askCopper){
    char factoryOp;
        armorFactory->response(askCopper);
        arrowFactory->response(askCopper);
        magicTower->response(askCopper);
        axeFactory->response(askCopper);
        if(player->getTag()=="Worker" && player->getLv() >= 3 && player->getnTree()>=5 && player->getHaveLadder() == false)
            cout << "Input 0 to use 5 wood to build a ladder."<< endl;
        cout << "Input 1 to go to Armor Factory" << endl;
        cout << "Input 2 to go to Arrow Factory" << endl;
        cout << "Input 3 to go to Magic Tower" << endl;
        cout << "Input 4 to go to Axe Factory" << endl;
        cout << "Input 5 to go to Incinerator to dump your materials" << endl;
        cout << "Input 6 to go on your adventure" << endl;
        cout << "Input:";
        cin >> factoryOp;
    char inFactoryOP;
        system("cls");
        cout << "Player: " << player->getName() << "  Career: Lv." << player->getLv() << " " << player->getTag() << endl;
        cout << "Health: " << player->getHealth() << "/" << player->getMaxHealth();
        if(player->getTag() != "Villager") cout << "  Money: " << player->getMoney();
        if(askCopper){
            cout << endl;
            cout << "Copper: " << player->getnCopper();
            cout << "  Wood: " << player->getnTree();
        }
        cout << endl;
        cout << "----------------------------------------" << endl;
    if(factoryOp == '1'){
        //Armor Factory
        armorFactory->response(askCopper);
        //cout << "You are at Armor Factory" << endl;
        if(askCopper && armorFactory->getLv()<armorFactory->getMaxLv()){
            cout << "Input 1 to become a Lv." << armorFactory->getLv() << " knight." << endl;
            cout << "Input 2 to go to upgrade the factory" << endl;
            cout << "Input 3 to go on your adventure" << endl;
            cout << "Input:";
            cin >> inFactoryOP;
            if(inFactoryOP == '1') return 'k';//"knight";
            else if(inFactoryOP == '2') return 'A';//"ArmorFactory";
            else return 'd';
        }
        else{
            cout << "Input 1 to become a Lv." << armorFactory->getLv() << " knight." << endl;
            cout << "Input 2 to go on your adventure" << endl;
            cout << "Input:";
            cin >> inFactoryOP;
            if(inFactoryOP == '1') return 'k';//"knight";
            else return 'd';
        }
    }
    else if(factoryOp == '2'){
        //Arrow Factory
            arrowFactory->response(askCopper);
            if(askCopper && arrowFactory->getLv()<arrowFactory->getMaxLv()){
                cout << "Input 1 to become a Lv." << arrowFactory->getLv() << " archer." << endl;
                cout << "Input 2 to go to upgrade the factory" << endl;
                cout << "Input 3 to go on your adventure" << endl;
                cout << "Input:";
                cin >> inFactoryOP;
                if(inFactoryOP == '1') return 'a';//"archer";
                else if(inFactoryOP == '2') return 'R';//"ArrowFactory";
                else return 'd';
            }
            else{
                cout << "Input 1 to become a Lv." << arrowFactory->getLv() << " archer." << endl;
                cout << "Input 2 to go on your adventure" << endl;
                cout << "Input:";
                cin >> inFactoryOP;
                if(inFactoryOP == '1') return 'a';//"archer";
                else return 'd';
            }
    }

    else if(factoryOp == '3'){
        //Magic Tower
            magicTower->response(askCopper);
            if(askCopper && magicTower->getLv()<magicTower->getMaxLv()){
                cout << "Input 1 to become a Lv." << magicTower->getLv() << " wizard." << endl;
                cout << "Input 2 to go to upgrade the factory" << endl;
                cout << "Input 3 to go on your adventure" << endl;
                cout << "Input:";
                cin >> inFactoryOP;

                if(inFactoryOP == '1') return 'z';//"wizard";
                else if(inFactoryOP == '2') return 'M';//"MagicTower";
                else return 'd';
            }
            else{
                cout << "Input 1 to become a Lv." << magicTower->getLv() << " wizard." << endl;
                cout << "Input 2 to go on your adventure" << endl;
                cout << "Input:";
                cin >> inFactoryOP;
                if(inFactoryOP == '1') return 'z';//"wizard";
                else return 'd';
            }

    }
    else if(factoryOp == '4'){
        //Axe Factory
            axeFactory->response(askCopper);
            if(askCopper && axeFactory->getLv()<axeFactory->getMaxLv()){
                cout << "Input 1 to become a Lv." << axeFactory->getLv() << " worker." << endl;
                cout << "Input 2 to go to upgrade the factory" << endl;
                cout << "Input 3 to go on your adventure" << endl;
                cout << "Input:";
                cin >> inFactoryOP;
                if(inFactoryOP == '1') return 'w';//"worker";
                else if(inFactoryOP == '2') return 'X';//"AxeFactory";
                else  return 'd';
            }
            else{
                cout << "Input 1 to become a Lv." << axeFactory->getLv() << " worker." << endl;
                cout << "Input 2 to go on your adventure" << endl;
                cout << "Input:";
                cin >> inFactoryOP;
                if(inFactoryOP == '1') return 'w';//"worker";
                else  return 'd';
            }

    }
    else if(factoryOp == '5') return 'I';// Incinerator
    else if(factoryOp == '0' && player->getTag()=="Worker" && player->getLv()==axeFactory->getMaxLv()
            && player->getnTree()>=5 && player->getHaveLadder() == false)
        return 'L';//ladder;
    else return 'd';//"adventure";
}
