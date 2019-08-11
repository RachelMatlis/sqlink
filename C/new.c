#include<stdio.h>
#include<stdlib.h>

int* insert(int *ip, int* index,int* capacity, int num);
void printArr(int*, int);

int main()
{
	int* ip= NULL;
	int num=0, index=0 ,capacity=0;
	int iteration =0;
	
	printf("Enter array capacity: \n");
	scanf("%d", &capacity);
	
	ip= (int*) malloc(capacity* sizeof(int));
	
	while(iteration < capacity+1)
	{
		printf("insert number: \n");
		scanf("%d", &num);
		ip = insert(ip , &index, &capacity, num);
		iteration++;
	}
	
	printArr(ip, iteration);	
	
	free(ip);
	
	return 0;
}

int* insert(int *ip, int* index,int* capacity, int num)
{
	if(index < capacity)
	{
		ip[*index] = num;
		(*index)++;
	}
	else
	{
		(*capacity)++;
		ip = (int*)realloc(ip,(*capacity) *sizeof(int));
		ip[*index] = num;
		(*index)++;
		(*capacity)++;
	}
	
	return ip;
}

void printArr(int *arr, int size)
{
	int i = 0;
	for (i; i<size - 1; i++)
	{
		printf("%d, ", arr[i]);
	}

	printf("%d.", arr[size - 1]);
}


