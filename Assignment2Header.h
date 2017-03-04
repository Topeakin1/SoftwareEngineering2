#ifndef ASSIGNMENT2HEADER_H_
#define ASSIGNMENT2HEADER_H_

// Defined constant variables
#define PLAYER_MAX 6
#define SLOT_MAX 20
#define MAX_STRING_LENGTH 20

enum playerTypes{
    Elf,
    Human,
    Ogre,
    Wizard
};

// Structs for players and slots.
typedef struct Player{
    enum playerTypes type;
    char name[MAX_STRING_LENGTH];
    int lifePoints;
    int currentSlot;
    int smartness;
    int strength;
    int magicSkill;
    int luck;
    int dexterity;
} Player;

typedef struct Slot{
    int slotTypeNum;
    char slotType[MAX_STRING_LENGTH];
    int CurrentPlayer;
} Slot;



// Function prototypes.
int RandInt(int min, int max);

// Player functions
int NumberOfPlayers();
void InputPlayerInfo(int playerCoutn, Player * players);
void ElfPlayer(Player *currentPlayer);
void HumanPlayer(Player *currentPlayer);
void OgrePlayer(Player *currentPlayer);
void WizardPlayer(Player *currentPlayer);

// Slot functions
void FillSlotArray(int NumberOfSlots,struct Slot Slots[]);
int NumberOfSlots(int PlayersCount);


#endif