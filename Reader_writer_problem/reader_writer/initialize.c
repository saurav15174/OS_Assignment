#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>
#include <string.h>
int main()
{
	FILE *fp;
	fp=fopen("data.txt","w");
	key_t keypt = ftok("shmfile",76);
	int shmpt = shmget(keypt,5,0666|IPC_CREAT);
	int *pt = (int*)shmat(shmpt,(void*)0,0);
	pt[0]=1;
	pt[1]=1;
	pt[2]=0;
	pt[3]=0;
	pt[4]=0;
	return 0;
}
