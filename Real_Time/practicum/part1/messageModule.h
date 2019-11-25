#ifndef MESSAGEMODULE
#define MESSAGEMODULE
#include<linux/ioctl.h>

struct message_t{
	char* buff;
	size_t size;
};
 
#endif