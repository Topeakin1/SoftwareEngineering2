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
    int playerTypeNum;
    char *playerTypes[4] = {"Elf", "Human", "Ogre", "Wizard"};
    char tempInput[MAX_STRING_LENGTH];
    
    for(int i = 0; i < playerCoutn; i++)
    {
        printf("Player %d \n\nInput player name: ", i + 1);
        fgets(players[i].name, MAX_STRING_LENGTH - 1, stdin);
        // Take a string as input and assign it to the name of the current player.
        
        playerTypeNum = 0;
        while(playerTypeNum < 1 || playerTypeNum > 4)
        {
            printf("\nChose a player type: \
                    \n 1. Elf\
                    \n 2. Human\
                    \n 3. Ogre\
                    \n 4. Wizard\
                    \n : ");
            fgets(tempInput, MAX_STRING_LENGTH - 1, stdin);
            playerTypeNum = strtol(tempInput, NULL, 10);
        }
        // Player choses a number between 1 and 4 and if it is valid, that player type gets chosen.
        
        strcpy(players[i].type, playerTypes[playerTypeNum - 1]);
        // Copies the string of the player type into the player's type variable.
    }
}
