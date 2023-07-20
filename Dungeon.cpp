#include "Dungeon.h"
#include "Home.h"

Dungeon::Dungeon(){

}

Room* Dungeon::getRoom(int i){
    return &room[i];
}

Room* Dungeon::getHome(){
    return &room[0];
}

Player* Dungeon::getPlayer(){
    return this->player;
}

void Dungeon::createPlayer(){
    string name;
    std::cout << "Insert your name: ";
    std::cin >> name;
    std::cout << "Hello " << name << endl;
    this->player->setName(name);
}

void Dungeon::setMember(){
    this->player = new Player("NoName", 0, "Villager", 20, 20, 2, 50, 2, 0, 0, 0, 3, 1, false);
    //Player::Player(string name, int Lv, string tag, int maxHealth, int health, int attack,
                    //int attackMiss, int defense, int beAttackMiss, int escape, int money,int nCopper, int nTree, bool haveLadder):
    this->room = (Room*)calloc(25,sizeof(Room));
    for(int i=0; i<25; i++)
    this->npc= new NPC(false,false,false,false);//NPC::NPC(bool askCopper, bool askLadder)
    this->home = new Home(&room[1]);
    this->home->armorFactory = new Factory("ArmorFactory",1,"Factory");
    this->home->arrowFactory = new Factory("ArrowFactory",1,"Factory");
    this->home->magicTower = new Factory("MagicTower",1,"Factory");
    this->home->axeFactory = new Factory("AxeFactory",1,"Factory");
    this->monster7 = new Monster("Lv2",2,"Monster", 100, 100, 10, 10, 7);
    this->monster13 = new Monster("Lv1",1,"Monster", 50, 50, 5, 5, 13);
    this->monster16 = new Monster("Lv3",3,"Monster", 150, 150, 15, 15, 16);
    this->monster17 = new Monster("Lv3",3,"Monster", 150, 150, 15, 15, 17);
    this->monster22 = new Monster("Lv4",4,"Monster", 200, 200, 20, 20, 22);
    this->boss = new Monster("Boss", 6, "Boss", 300, 300, 30, 20, 24);
    this->player->currentRoom = &room[0];
    this->player->previousRoom = nullptr;
    this->player->haveOloo=false;
}

void Dungeon::createMap(){
    //static map
    /*
    H-.-W W-$
      | | |
    C-N-M-C $
    | | | | |
    . S .-M-.
    |     |
    W-M M-L-$
      | |
    $-. M-C-B
    */
    FILE* f;
    f = fopen("map.txt","r");
    for(int i=0;i<25;i++){
        int u, d, l, r;
        char state;
        fscanf(f, "%c%d%d%d%d\n", &state, &u, &d, &l, &r);
        //printf("%d %c %d %d %d %d\n", i, state, u, d, l, r);
        room[i].index=i;
        room[i].state = state;
        room[i].visible=false;
        if(u!=-1) room[i].upRoom = &room[u];
        else room[i].upRoom=nullptr;
        if(d!=-1) room[i].downRoom = &room[d];
        else room[i].downRoom=nullptr;
        if(l!=-1) room[i].leftRoom = &room[l];
        else room[i].leftRoom=nullptr;
        if(r!=-1) room[i].rightRoom = &room[r];
        else room[i].rightRoom=nullptr;
    }
    fclose(f);
    //return home;
}

void Dungeon::printTitle(){
    system("cls");
    cout << "Player: " << player->getName() << "  Career: Lv." << player->getLv() << " " << player->getTag();
    cout << "       Round " << round << endl;
    cout << "Health: " << player->getHealth() << "/" << player->getMaxHealth();
    if(this->player->getTag() != "Villager") cout << "  Money: " << this->player->getMoney();
    if(this->npc->askCopper){
        cout << endl;
        cout << "Copper: " << player->getnCopper();
        cout << "  Wood: " << player->getnTree();
    }
    cout << endl;
    cout << "--------------------------------------------------" << endl;
}

void Dungeon::printMap(){
    cout << "Map:" << endl;
    cout << "  0 1 2 3 4\n0 ";
    this->room[this->player->currentRoom->index].visible = true;
    for(int i=0; i<25; i++){
        if(i==5) cout << "\n" << i/5 << " ";
        else if (i==10) cout << "\n" << i/5 << " ";
        else if (i==15) cout << "\n" << i/5 << " ";
        else if (i==20) cout << "\n" << i/5 << " ";
        if(this->room[i].visible == false) cout << "? ";
        else{
            char state = this->room[i].state;

            if(state == 'c'){
                if(round % 8 ==0){
                    this->room[i].state = 'W';
                    cout << "W ";
                }
                else cout << ". ";
            }
            else if(state == 'w'){
                if(round % 8 ==0){
                    this->room[i].state = 'C';
                    cout << "C ";
                }
                else cout << ". ";
            }
            else if(state == 's'){
                if(round % 10 ==0){
                    this->room[i].state = '$';
                    cout << "$ ";
                }
                else cout << ". ";
            }
            else if(state == 'm'){
                if(round % 60 ==0){
                    this->room[i].state = 'M';
                    cout << "M ";
                }
                else cout << ". ";
            }
            else if(state == 'l') cout  << "# ";
            else if(state == 'L' && player->haveLadder == false) cout << ". ";
            else cout << this->room[i].state << " ";
            //if(this->room[i].rightRoom != nullptr)
                //if(room[i+1] == true) cout << "-";
                //else
        }
    }
    cout << "\nYour location is (" << this->player->currentRoom->index%5 << "," << this->player->currentRoom->index/5 << ")\n\n";
}

void Dungeon::printMoveMap(){
    cout << "Map:" << endl;
    cout << "  0 1 2 3 4\n0 ";
    this->room[this->player->currentRoom->index].visible = true;
    for(int i=0; i<25; i++){
        if(i==5) cout << " Input w to go upper room\n" << i/5 << " ";
        else if (i==10) cout << " Input s to go lower room\n" << i/5 << " ";
        else if (i==15) cout << " Input a to go left  room\n" << i/5 << " ";
        else if (i==20) cout << " Input d to go right room\n" << i/5 << " ";
        if(this->room[i].visible == false) cout << "? ";
        else{
            char state = this->room[i].state;
            if(state == 'c') cout  << ". ";
            else if(state == 'w') cout  << ". ";
            else if(state == 's') cout  << ". ";
            else if(state == 'm') cout  << ". ";
            else if(state == 'l') cout  << "# ";
            else if(state == 'L' && player->haveLadder == false) cout << ". ";
            else cout << this->room[i].state << " ";
            //if(this->room[i].rightRoom != nullptr)
                //if(room[i+1] == true) cout << "-";
                //else
        }
    }
    cout << "\nYour location is (" << this->player->currentRoom->index%5 << "," << this->player->currentRoom->index/5 << ")\n\n";
}


char Dungeon::fight(Player* player, Monster* monster){
    if(monster->getHealth()<=0){
        monster->setHealth(monster->getMaxHealth()*0.8);
    }
    player->response();
    monster->response();
    system("pause");
    while(true){
        cout << endl;
        cout << player->getTag() << " attack. ";
        if(player->getAttackResult()){
            int hurt= player->getAttack()-monster->getDefense();
            if(hurt>0){
                monster->setHealth(monster->getHealth()-hurt);
                cout << "Hurt=" << hurt << endl << endl;
            }
            else cout << "Hurt=0\n\n";
            if(monster->getHealth() <=0){
                cout << "You win!" << endl;
                system("pause");
                return 'W';
                break;
            }
        }
        else cout << "Miss!" << endl << endl;
        player->response();
        monster->response();
        system("pause");
        cout << endl;
        cout << monster->getTag() << " attack. ";
        if(player->getBeAttackResult()){
            int hurt= monster->getAttack()-player->getDefense();
            if(hurt>0){
                    player->setHealth(player->getHealth()-hurt);
                    cout << "Hurt=" <<hurt << endl << endl;
            }
            else cout << "Hurt=0\n\n";
                if(player->getHealth() <= 0){
                system("pause");
                return 'L';
                break;
            }
        }
        else cout << "Miss!" << endl << endl;
        player->response();
        monster->response();
        cout << "\nDo you want to escape? [Y/n] ";
        char ans;
        cin >> ans;
        if(ans == 'Y' || ans == 'y'){
            if(player->getEscapeResult()) {
                    cout << "Escape Success" << endl;
                    system("pause");
                    return 'E';//escape
                    break;
            }
            else cout << "Escape Fail" << endl;
        }
    }
}

void Dungeon::handleMovement(){
    if(player->currentRoom->state != 'B'){
        char wasd;
        cout << "Input:";
        cin >> wasd;
        while(!(player->movement(wasd))){
            cout << "There is a wall." << endl;
            cout << "Input:";
            cin >> wasd;
        }
    }

}

void Dungeon::handleEvent(){
    char state = this->player->currentRoom->state;
/*At home start*/
    if(state == 'H'){
        //update factory, change job, return health
        player->setHealth(player->getMaxHealth());
        cout << "You are at Home" << endl;
        cout << "Enter your Home? [Y/n] ";
        char ans;
        cin >> ans;
        if(ans == 'Y' || ans == 'y'){
            homeEvent();
        }
    }
/*at home end*/
/*empty start*/
    else if(state == '.'){
        static int i=0;
        if(!i)
        {
            cout << "It is an empty space." << endl;
            i++;
            system("pause");
        }
        //nothing to do.
    }
/*copper start*/
    else if(state == 'C'){
        //if no ask NPC, you are an idiot
        //else if you are worker you can mine copper
        if(this->npc->askCopper && this->player->getTag() == "Worker"){
            if(this->player->getnCopper() + this->player->getnTree() < (5+player->getLv()*4)){
                this->player->setnCopper(player->getnCopper()+1);
                if(player->getLv() >= 3 && this->player->getnCopper() + this->player->getnTree() < (5+player->getLv()*4)){
                    this->player->setnCopper(player->getnCopper()+1);
                    cout << "You get 2 Copper" << endl;
                }
                else cout << "You get Copper" << endl;
                this->player->currentRoom->state='c';
            }
            else{
                cout << "Your backpack is full." << endl;
            }
        }
        else cout << "There is a copper mine." << endl;

        system("pause");
    }
    else if(state == 'c'){
        //nothing to do
    }
/*copper end*/
/*tree start*/
    else if(state == 'W'){
        //if no ask NPC, you are an idiot
        //else if you are worker you can cut down tree
        if(this->npc->askCopper && this->player->getTag() == "Worker"){
            if(this->player->getnCopper() + this->player->getnTree() < (5+player->getLv()*4)){
                this->player->setnTree(player->getnTree()+1);
                if(player->getLv() >= 3 && this->player->getnCopper() + this->player->getnTree() < (5+player->getLv()*4)){
                    this->player->setnTree(player->getnTree()+1);
                    cout << "You get 2 Wood" << endl;
                }
                else cout << "You get Wood" << endl;
                this->player->currentRoom->state='w';
            }
            else{
                cout << "Your backpack is full." << endl;
            }
        }
        else cout << "There is a tree." << endl;
        system("pause");
    }
    else if(state == 'w'){
        //nothing to do.
    }
/*tree end*/
/*$ start*/
    else if(state == '$'){
        //collect money
        this->player->setMoney(this->player->getMoney() +1);
        cout << "You get Money" << endl;
        this->player->currentRoom->state='s';
        system("pause");
    }
    else if(state == 's'){
        //nothing to do.
    }
/*$ end*/
/*monster start*/
    else if(state == 'M'){
        //fight monster
        cout << "You enter Monster's room." << endl;
        system("pause");
        system("cls");
        char result;
        switch(player->currentRoom->index){
        case 7:
            result = fight(player, monster7);
            break;
        case 13:
            result = fight(player, monster13);
            break;
        case 16:
            result = fight(player, monster16);
            break;
        case 17:
            result = fight(player, monster17);
            break;
        case 22:
            result = fight(player, monster22);
        default:
            break;
        }
        cout << result;
        if( result =='E'){
            Room* tmp = player->currentRoom;
            player->currentRoom=player->previousRoom;
            player->previousRoom = tmp;
        }
        else if( result == 'W'){
            this->player->currentRoom->state='m';
        }
        else if(result == 'L'){
            player->previousRoom=player->currentRoom;
            player->currentRoom=this->home;
        }

    }
    else if(state == 'm'){
        //nothing to do.
    }
/*moster end*/
/*boss start*/
    else if(state == 'B'){
        //fight boss
        cout << "You enter Boss's room." << endl;
        system("pause");
        system("cls");
        char result = fight(player, boss);
        if( result =='E'){
            Room* tmp = player->currentRoom;
            player->currentRoom = player->previousRoom;
            player->previousRoom = tmp;
        }
        else if(result == 'L'){
            player->previousRoom=player->currentRoom;
            player->currentRoom=this->home;
        }
    }
/*boss end*/
/*shop start*/
    else if(state == 'S'){
        //buy item
        cout << "You are at Shop" << endl;
        cout << "You have $" << player->getMoney() << endl<<endl;
        cout << "\"What do you want to buy?\"" <<endl;
        cout << "\"Copper $1  Wood $1 \""<< endl;
        if(this->npc->askLadder) cout << "\"Ladder $6 Oloo $15\"";
        else cout << "\"Oloo $15\"" << endl;
        int copper,wood;
        if(player->getMoney()>0){
            cout << "Copper for (input number)";
            cin >> copper;
            while(this->player->getnCopper() + this->player->getnTree() < (5+player->getLv()*4) && player->getMoney()>=2 && copper){
                this->player->setnCopper(player->getnCopper()+1);
                this->player->setMoney(player->getMoney()-1);
                copper--;
            }
            cout <<  "Wood for ";
            cin >> wood;
            while(this->player->getnCopper() + this->player->getnTree() < (5+player->getLv()*4) && player->getMoney()>=2 && wood){
                this->player->setnTree(this->player->getnTree()+1);
                this->player->setMoney(player->getMoney()-1);
                wood--;
            }
            if(npc->askLadder && player->getMoney()>=6){
                cout << "Buy Ladder?(One for each time) [Y/n]";
                char ans;
                cin >> ans;
                if(ans == 'Y' || ans == 'y'){
                    this->player->setMoney(player->getMoney()-6);
                    player->haveLadder=true;
                }
            }
            if(player->getMoney()>=15){
                cout << "Buy Oloo?(One for each time) [Y/n]";
                char ans;
                cin >> ans;
                if(ans == 'Y' || ans == 'y'){
                    this->player->setMoney(player->getMoney()-15);
                    player->haveOloo=true;
                }
            }
        }
        else {
            cout << "You have no money?! GET OUT!!" << endl;
            system("pause");
        }
    }
/*shop end*/
/*ladder start*/
    else if(state == 'L'){
        //if no ask NPC, you are an idiot
        //else if you carry ladder, you can place it
        //if you place ladder, you can enter boss room.
        char ans;
        cout << endl;
        if(player->haveLadder){
            cout << "Do you want to place you ladder? [Y/n]";
            cin >> ans;
            if(ans == 'Y' || ans == 'y'){
                cout << "You place your ladder" << endl;
                this->player->getCurrentRoom()->state='l';
                cout << "Enter boss room? [Y/n] ";
                cin >> ans;
                if(ans == 'Y' || ans == 'y'){
                    player->previousRoom = player->currentRoom;
                    player->currentRoom = &(this->room[24]);
                }
            }
        }
    }
    else if(state == 'l'){
        cout << endl;
        char enter;
        cout << "Enter boss room? [Y/n] ";
        cin >> enter;
        if(enter == 'Y' || enter == 'y'){
            player->previousRoom = player->currentRoom;
            player->currentRoom = &(this->room[24]);
        }
    }
/*ladder end*/
/*NPC start*/
    else if(state == 'N'){
        cout << "You met NPC.\n\nNPC:";
        npc->response(player->getLv(), player->getTag());
        system("pause");
    }
    else if(state == 'F' && player->getTag()=="Archer" && npc->askFireAttack){
        cout << "Do you want to light your arrow? [Y/n] ";
        char ans;
        cin >> ans;
        if(ans == 'Y' || ans == 'y') {
            player->setTag("FireArcher");
            player->setAttack(12*player->getLv());
        }
    }
    if(state!= 'H' && state != 'N' && state != 'S' && state != 'F' && player->getTag() == "Wizard" && npc->askFire == true){
        cout << "Do you want to set fire here? [Y/n] ";
        char ans;
        cin >> ans;
        if(ans == 'Y' || ans == 'y') player->currentRoom->state='F';
    }
}
//HandleEvent end

 void Dungeon::startGame(){
    system("cls");
    cout << "\"Welcome to Dungeon.\"" << endl;
    system("pause");
    system("cls");
    cout << "\"Welcome to Dungeon.\"" << endl;
    cout << "\"The game goal is to escape from Dungeon.\"" << endl;
    system("pause");
    system("cls");
    cout << "\"Welcome to Dungeon.\"" << endl;
    cout << "\"The game goal is to escape from Dungeon.\"" << endl;
    cout << "\"But how?\"" << endl;
    system("pause");
    system("cls");
    cout << "\"Welcome to Dungeon.\"" << endl;
    cout << "\"The game goal is to escape from Dungeon.\"" << endl;
    cout << "\"But how?\"" << endl;
    cout << "\"I don't want to tell you.\"" << endl;
    system("pause");
    system("cls");
    cout << "\"Welcome to Dungeon.\"" << endl;
    cout << "\"The game goal is to escape from Dungeon.\"" << endl;
    cout << "\"But how?\"" << endl;
    cout << "\"I don't want to tell you.\"" << endl;
    cout << "\"Enjoy your game.\"" << endl;
    system("pause");
    system("cls");
    setMember();
    createPlayer();
    createMap();
    resetRound();
}

 bool Dungeon::checkGameLogic(){
    /* Check whether the game should end or not */
    if(!(isAlive())) return true;
    if(boss->checkisDead()) return true;
    return false;
}

bool Dungeon::isAlive(){
    if (!(player->checkisDead()))
        return true;
    else
        return false;
}

 void Dungeon::runDungeon(){
    if(this->player->haveOloo){
        static int i=0;
        if(i%2==1) this->round +=1;
        i++;
    }
    else this->round +=1;
    printTitle();
    printMap();
    handleEvent();
    if(!(checkGameLogic()) && player->currentRoom->state != 'B'){
        printTitle();
        printMoveMap();
        handleMovement();
    }
}

void Dungeon::resetRound(){
    this->round = 0;
}

int Dungeon::getRound(){
    return round;
}

void Dungeon::homeEvent(){
        while(true){
            system("cls");
            printTitle();
            char homeOp = home->response(player,npc->askCopper);
            system("cls");
            printTitle();
            //cout << homeOp << endl;
    //change to knight
            if(homeOp == 'k'){//knight
                player->setTag("Knight");
                int lv=home->armorFactory->getLv();
                player->setLv(lv);
                player->setAttack(lv*15);
                player->setDefense(10*lv);
                player->setAttackMiss(30-10*lv);
                player->setBeAttackMiss(5*lv);
                player->setEscape(40+15*lv);
                player->setHealth(70*lv);
                player->setMaxHealth(70*lv);
                printf("You are a Lv.%d knight.\n", lv);
                system("pause");
            }
    //upgrade ArmorFactory
            else if(homeOp == 'A'){//ArmorFactory:3c,1t
                if(home->armorFactory->getLv() < home->armorFactory->getMaxLv()){
                    if(player->getnCopper()){
                        while(home->armorFactory->pushCopper()){
                            player->setnCopper(player->getnCopper()-1);
                            if(player->getnCopper()<=0) break;
                        }
                    }
                    if(player->getnTree()){
                        while(home->armorFactory->pushTree()){
                            player->setnTree(player->getnTree()-1);
                            if(player->getnTree()<=0) break;
                        }
                    }
                    if(this->home->armorFactory->upgradeFactory()) {
                        if(this->home->armorFactory->getLv() == this->home->armorFactory->getMaxLv())
                            cout << "Your Armor Factory has upgraded to Max Lv."<< home->armorFactory->getLv() << " !\n" << endl;
                        else
                            cout << "Your Armor Factory has upgraded to Lv." << home->armorFactory->getLv() << " !\n" << endl;
                        system("pause");
                    }
                    home->armorFactory->response(npc->askCopper);
                }
                else if(home->armorFactory->getLv() >= home->armorFactory->getMaxLv())
                    cout << "Your Armor Factory has reached Max Lv."<< home->armorFactory->getLv() << " !\n" << endl;
                system("pause");
            }
    //change to archer
            else if(homeOp == 'a'){//archer
                player->setTag("Archer");
                int lv=home->arrowFactory->getLv();
                player->setLv(lv);
                player->setAttack(lv*8);//with fire && lv>=3 lv*12
                player->setDefense(4*lv);
                player->setAttackMiss(30-5*lv);
                if(lv!=5) player->setBeAttackMiss(10+5*lv);
                else player->setBeAttackMiss(40);
                player->setEscape(40+10*lv);
                player->setHealth(30+30*lv);
                player->setMaxHealth(30+30*lv);
                printf("You are a Lv.%d archer.\n", lv);
                system("pause");

            }
    //upgrade ArrowFactory
           else if(homeOp == 'R'){//ArrowFactory:1c,2t
                if(home->arrowFactory->getLv() < home->arrowFactory->getMaxLv()){
                    if(player->getnCopper()){
                        while(home->arrowFactory->pushCopper()){
                            player->setnCopper(player->getnCopper()-1);
                            if(player->getnCopper()<=0) break;
                        }
                    }
                    if(player->getnTree()){
                        while(home->arrowFactory->pushTree()){
                            player->setnTree(player->getnTree()-1);
                            if(player->getnTree()<=0) break;
                        }
                    }
                    if(this->home->arrowFactory->upgradeFactory()) {
                        if(this->home->arrowFactory->getLv() == this->home->arrowFactory->getMaxLv())
                            cout << "Your Arrow Factory has upgraded to Max Lv."<< home->arrowFactory->getLv() << " !\n" << endl;
                        else
                            cout << "Your Arrow Factory has upgraded to Lv." << home->arrowFactory->getLv() << " !\n" << endl;
                        system("pause");
                    }
                    home->arrowFactory->response(npc->askCopper);
                }
                else if(home->arrowFactory->getLv() >= home->arrowFactory->getMaxLv())
                    cout << "Your Arrow Factory has reached Max Lv."<< home->arrowFactory->getLv() << " !\n" << endl;
                system("pause");
            }
    //change to wizard
            else if(homeOp == 'z'){//wizard:
                player->setTag("Wizard");
                int lv=home->magicTower->getLv();
                player->setLv(lv);
                player->setAttack(2);
                player->setDefense(2);
                player->setAttackMiss(0);
                player->setBeAttackMiss(5*lv+20);
                player->setEscape(60+10*lv);
                player->setHealth(20*lv);
                player->setMaxHealth(20*lv);
                printf("You are a Lv.%d wizard.\n", lv);
                system("pause");
            }
    //upgrade MagicTower
            else if(homeOp == 'M'){//MagicTower:3t
                if(home->magicTower->getLv() < home->magicTower->getMaxLv()){
                    if(player->getnTree()){
                        while(home->magicTower->pushTree()){
                            player->setnTree(player->getnTree()-1);
                            if(player->getnTree()<=0) break;
                        }
                    }
                    if(this->home->magicTower->upgradeFactory()) {
                        if(this->home->magicTower->getLv() == this->home->magicTower->getMaxLv())
                            cout << "Your Magic Tower has upgraded to Max Lv."<< home->magicTower->getLv() << " !\n" << endl;
                        else
                            cout << "Your Magic Tower has upgraded to Lv." << home->magicTower->getLv() << " !\n" << endl;
                        system("pause");
                    }
                    home->magicTower->response(npc->askCopper);
                }
                else if(home->magicTower->getLv() >= home->magicTower->getMaxLv())
                    cout << "Your Magic Tower has reached Max Lv."<< home->magicTower->getLv() << " !\n" << endl;
                system("pause");
            }
    //change to worker
            else if(homeOp == 'w'){//worker
                player->setTag("Worker");
                int lv = home->axeFactory->getLv();
                player->setLv(lv);
                player->setAttack(2);
                player->setDefense(2);
                player->setAttackMiss(50);
                player->setBeAttackMiss(0);
                player->setEscape(30);
                player->setHealth(60);
                player->setMaxHealth(60);
                printf("You are a Lv.%d worker.\n", lv);
                system("pause");
            }
    //upgrade AxeFactory
            else if(homeOp == 'X'){//AxeFactory:2c,2t
                if(home->axeFactory->getLv() < home->axeFactory->getMaxLv()){
                    if(player->getnCopper()){
                        while(home->axeFactory->pushCopper()){
                            player->setnCopper(player->getnCopper()-1);
                            if(player->getnCopper()<=0) break;
                        }
                    }
                    if(player->getnTree()){
                        while(home->axeFactory->pushTree()){
                            player->setnTree(player->getnTree()-1);
                            if(player->getnTree()<=0) break;
                        }
                    }
                    if(this->home->axeFactory->upgradeFactory()) {
                        if(this->home->axeFactory->getLv() == this->home->axeFactory->getMaxLv())
                            cout << "Your Axe Factory has upgraded to Max Lv."<< home->axeFactory->getLv() << " !\n" << endl;
                        else
                            cout << "Your Axe Factory has upgraded to Lv." << home->axeFactory->getLv() << " !\n" << endl;
                        system("pause");
                    }
                    home->axeFactory->response(npc->askCopper);
                }
                else if(home->axeFactory->getLv() >= home->axeFactory->getMaxLv())
                    cout << "Your Axe Factory has reached Max Lv."<< home->axeFactory->getLv() << " !\n" << endl;
                system("pause");
            }
            else if(homeOp == 'L'){
                player->setnTree(player->getnTree()-5);
                player->haveLadder = true;
                cout << "You get a ladder." << endl;
                system("pause");
            }
            else if(homeOp == 'I')
            {
                int copper,wood;
                cout << "Dump Copper for (input number)";
                cin >> copper;
                while(this->player->getnCopper()>0 && copper){
                    this->player->setnCopper(player->getnCopper()-1);
                    copper--;
                }
                cout <<  "Wood for ";
                cin >> wood;
                while(this->player->getnTree()>0 && wood){
                    this->player->setnTree(this->player->getnTree()-1);
                    wood--;
                }
                system("pause");
            }
    //go on adventure
            else if(homeOp == 'd'){//adventure
            // do nothing
            break;
            }
        }



}
