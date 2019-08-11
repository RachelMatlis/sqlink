#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_
/* ^^ these are the include guards */

/* Prototypes for the functions */

#include <stdio.h>
#include<stdlib.h>

typedef struct{
	int *arr;
	int index;
	int capacity;
}DA;

DA* createDA(int capacity);
int insert(DA* da,int num);
void destroyDA(DA* da);
void printArr(DA* );

#endif
