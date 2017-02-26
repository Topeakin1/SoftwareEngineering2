#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Assignment2Header.h"

int main(void) {
	srand(time(NULL));
	Player players[PLAYER_MAX_SIZE]; 
	int slots;
	int playersCount;
	printf("%d", RandInt(4, 10));
    

    playersCount = NumberOfPlayers();
    
    /*
	Input player names and types function (also fills out the life points and capabilities of the players)
	
	Input number of slots function
	
	Generate random slots function
	
	Place players into slots function
	
	Loop for asking to move or attack
	 Move or attack according to user input
	
	Print players function
    */
}