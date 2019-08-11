#include <stdio.h>
#include<stdlib.h>
/* To use the functions defined in Functions.c I need to #include Functions.h */
#include "functions.h"

int main(void)
{
	int capacity=0, num =0, iteration =0;
	DA* da = NULL;
	
	printf("Enter array capacity: \n");
	scanf("%d", &capacity);
	
	da = createDA(capacity);
	
	if(da)
	{
		while(iteration < capacity+1)
		{
			printf("insert number: \n");
			scanf("%d", &num);
			insert(da, num);
			iteration++;
		}
		
		printArr(da);
		destroyDA(da);
	}
	
        return 0;
}
