#include <stdio.h>
#include<stdlib.h>
/* To use the functions defined in Functions.c I need to #include Functions.h */
#include "functions.h"

int main(void)
{
	int capacity=0, *num = NULL, iteration =0;
	DA* da = NULL;

	printf("Enter array capacity: \n");
	scanf("%d", &capacity);
	
	da = createDA(capacity);
	
	if(da)
	{
		while(iteration < capacity+1)
		{
			printf("\ninsert number: ");
			num = (int *)malloc(sizeof(int));
			scanf("%d", num); /*num is already an adress*/
			insert(da, num);
			iteration++;
		}
	}
	
	printArr(da);
	
	destroyDA(da);
    return 0;
}
