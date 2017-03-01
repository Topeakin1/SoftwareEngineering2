#ifndef ASSIGNMENT2HEADER_H_
#define ASSIGNMENT2HEADER_H_

// Defined constant variables
#define PLAYER_MAX 6
#define SLOT_MAX 20
#define MAX_STRING_LENGTH 20

// Structs for players and slots.
typedef struct Player{
    char type[MAX_STRING_LENGTH];
    char name[MAX_STRING_LENGTH];
    int lifePoints;
    int currentSlot;
    int smartness;
    int strength;
    int magicSkill;
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

// Slot functions
void FillSlotArray(int NumberOfSlots,struct Slot Slots[]);
int NumberOfSlots(int PlayersCount);


#endif