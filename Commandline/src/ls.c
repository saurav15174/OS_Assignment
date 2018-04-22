#include <stdio.h>
#include <dirent.h>
#include <string.h> 
void ls(char* arg)
{
  struct dirent *de;
  DIR *direct = opendir(".");
  if (strcmp(arg,"-d")==0)
  {
    printf(".\n");
  }
  else if (strcmp(arg,"-a")==0)
  {
    while((de=readdir(direct))!=NULL)
    {
        printf("%s\n",de->d_name);
    } 
  }
  else
  {
    while((de=readdir(direct))!=NULL)
    {
      if(de->d_name[0]!='.')
      {
        printf("%s\n",de->d_name);
      }
    }
  }
  closedir(direct);
}
int main(int argc, char *argv[])
{
  if (argv[1]==NULL)
  {
    ls("");
  }
  else
  {
    ls(argv[1]);
  }
  return 0;
}