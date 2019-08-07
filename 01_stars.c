#include<stdio.h>

void func1(int N);
void func2(int N);
void func3(int N);

int main()
{
	int N = 0; 
	printf("Enter number: ");
	scanf("%d", &N);
	printf("Ex 1:\n");
	func1(N);
	printf("Ex 2:\n");
	func2(N);
	printf("Ex 3:\n");
	func3(N);

	return 0;
}

void func1(int N)
{
	int i=0, j=0;
	
	for(i=1; i<=N; i++)
	{
		j=0;
		for(j; j< i;j++)
		{
			printf("*");
		}
		
		printf("\n");
		
	}
}

void func2(int N)
{
	int i = 1 , j= 0;
	while(i< N)
	{
		while(j< i)
		{
			printf("*");
			j++;
		}
		printf("\n");
		i++;
		j=0;
	}
	j=0;
	i=N;
	for(i; i>0; i--)
	{
		for(j;j<i;j++)
		{
			printf("*");
		}
		j=0;
		printf("\n");
	}
}

void func3(int N)
{
	int i=0, j=0, k=0, starsToPrint =1;

	for(i;i<N;i++)
	{
		printf(" ");
	}
	printf("*");
	printf("\n");
	starsToPrint+=2;
	
	i=0;
	for(i=1; i<N; i++)
	{
		j=0;
		for(k;k<N-i;k++)
		{
			printf(" ");
		}

		k=0;
		for(j; j< starsToPrint;j++)
		{
			printf("*");
		}
		printf("\n");
		starsToPrint+=2;
	}
}










