#include "functions.h"
#include <stdio.h>
#include<stdlib.h>

int invertBits(char x)
{
	int mask = 0, res;

	res = x^ mask;
	
}

/*rotate x to the right n times*/
int rotateBitsToRight(char x, int n)
{
	int res;
 	res = x >> n | x << (CHAR_BITS -n);
}

int setbitsToValue(unsigned int x, int i, int j,int value)
{
	if((i < INT_BITS && i > 1) && (j< INT_BITS && j > 1) && (i<=j))
	{
		
	}
}
