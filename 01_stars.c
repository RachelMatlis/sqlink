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
	int line=1, stars=0;
	
	for(line; line<=N; line++)
	{
		stars=0;
		for(stars; stars< line;stars++)
		{
			printf("*");
		}
		
		printf("\n");
		
	}
}

void func2(int N)
{
	int line = N-1 , stars= 0;
	func1(N);
	
	for(line; line>0; line--)
	{
		for(stars;stars<line;stars++)
		{
			printf("*");
		}
		stars=0;
		printf("\n");
	}
}

void func3(int N)
{
	int line=0, j=0, spaces=0, starsToPrint =1;

	for(line;line<N;line++)
	{
		printf(" ");
	}
	printf("*");
	printf("\n");
	starsToPrint+=2;
	
	line=0;
	for(line=1; line<N; line++)
	{
		j=0;
		for(spaces;spaces<N-line;spaces++) /*canculate spaces*/
		{
			printf(" ");
		}

		spaces=0;
		for(j; j< starsToPrint;j++)
		{
			printf("*");
		}
		printf("\n");
		starsToPrint+=2;
	}
}










