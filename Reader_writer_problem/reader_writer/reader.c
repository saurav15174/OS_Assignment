#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <semaphore.h>
int main()
{
	key_t keypt = ftok("shmfile",76);
	int shmpt = shmget(keypt,5,0666|IPC_CREAT);
	int *pt = (int*)shmat(shmpt,(void*)0,0);
	pt[2]++;
	pt[1]++;
	int t;
	if (pt[0]==0)
	{
		printf("someone is writing\n");
	}
	while(pt[0]<=0);
	pt[0]++;
	printf("Use c for consume and r for read\n");
	printf("which character you want to read or consume : ");
	char k;
	scanf("%c",&k);
	FILE *ptr = fopen("data.txt","r");
	char c;
	if (k=='c')
	{

		int i;
		if (pt[3]==0 && pt[4]==0)
		{
			printf("The queue is empty\n");
		}
		else
		{
			for (i = 0; i <= pt[4]; ++i)
			{
				c=fgetc(ptr);
			}
			printf("character consumed is %c\n",c);
			pt[4]++;
			if (pt[3]==pt[4])
			{
				pt[3]=pt[4]=0;
			}
		}	
	}
	else if(k=='r')
	{
		printf("what character you want to read : ");
		scanf("%d",&t);
		if (pt[3]==0 && pt[4]==0)
		{
			printf("the position is not written with character\n");
		}
		else if(t> pt[4] && t<=pt[3])
		{
			int i;
			for (i = 0; i < t; ++i)
			{
				c=fgetc(ptr);
			}
			printf("data read is : ");
			printf("%c\n",c);
		}
		else
		{
			printf("the position is not written with character\n");
		}
	}
	pt[0]++;
	return 0;
}

