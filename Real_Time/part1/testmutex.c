#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <pthread.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include "mq.h"
/*#define MESSEGE 5*/
#define PRONUM 10
#define CONSNUM 10

char* queuePath;
char* msg;

void* producer(void *arg) 
{   
    int fd ,ret;
    struct message_t reg;
    fd=open(queuePath,O_WRONLY);
    if(fd==-1) 
    {
        fprintf(stderr, "open error [%s]\n", queuePath);
        return NULL;
    }
    reg.buff=msg;
    reg.size=strlen(msg);
    ret=ioctl(fd, MQ_SEND_MESSAGE,&reg);
    if(ret==-1) 
    {
        fprintf(stderr, "ioctl error\n");
        return NULL;
    }
    ret=close(fd);
    if(ret==-1) 
    {
        fprintf(stderr, "close error\n");
        return NULL;
    }
    return NULL;
}

void* consumer() 
{ 
	int fd, ret;
    char* buffer= (char*)malloc(sizeof(char)*4096);
    
    fd=open(queuePath,O_RDONLY);
    if(fd==-1) 
    {
        fprintf(stderr, "open error\n");
    return (void*)1;
    }
    ret=ioctl(fd, MQ_GET_MESSAGE, buffer);
    if(ret==-1) 
    {
        fprintf(stderr, "ioctl error\n");
    return (void*)1;
    }
    printf("The message is %s\n", buffer);
    ret=close(fd);
    if(ret==-1) 
    {
        fprintf(stderr, "close error\n");
        return (void*)1;
    }

    free(buffer);
    return (void*) 0;
}


int main (int argc, char** argv)
{ 
    pthread_t produsers [PRONUM];
    pthread_t consumers [CONSNUM];
   
    int i ,j,w,z;

    queuePath=argv[1];
    if(argc ==3)
    {
        msg = argv[2];
    }
    
    for(i=0;i<PRONUM;i++)
    {
         pthread_create(&produsers[i],NULL,producer,&i);   
    }

   for(j=0;j<CONSNUM;j++)
    {
        pthread_create(&consumers[j],NULL,consumer,&j);
    }
    
    for(w=0;w<PRONUM;w++)
    {
        pthread_join(produsers[w],NULL);
    }

    for(z=0;z<CONSNUM;z++)
    {
        pthread_join(consumers[z],NULL);
    }

   return 0;
}


