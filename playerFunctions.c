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
    int j;
    
    for(int i = 0; i < playerCoutn; i++)
    {
        do{
            printf("\nPlayer %d \n\nInput player name: ", i + 1);
        }while(*(fgets(players[i].name, MAX_STRING_LENGTH - 1, stdin)) == '\n');
        // Take a string as input and assign it to the name of the current player.
        
        j = 0;
        while(players[i].name[++j] != '\n');
        players[i].name[j] = '\0';
        
        
        printf("\nChose a player type: \
                    \n 1. Elf\
                    \n 2. Human\
                    \n 3. Ogre\
                    \n 4. Wizard \n");
                    
        do
        {
            printf("  : ");
            fgets(tempInput, MAX_STRING_LENGTH - 1, stdin);
            players[i].type = strtol(tempInput, NULL, 10) - 1;
        }while(players[i].type < 0 || players[i].type > 3);
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

<<<<<<< HEAD
void PlayerAction(int playerCount, int slotCount, Player *players, Slot *slots)
{
    int i, position, choice;
    int legalMoves[4];
    int j, closestPlayerDist;
    char tempInput[MAX_STRING_LENGTH];
    
    
    for(i = 0; i < playerCount; i++)
    {
        position = -1;
        while(slots[++position].currentPlayer != i);
        // Finds the position of the current player.
        
        printf("\nPlayer: %s\nCurrent Slot: %d %s\n\n", players[i].name, (position + 1), slots[position].slotType);
        
        legalMoves[0] = (position != 0 && slots[position - 1].currentPlayer >= playerCount);
        // Checks if it's possible to move to the left.
        
        legalMoves[1] = (position != (slotCount - 1) && slots[position + 1].currentPlayer >= playerCount);
        // Checks if it's possible to move to the right.
        
        closestPlayerDist = slotCount;
        j = position;
        while(--j > -1 && (slots[j].currentPlayer >= playerCount));
        
        
        if(j != -1)
        {
            closestPlayerDist = position - j;
            legalMoves[2] = 1;
            legalMoves[3] = 0;
        }
        
        j = position;
        while(++j < slotCount && slots[j].currentPlayer >= playerCount);
        
        if(j != slotCount)
        {
            if(closestPlayerDist > j - position)
            {
                closestPlayerDist = j - position;
                legalMoves[2] = 0;
                legalMoves[3] = 1;
            }
            else if(closestPlayerDist == j - position)
            {
                legalMoves[2] = 1;
                legalMoves[3] = 1; 
            }
        }
        /* 
         * Finds the closest player if any and the distance to them.
         * Then finds the closest player on the right and checks who
         * Then sets attacking the closest player as a legal move.
         * If two players are the same distance away, both are legal.
         */
        
        
        
        
        j = 0;
        printf("What do you want to do?\n");
        
        if(legalMoves[0])
        {
            legalMoves[0] = ++j;
            printf(" %d: Move left\n", j);
        }
        
        if(legalMoves[1])
        {
            legalMoves[1] = ++j;
            printf(" %d: Move right\n", j);
        }
        
        if(legalMoves[2])
        {
            legalMoves[2] = ++j;
            printf(" %d: Attack %s\n", j, players[slots[position - closestPlayerDist].currentPlayer].name);
        }
        
        if(legalMoves[3])
        {
            legalMoves[3] = ++j;
            printf(" %d: Attack %s\n", j, players[slots[position + closestPlayerDist].currentPlayer].name);
        }
        
        puts("");
        
        // Displays a list of options for the player based on what is possible from their position.
        
        do
        {
            printf("  : ");
            fgets(tempInput, MAX_STRING_LENGTH - 1, stdin);
            choice = strtol(tempInput, NULL, 10);
        }while(choice < 1 || choice > j);
        
        // Takes input for what the player should do.
        
        
        
        // Move or attack here depending on user input.
    }
=======
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
	printf("currentSlot:%d\n",players[i].currentSlot);
	
>>>>>>> c69d472... printed out list of players
}


