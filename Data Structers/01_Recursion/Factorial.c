#include<stdio.h>

int factorial (int n)
{
	if(n==1)
	{
		return n;
	}

	return n* factorial(n-1);
}

int main()
{
	int res = factorial(5);

	printf("%d\n", res);
}