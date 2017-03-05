#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "Assignment2Header.h"

//  Takes user input for the amount of players and returns that as a number.
int NumberOfPlayers()
{
    int numberOfPlayers;
    char tempInput[MAX_STRING_LENGTH];
    
    printf("Input number of players: ");
    fgets(tempInput, MAX_STRING_LENGTH - 1, stdin);
    numberOfPlayers = strtol(tempInput, NULL, 10);
    // Takes a string as input and stores it as a nummber.
    
    while(numberOfPlayers < 2 || numberOfPlayers > PLAYER_MAX)
    {
        printf("Number of players has to be between 2 and %d: ", PLAYER_MAX);
        fgets(tempInput, MAX_STRING_LENGTH - 1, stdin);
        numberOfPlayers = strtol(tempInput, NULL, 10);
    }
    // Makes sure the input is a number between 2 and the max amount of players.
    
    return numberOfPlayers;
}


//   Takes input for each player and stores their info in the players array.
void InputPlayerInfo(int playerCoutn, Player * players)
{
    void (*playerTypes[4])(Player *currentPlayer) = \
    {ElfPlayer, HumanPlayer, OgrePlayer, WizardPlayer};
    // Array of pointers to functions for each player type. 
    
    char tempInput[MAX_STRING_LENGTH];
    
    for(int i = 0; i < playerCoutn; i++)
    {
        printf("Player %d \n\nInput player name: ", i + 1);
        fgets(players[i].name, MAX_STRING_LENGTH - 1, stdin);
        // Take a string as input and assign it to the name of the current player.
        
        players[i].type = -1;
        while(players[i].type < 0 || players[i].type > 3)
        {
            printf("\nChose a player type: \
                    \n 1. Elf\
                    \n 2. Human\
                    \n 3. Ogre\
                    \n 4. Wizard\
                    \n : ");
            fgets(tempInput, MAX_STRING_LENGTH - 1, stdin);
            players[i].type = strtol(tempInput, NULL, 10) - 1;
        }
        // Player choses a number between 1 and 4 and if it is valid, that player type gets chosen.
        
        playerTypes[players[i].type](&players[i]);
        players[i].lifePoints = 100;
        // Calls the player type function and sets player life to 100;
    }
}

/* 
 * Functions for generating player charactersistics.
 * Uses the RandInt(int x, int y) function to generate 
 * numbers from x to y inclusive.
 * Stores thexe numbers in the current player's characteristics.
 * 
*/
void ElfPlayer(Player *currentPlayer)
{
    currentPlayer->luck = RandInt(60, 100);
    currentPlayer->smartness = RandInt(70, 100);
    currentPlayer->strength = RandInt(1, 50);
    currentPlayer->magicSkill = RandInt(50, 80);
    currentPlayer->dexterity = RandInt(1, 100);
}

void HumanPlayer(Player *currentPlayer)
{
    unsigned int sum;
    do
    {
        sum = 0;
        currentPlayer->luck = RandInt(1, 100);
        currentPlayer->smartness = RandInt(1, 100);
        currentPlayer->strength = RandInt(1, 100);
        currentPlayer->magicSkill = RandInt(1, 100);
        currentPlayer->dexterity = RandInt(1, 100);
        sum = \
        currentPlayer->luck +\
        currentPlayer->smartness +\
        currentPlayer->strength +\
        currentPlayer->magicSkill +\
        currentPlayer->dexterity;
    }while(sum > 300);
}

void OgrePlayer(Player *currentPlayer)
{
    currentPlayer->smartness = RandInt(0, 20);
    currentPlayer->luck = RandInt(0, 50 - currentPlayer->smartness);
    currentPlayer->strength = RandInt(80, 100);
    currentPlayer->magicSkill = 0;
    currentPlayer->dexterity = RandInt(80, 100);
}

void WizardPlayer(Player *currentPlayer)
{
    currentPlayer->luck = RandInt(50, 100);
    currentPlayer->smartness = RandInt(90, 100);
    currentPlayer->strength = RandInt(1, 20);
    currentPlayer->magicSkill = RandInt(80, 100);
    currentPlayer->dexterity = RandInt(1, 100);
}

//printing out list of players
for(i=0; i<numberOfplayers; i++) {
	printf("name:%s\n",players[i].name);
	printf("type:%s\n",players[i].playertype);
	printf("smartness:%d\n",players[i].smartness);
	printf("strength:%d\n",players[i].strength);
	printf("MagicSkill:%d\n",players[i].magicSkill);
	printf("luck:%d\n",players[i].luck);
	printf("lifepoints:%d\n",players[i].lifepoints);
	printf("dexterity:%d\n",players[i].dexterity);
	printf("currentSlot:%d\n\n",players[i].currentSlot);
	
}


