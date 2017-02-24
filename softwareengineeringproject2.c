#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Assignment2Header.h"
int NumberOfPlayers(); //function prototype

int main(void) {
	srand(time(NULL));
	Player players[PLAYER_MAX_SIZE]; 
	int slots;
	int playersCount;
	printf("%d", RandInt(4, 10));
}
