# Dungeon

Implementation detailed

- void startGame(): Deal with all game initial setting, including create player, create map etc.
    - void createPlayer(): Create a new player, ask player what name he/she want.
    - void setMember(): Initialize set member status including name, lv, tag, etc.
    - void createMap(): Create a map, which include several different rooms.
- void runDungeon(): Deal with the whole game process
    - bool checkGameLogic(): Check whether to end the game or not.
    - bool isAlive(): If he/she dead, return true
- void printTitle(), void printMap(), void printMoveMap(): Print Game screen.
- void handleMovement(): Dealing with the player's moving action and updating the current room
- void handleEvent(): Deal with player's interaction with objects in that room
    - Home: void homeEvent(): Including
        - Recover health
        - Change career: including Knight, Archer, Wizard, Worker.
        - Update Factory: including Armor, Arrow, Axe Factories and Magic Tower
        - Build Ladder: use for enter boss room(the goal) quicker.
    - Copper, Wood: Get item which can upgrade Factories
    - Money: Get money to buy items
    - Monster, Boss: char fight(Player*, Monster*): Allows the player to engage in combat with monsters.
    - NPC: Told player what to do to reach his/her goal.
    - Shop: Place to buy your item.
    - Ladder: Only place to place Ladder.

UML Design

![png/image1.png](png/image1.png)

**Results**

![png/image2.jpeg](png/image2.jpeg)

⇧初始畫面

![png/image3.jpeg](png/image3.jpeg)

⇧輸入名稱

![png/image4.jpeg](png/image4.jpeg)

⇧Enter Home?

![png/image5.jpeg](png/image5.jpeg)

⇧移動

![png/image6.jpeg](png/image6.jpeg)

⇧第一次走到Empty space會告訴你這格Empty

![png/image7.jpeg](png/image7.jpeg)

⇧Villager遇到NPC

![png/image8.jpeg](png/image8.jpeg)

⇧進Home，選擇到Factory或Incinerator或繼續冒險

![png/image9.jpeg](png/image9.jpeg)

⇧進Factory選擇，輸入1換角色，輸入2繼續冒險

![png/image10.jpeg](png/image10.jpeg)

⇧換角色結果

![png/image11.jpeg](png/image11.jpeg)

⇧NPC遇到不同角色會有不同對話

![png/image12.jpeg](png/image12.jpeg)

⇧踩到Monster格

![png/image13.jpg](png/image13.jpg)

⇧Fight並成功逃出

![png/image14.jpeg](png/image14.jpeg)

⇧Get Copper

![png/image15.jpeg](png/image15.jpeg)

⇧Get Wood

![png/image16.jpeg](png/image16.jpeg)

⇧撞到牆(該方向為nullptr)

![png/image17.jpeg](png/image17.jpeg)

⇧NPC對話

![png/image18.jpeg](png/image18.jpeg)

⇧NPC對話

![png/image19.jpeg](png/image19.jpeg)

⇧背包滿了

![png/image20.jpeg](png/image20.jpeg)

⇧選擇升級Factory(此選項須問過NPC才會顯示)

![png/image21.jpeg](png/image21.jpeg)

⇧升級成功

![png/image22.jpeg](png/image22.jpeg)

⇧升級至最高級別

![png/image23.jpg](png/image23.jpg)

⇧若工廠升級至最高級別將不會顯示所需升級物資

![png/image24.jpeg](png/image24.jpeg)

⇧當Worker = Lv3時，拿到物品(不含錢)加倍

![png/image25.jpg](png/image25.jpg)

⇧選擇建造Ladder(當Worker = Lv3且Wood>5時顯示此功能)

![png/image26.jpeg](png/image26.jpeg)

⇧Get Ladder

![png/image27.jpeg](png/image27.jpeg)

⇧Wizard = Lv3且問過NPC後可以Set Fire

![png/image28.jpeg](png/image28.jpeg)

⇧NPC對話

![png/image29.jpeg](png/image29.jpeg)

⇧Worker Lv>=3時可以點火(點火會增加攻擊力)

![png/image30.jpg](png/image30.jpg)

⇧Fight and Win

![png/image31.jpeg](png/image31.jpeg)

⇧Get Money

![png/image32.jpeg](png/image32.jpeg)

⇧Ladder格可以置放Ladder，可以快速進出Boss Room

![png/image33.jpeg](png/image33.jpeg)

⇧每60回合Monster會復活

![png/image34.jpeg](png/image34.jpeg)

⇧逃出Dungeon結束畫面