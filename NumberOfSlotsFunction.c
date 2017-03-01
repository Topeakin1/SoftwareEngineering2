#include <stdio.h>

int NumberOfSlots(int PlayersCount) {
	int reply;
	
	printf("Please enter the number of slots between %d and 20", PlayersCount);
	do{
		scanf("%d",&reply);
	}while(reply < PlayersCount || reply > 20);
	return reply;
}
