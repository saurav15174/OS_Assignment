#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cat(char* arg,char* filen)
{
	FILE *f;
	f=fopen(filen,"r");
	if (f==NULL)
		{
			return 0;
		}
	if (arg==NULL)
	{
		char c;
		c=fgetc(f);
		while(c!=EOF)
		{
			printf("%c",c);
			c=fgetc(f);
		}
		printf("\n");	
	}
	else if (strcmp(arg,"-e")==0)
	{
		char c;
		c=fgetc(f);
		while(c!=EOF)
		{
			if (c=='\n')
			{
				printf("$");
			}
			printf("%c",c);
			c=fgetc(f);
		}
		printf("$");
		printf("\n");		
	}
	else if (strcmp(arg,"-n")==0)
	{
		char c;
		c=fgetc(f);
		char temp='\n';
		int count=1;
		while(c!=EOF)
		{
			if (temp=='\n')
			{
				printf("%d ",count++);
			}
			temp=c;
			printf("%c",c);
			c=fgetc(f);
		}
		printf("\n");	
	}
	fclose(f);
	return 1;

}

int main(int argc, char *argv[])
{
	if (argc==2)
	{
		cat(NULL,argv[1]);
	}
	else if(argc==3)
	{
		cat(argv[1],argv[2]);
	}
	return 0;
}