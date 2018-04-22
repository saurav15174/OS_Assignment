#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void rm(char* arg1,char* arg2)
{
	int r;
	if (strcmp(arg1,"-v")==0)
	{
		r=remove(arg2);
		if (r==0)
		{
			printf("file %s is deleted sucessfully\n",arg2);
		}
		else
		{
			printf("file name %s not found\n",arg2);
		}
	}
	else if(strcmp(arg1,"-i")==0)
	{
		char a[12];
		printf("do you want to delete ?\n");
		scanf("%s",a);
		if (strcmp(a,"yes")==0)
		{
			remove(arg2);
		}
	}
	else if (strcmp(arg1,"")==0)
	{
		r=remove(arg2);
	}
}

int main(int argc, char  *argv[])
{
	if (argc==2)
	{
		rm("",argv[1]);
	}
	else if(argc==3)
	{
		 rm(argv[1],argv[2]);
	}
	return 0;
}