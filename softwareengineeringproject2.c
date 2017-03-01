#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Assignment2Header.h"

int main(void) {
	srand(time(NULL));
	Player players[PLAYER_MAX]; 
	int slots;
	int playersCount;    

    // Reads in number of playerrs from user and stores it in the playerCount variable.
    playersCount = NumberOfPlayers();
    
    // Takes input for names and types for the players.
    InputPlayerInfo(playersCount, players);
    
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