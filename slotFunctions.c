#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Assignment2Header.h"
#define ASSIGNMENT2HEADER_H_
#define ASSIGNMENT2HEADER_H_

// Defined constant variables
#define PLAYER_MAX_SIZE 6
#define SLOT_MAX_SIZE 6
#define MAX_STRING_LENGTH 20

	Slot{
    int slotTypeNum;
    char slotType[MAX_STRING_LENGTH];
    int CurrentPlayer;
} ;
	
int RandInt(int min, int max);

int main(void) 
{
	int i; 
	int min;
	int max;
	char SlotArray[20];

	{   for(i=0; SlotArray[i]<MAX_STRING_LENGTH; i++) {
		struct Slot;
		printf("Please enter in the amount of slots\n");
		scanf("%c",SlotArray[i]); 
		
	}
}
{
    max -= min;
    int upperBound = RAND_MAX - RAND_MAX % max;
    int randInt;

    do
    {
        randInt = rand();
    }while(randInt >= upperBound);

    randInt %= max + 1;
    
    randInt += min;
    randInt= SlotArray[i];

    return randInt;
}
}
