#include <time.h>
#include <stdio.h>
#include <string.h>
void date(char* arg)
{
	time_t date;
	date = time(NULL);
	char ti[100];
	 struct tm* t= localtime(&date);
	 if (strcmp(arg,"-R")==0)
	 {
			strftime(ti,100,"%a %b  %d %H:%M:%S %Z %Y +0530",t);
			printf("%s\n",ti);
	 }
	 else
	 {
	 	strftime(ti,100,"%a %b  %d %H:%M:%S %Z %Y",t);
		printf("%s\n",ti);
	 }
}
int main(int argc, char *argv[])
{
	if (argv[1]==NULL)
	{
		date("");
	}
	else if(strcmp(argv[1],"-R")==0)
	{
		date(argv[1]);
	}
	return 0;
}