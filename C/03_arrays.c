#include<stdio.h>

void sortAscending(int*, int);
void sortZeroFirst(int*, int);
int sortEvenNumbersFirst(int*, int);
int findMostFrequent(int *, int);

void printArr(int*, int);
void swap(int*, int*);

int main()
{
	int a1[8] = { 64,34,25,12,22,11,90, 38 };
	int a2[8] = { 0,0,1,0,1,1,1,0 };
	int a3[8] = { 1,2,4,8,9,2,13,15};
	int a4[8] = { 3,6,8,3,9,12,9,9 };
	int size = 8;
	int evenNumbers;

	printf("--- Question 1 --- \n");
	printf("Original array: ");
	printArr(a1, size);
	printf("\nAfter sort:     ");
	sortAscending(a1, size);
	printArr(a1, size);

	printf("\n\n--- Question 2: --- \n");
	printf("Original array:     ");
	printArr(a2, size);
	printf("\nAll 0's before 1's: ");
	sortZeroFirst(a2, 8);

	printf("\n\n--- Question 3: --- \n");
	printf("Original array:     ");
	printArr(a3, size);
	printf("\nEven Numbers First: ");
	evenNumbers = sortEvenNumbersFirst(a3, size);

	printf("\n\n--- Question 4: --- \n");
	printf("Array: ");
	printArr(a4, size);
	printf("\nMost frequent num is: %d", findMostFrequent(a4, size));

	printf("\n\n");
	return 0;
}

void sortAscending(int *arr, int size)
{
	int i, j, flag=0;
	for (i = 0; i < size - 1; i++)
	{
		/* Last i elements are already in place */
		for (j = 0; j < size - i - 1; j++)
		{
			flag==0;

			if (arr[j] > arr[j + 1])
			{
				swap(&arr[j], &arr[j + 1]);
				flag= 1;
			}
		}
		if(flag==0) /* no more swaps */
		{
			break;
		}
	}
}

void sortZeroFirst(int *a, int size)
{
	int i = 0, j = 0, countZero = 0;

	for (i; i< size; i++)
	{
		if (a[i] == 0)
		{
			countZero++;
		}
	}

	i = 0;
	for (i; i< size; i++)
	{
		if (i < countZero)
		{
			a[i] = 0;
		}
		else
		{
			a[i] = 1;
		}
	}

	printArr(a, size);
}


int sortEvenNumbersFirst(int *a, int size)
{
	int i, j;
	for (i = 0; i < size - 1; i++)
		for (j = 0; j < size - i - 1; j++)
		{
			if (a[j]%2 == 1 && a[j+1]%2 ==0)
			{
				swap(&a[j], &a[j + 1]);
			}
		}
 
	printArr(a, size);
}

int findMostFrequent(int *a, int size)
{
	int max = 0, count=1, i = 0,j=0, maxCount = 0, returnedValue;

	sortAscending(a, size);

	for (i=0; i < size -1; i++)
	{

		if (a[i] == a[i + 1])
		{
			count++;
			while (a[i + 1] == a[i + 2])
			{
				count++;
				i++;
			}
		}

		if (count > maxCount) /*check if bigger than prev count*/
		{
			maxCount = count;
			returnedValue = a[i];
		}

		count = 1;
	}

	return returnedValue;
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

void swap(int *x, int *y)
{
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
}

