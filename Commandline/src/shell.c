#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#define MAX_BUFFER 256
#define QUIT_STRING "exit"
// function to print the prompt on the screen.
void prompt()
{
	static int first=1;
	if (first)
		{
  			write(STDOUT_FILENO,"\e[1;1H\e[2J", 12);
  			first=0;
		}
		printf("saurav os>");	
}
// function to split the input string on the basis of space as delimiter
char** makeargv(char* in,char** charg)
{
	int i;
	for (i = 0; i < 4; ++i)
	{
		charg[i]=NULL;
	}
	char* tok=strtok(in," ");
	i=0;
	while(tok!=NULL)
	{
		charg[i]=(char*)malloc(20*sizeof(char));
		strcpy(charg[i],tok);
		tok=strtok(NULL," ");
		i++;
	}

	return charg;
}
void pwd()
{
	char path[200];
	if (getcwd(path,sizeof(path))==NULL)
	{
		printf("error!\n");
	}
	else
	{
		printf("%s\n",path);
	}
}
//function for cd command
int cd(char **chargs)
{
    if(chargs[1] == NULL)
    {
      fprintf(stderr, "cd: expected argument to \"cd\"\n");
    }
    else
    {
      if(chdir(chargs[1]) != 0)
      {
          perror("cd");
      }
    }
    return 1;
}
//driver function
int main (int argc, char *argv[])
{
    char **chargv=(char**)malloc(4*sizeof(char*));
    char inbuf[MAX_BUFFER];
    int i=0;
    char **hist =(char**)malloc(256*sizeof(char*));
    int k=0;
    //char* path[150]=""
    for (int k = 0; k < 256; ++k)
    {
    	hist[k]=(char*)malloc(100*sizeof(char));
    }
    while(true) 
    {
    prompt();
	gets(inbuf);
	strcpy(hist[i],inbuf);
	chargv=makeargv(inbuf,chargv);
			if (strlen(inbuf)==0)
			{
				continue;
			}
			if(strcmp(chargv[0],"exit") == 0)
       		{
          		exit(0);
       		}
       		else if (strcmp(chargv[0],"history")==0)
       		{
       			int j=0;
       			for (j = 0; j <= i; ++j)
       			{
       			printf("%d %s\n",j+1,hist[j]);
       			}
       		} 
       		else if(strcmp(chargv[0],"cd")==0)
       		{
		 		cd(chargv);       	
       		}
       		else if (strcmp(chargv[0],"pwd")==0)
       		{
       			pwd();
       		}
       		else if (strcmp(chargv[0],"echo")==0)
       		{
       			printf("%s\n",chargv[1]);
       		}
       		else
       		{
          		if (fork() == 0)
          		{
	     			if (execvp(chargv[0], chargv)==-1)
	     			{
	     				printf("invalid command\n");
	     			}
	     			else
	     			{
	     				execvp(chargv[0], chargv);
	     			}
	     	
          		}
          	wait(NULL);
       		}
		memset(inbuf,0,strlen(inbuf));
        i++;
    }   
    return 0;
}
