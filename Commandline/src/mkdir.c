#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
void mkdi(char* arg1,char* arg2)
{
	if (strcmp(arg2,"")==0)
	{
		mkdir(arg1,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	}
	else if (strcmp(arg2,"-v")==0)
	{
		mkdir(arg1,S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
		printf("successfully created %s\n",arg1);	
	}	
}
int main(int argc, char *argv[])
{
	if (argc==2)
	{
		mkdi(argv[1],"");
	}
	else if (argc==3)
	{
		mkdi(argv[2],argv[1]);
	}
	return 0;
}