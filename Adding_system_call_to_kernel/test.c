#include <stdio.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#include <unistd.h>
int main()
{
	long t;
	printf("Enter a process id : ");
	scanf("%li",&t);	
         long p=syscall(351,t);
	printf("system call returned %ld\n",p);
	return 0;
}

