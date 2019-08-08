#include<stdio.h>

int isPalindrome(int);
int reverseNumber(int);
int isAscending(int);
int isPrimeNumber(int);
int isPerfectNumber(int);

int main()
{
	int n, isPali, isAscen, isPrimer,isPerfect; 
	printf("Enter number: ");
	scanf("%d", &n);
	
	isPali = isPalindrome(n);

	if(isPali)
	{	
		printf("\n%d is Palindrome", n);
	}
	else
	{
		printf("\n%d is NOT Palindrome", n);
	}

	isAscen = isAscending(n);

	if(isAscen)
	{	
		printf("\n%d is ascending number", n);
	}
	else
	{
		printf("\n%d is NOT ascending numer", n);
	}
	
	isPrimer = isPrimeNumber(n);
	
	if(isPrimer)
	{
		printf("\n%d is prime number", n);
	}
	else	
	{	
		printf("\n%d is not prime number", n);
	}

	isPerfect = isPerfectNumber(n); 

	if(isPerfect)
	{
		printf("\n%d is perfect number\n", n);
	}
	else
	{
		printf("\n%d is NOT perfect number\n", n);
	}

	return 0;
}



/* My Functions*/
int reverseNumber(int n)
{
    int reversedNumber = 0, remainder;
    while(n != 0)
    {
        remainder = n%10;
        reversedNumber = reversedNumber*10 + remainder;
        n = n/10;
    }

    return reversedNumber;
}

int isPalindrome(int n)
{
	int res;
	if( n == reverseNumber(n))
	{	
		res = 1;
	}
	else 
	{
		res =0;
	}
	
	return res;
}

int isAscending(int n)
{
	int currDigit, prevDigit, res=1;

	while(n != 0)
	{
		currDigit= n%10;
		n = n/10;
		prevDigit= n%10;

		if(prevDigit > currDigit)
		{
			res = 0;
			break; 
		}
		
		return res;
	}
}

int isPrimeNumber(int n)
{
	int res, i=3;

	if(n==2)
	{
		res = 1;	
	}
	
	else if(n%2 == 0)
	{
		res = 0;
	}	
	else 
	{
		for(i; i<= n/2; i++)
		{
			if(n%i ==0)
			{
				res = 0;
				break;
			}
	}

	return res;
}
}

isPerfectNumber(n)
{
	int res=0, sum=0, multi=1, i=1;

	for(i; i<n; i++)
		{
			if(n%i == 0)
			{
				sum+= i;
				multi*= i;
			}	
		}
		
	if(sum== n && multi ==n)
	{
		res= 1;
	}
		
	return res;

}













