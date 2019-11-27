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

void* producer(void * arg) 
{   
    int fd ,ret, i;
    struct message_t reg;

    for(i=0;i<PRONUM;i++)
    {
    	fd=open("/dev/mq0",O_WRONLY);
        if(fd==-1) 
        {
            fprintf(stderr, "open error\n");
            return (void*)1;
        }
        reg.buff="hello";
        reg.size=strlen(reg.buff);
        ret=ioctl(fd,MQ_SEND_MESSAGE,&reg);
        if(ret==-1) 
        {
            fprintf(stderr, "ioctl error\n");
            return (void*)1;
        }
        /*printf("return value from ioctl was %d\n", ret);*/
        ret=close(fd);
        if(ret==-1) 
        {
            fprintf(stderr, "close error\n");
            return (void*)1;
        }
    }

    return (void*) 0;
}

void* consumer() 
{ 
	int fd, ret,i;
    char* buffer= (char*)malloc(sizeof(char)*4096);
    for(i=0;i<CONSNUM;i++)
    {     
        fd=open("/dev/mq0",O_RDONLY);
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
    }

    free(buffer);
    return (void*) 0;
}


int main ()
{ 
    pthread_t produsers [PRONUM];
    pthread_t consumers [CONSNUM];
   
    int i ,j,w,z;

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
