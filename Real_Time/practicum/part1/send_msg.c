#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/ioctl.h>
#include<sys/stat.h>


#include "messageModule.h"
#include<stdlib.h>

int main(int argc, char** argv)
{
    int fd;

    fd = open(argv[1], O_RDWR);
    
    if (fd == -1)
    {
        exit (-1);
    }
    struct message_t msg;
    msg.buff = malloc(strlen(argv[2]) * sizeof(char));
    strcpy(msg.buff, argv[2]);
    msg.size = strlen(argv[2]);

    if(ioctl(fd, 0, &msg)==-1)
    {
        perror("ioctl error\n");
    }

    close (fd);
 
    return 0;
}