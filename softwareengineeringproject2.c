#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Assignment2Header.h"

int main(void) {
	srand(time(NULL));
	Player players[PLAYER_MAX]; 
    Slot slots[SLOT_MAX];
    
	int slotsCount;
	int playersCount;    

    // Reads in number of players from user and stores it in the playersCount variable.
    playersCount = NumberOfPlayers();
    
    // Takes input for names, types and charactersitics for the players.
    InputPlayerInfo(playersCount, players);
    
    // Reads in number of slots from user and stores it in the slotCount variable.
	slotsCount = NumberOfSlots(playersCount);
	
    // Fills slot array with random slots.
	FillSlotArray(slotsCount, slots);
    
    PlayersNSlots(slots, slotsCount);
    
    PlayerAction(playersCount, slotsCount, players, slots);
    
    Print(players, playersCount);
}