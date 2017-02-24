
#ifndef ASSIGNMENT2HEADER_H_
#define ASSIGNMENT2HEADER_H_

#define PLAYER_MAX_SIZE 6
#define SLOT_MAX_SIZE 6
#define MAX_STRING_LENGTH 20


typedef struct Player{
    char type[MAX_STRING_LENGTH];
    char name[MAX_STRING_LENGTH];
    int lifePoints;
    int currentSlot;
    int smartness;
    int strength;
    int magicSkill
} Player;

typedef struct Slot{
    
} Slot;


int RandInt(int min, int max);


#endif