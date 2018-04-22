#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <pthread.h>
#include <string.h>
void *listener(void *arg)
{
    key_t key = ftok("recievefile",72);
    char ** argu = (char**)arg;
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    char *recv = (char*) shmat(shmid,(void*)0,0);
    strcpy(recv,"");
    while(1)
    {
        if (recv[0]==argu[1][0])
        {
         printf("%s\n",recv);   
         strcpy(recv,"");
        }
        else if (recv[0]=='A')
        {
            printf("%s\n",recv);   
            strcpy(recv,"");
        }
    }
}
int main(int argc, char *argv[])
{
    char buffer[1024];
    key_t key = ftok("sendfile",65);
    int shmid = shmget(key,1024,0666|IPC_CREAT);
    char *sent = (char*) shmat(shmid,(void*)0,0);
    pthread_t tid;
    pthread_create(&tid, NULL, listener, (void*)argv);
    strcpy(sent,"");
    if (!argv[1])
    {
        printf("error: Enter the correct user name!\n");
        exit(1);
    }
    while(1)
    {

        gets(buffer);
        if(strcmp(buffer,"exit")==0)
        {
            strcpy(buffer,"");
            strcat(buffer,"A ");
            strcat(buffer,argv[1]);
            strcat(buffer," exited from chat");
            strcpy(sent,buffer);
            break;
            
        }
        strcat(buffer,": form ");
        strcat(buffer,argv[1]);
        strcpy(sent,buffer);
    }
    return 0;
}