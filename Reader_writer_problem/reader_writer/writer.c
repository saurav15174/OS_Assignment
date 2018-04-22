#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
int main()
{
	key_t keypt = ftok("shmfile",76);
	int shmpt = shmget(keypt,5,0666|IPC_CREAT);
	int *pt = (int*)shmat(shmpt,(void*)0,0);
	if (pt[0]==0)
	{
		printf("some writer is writing\n");
		exit(0);
	}
	while(pt[0]<=0);
	pt[0]--;
	printf("You can write now\n");
	char y;
	scanf("%c",&y);
	FILE *ptr=fopen("data.txt","a");
	fputc(y,ptr);
	pt[3]++;
	pt[0]++;
	return 0;
}
