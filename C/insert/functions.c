/* In general it's good to include also the header of the current .c,
   to avoid repeating the prototypes */
#include "functions.h"

DA* createDA(int capacity)
{
	DA* da = (DA*)malloc(sizeof(DA));
	
	if(da)
    {
        da->arr = (int *)malloc(capacity* sizeof(int));
        da->index = 0;
        da-> capacity = capacity;
        return da;
    }
}

void destroyDA(DA* da)
{
	if(da)
	{
		if(da->arr)
		{
			free(da);	
		}
		
		free(da->arr);
		free(da);
	}
}

int insert(DA* da, int num)
{
	if(da->index < da->capacity)
	{
		da->arr[(da->index)] = num;
		(da->index)++;
	}
	else
	{
		da->arr = (int*)realloc(da->arr,((da->capacity) *2) *sizeof(int));
		da->arr[da->index] = num;
		(da->index)++;
		(da->capacity)*=2;
	}
	
	return 1;
}

void printArr(DA* da)
{
	int i = 0;
	for (i; i<(da->index) - 1; i++)
	{
		printf("%d, ", da->arr[i]);
	}

	printf("%d.", da->arr[da->index-1]);
	
}





