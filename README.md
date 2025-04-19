# Dungeon

A text-based dungeon adventure game where players explore rooms, fight monsters, and manage resources to reach the boss room.

## Features

- **Multiple Character Classes**
  - Knight: Balanced warrior
  - Archer: Ranged specialist
  - Wizard: Magic user
  - Worker: Resource management specialist

- **Resource Management**
  - Collect copper and wood for factory upgrades
  - Manage money for item purchases
  - Build ladders for quick boss room access

- **Factory System**
  - Upgrade various factories (Armor, Arrow, Axe)
  - Build Magic Towers
  - Special abilities unlock at higher levels

- **Dynamic Gameplay**
  - Monster encounters
  - NPC interactions with class-specific dialogues
  - Shop system for item purchases
  - Monster respawn system (every 60 turns)

## Building the Game

### Prerequisites
- C++ compiler (g++ recommended)
- Make

### Build Instructions
1. Clone the repository
2. Run `make` to build the game
3. Execute the game with `./dungeon`

To clean build files:
```bash
make clean
```

## Project Structure

```
Dungeon/
├── src/                      # Source code files
│   ├── main.cpp              # Program entry point (24 lines)
│   ├── Dungeon.cpp           # Main game engine and logic (796 lines)
│   ├── Dungeon.h             # Game engine class definition (89 lines)
│   ├── Player.cpp            # Player character implementation (153 lines)
│   ├── Player.h              # Player class definition (52 lines)
│   ├── GameCharacter.cpp     # Base class for all characters (54 lines)
│   ├── GameCharacter.h       # Character base class definition (30 lines)
│   ├── Monster.cpp           # Enemy implementation (17 lines)
│   ├── Monster.h             # Monster class definition (17 lines)
│   ├── NPC.cpp               # Non-player character interactions (61 lines)
│   ├── NPC.h                 # NPC class definition (25 lines)
│   ├── Room.cpp              # Room system and navigation (20 lines)
│   ├── Room.h                # Room class definition (20 lines)
│   ├── Home.cpp              # Home base implementation (144 lines)
│   ├── Home.h                # Home class definition (24 lines)
│   ├── Factory.cpp           # Resource and upgrade management (122 lines)
│   ├── Factory.h             # Factory system class definition (36 lines)
│   ├── Object.cpp            # Game object base implementation (40 lines)
│   ├── Object.h              # Object base class definition (26 lines)
│   └── map.txt               # Map layout configuration file (25 lines)
│
├── obj/                      # Object files generated during compilation
│   ├── main.o                # Compiled main.cpp
│   ├── Dungeon.o             # Compiled Dungeon.cpp
│   ├── Player.o              # Compiled Player.cpp
│   ├── GameCharacter.o       # Compiled GameCharacter.cpp
│   ├── Monster.o             # Compiled Monster.cpp
│   ├── NPC.o                 # Compiled NPC.cpp
│   ├── Room.o                # Compiled Room.cpp
│   ├── Home.o                # Compiled Home.cpp
│   ├── Factory.o             # Compiled Factory.cpp
│   └── Object.o              # Compiled Object.cpp
│
├── png/                      # Screenshots and game images for documentation
│
├── Makefile                  # Build configuration for compiling the game
├── dungeon.exe               # Executable game file
└── README.md                 # Project documentation
```

## Game Structure

### Core Components
- `Dungeon`: Main game engine
- `Player`: Player character management
- `Room`: Room system and navigation
- `Factory`: Resource and upgrade management
- `GameCharacter`: Base class for all characters
- `Monster`: Enemy system
- `NPC`: Non-player character interactions

### Game Flow
1. Start game and create player
2. Explore rooms and collect resources
3. Interact with NPCs for guidance
4. Upgrade factories and build ladders
5. Fight monsters and reach the boss room

## Screenshots

### Game Start
![Game Start](png/image2.jpeg)
- Initial game screen with title and welcome message
- Displays the game's main menu interface
- Shows available options to begin the adventure

### Character Selection
![Character Selection](png/image3.jpeg)
- Player name input screen
- Choose your character's name before starting
- Sets up your initial character identity

### Room Navigation
![Room Navigation](png/image4.jpeg)
- Main game interface showing room layout
- Displays available movement directions
- Shows current room status and surroundings

### Home Interface
![Home Interface](png/image5.jpeg)
- Safe haven where players can:
  - Rest and recover health
  - Access factory upgrades
  - Change character class
  - Build ladders (requires Worker level 3)

### Combat System
![Combat System](png/image13.jpg)
- Monster encounter interface
- Shows combat options and status
- Displays health, attack, and defense information
- Allows for strategic combat decisions

### Factory Management
![Factory Management](png/image9.jpeg)
- Factory upgrade interface showing:
  - Available factory types (Armor, Arrow, Axe)
  - Current factory levels
  - Required resources for upgrades
  - Special abilities unlocked at higher levels

### Resource Collection
![Resource Collection](png/image15.jpeg)
- Resource gathering interface
- Shows collected items (copper, wood)
- Displays inventory status
- Resource management system

### Boss Room Access
![Boss Room Access](png/image33.jpeg)
- Final challenge interface
- Boss room entrance
- Shows ladder placement option
- Displays final battle preparation

### Additional Game Features
![NPC Interaction](png/image8.jpeg)
- NPC dialogue system
- Class-specific conversations
- Quest information and guidance

![Shop Interface](png/image12.jpeg)
- Item purchase system
- Available equipment and upgrades
- Currency management

![Level Up System](png/image10.jpeg)
- Character progression
- Level-based abilities
- Class-specific upgrades

![Special Abilities](png/image28.jpeg)
- Class-specific powers
- Wizard's fire ability
- Worker's resource gathering bonus

![Monster Respawn](png/image34.jpeg)
- Monster regeneration system
- 60-turn respawn timer
- Dynamic dungeon population

## License

This project is released into the public domain under the Unlicense. See [LICENSE](LICENSE) for details.

## UML Design

![UML Design](png/image1.png)