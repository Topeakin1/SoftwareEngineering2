#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Assignment2Header.h"

	typedef struct Slots
	{
		char SlotArray[20];
    };
int RandInt(int min, int max);

int main(void) 
{
	int i; 
	int min;
	int max;
	char SlotArray[20];

	{   for(i=0; SlotArray[i]<100; i++) {
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

    return randInt;
}
}
