#include <stdio.h>
#include <stdlib.h>
#include "Assignment2Header.h"

int RandInt(int min, int max)
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