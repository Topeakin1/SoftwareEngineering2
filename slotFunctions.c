#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Assignment2Header.h"
#define ASSIGNMENT2HEADER_H_
void SlotFunction(int NumberOfSlots,struct Slot Slots[]) {
	char SlotTypes[3][15] = {"Level Ground","Hill","City"};
	int i, random;
	srand(time(NULL));
	
	for(i=0; i<NumberOfSlots; i++) {
		random=rand() %3;
		strcpy(Slots[i].slotType,SlotTypes[random]); //assigning my slots
	}
	for(i=0; i<NumberOfSlots; i++) {
		printf("| %s |\n", Slots[i].slotType); //printing out to check
	}
	
}

