#include<stdio.h>
#include<stdlib.h>

void testFunc()
{
	darray *myDarr;
	int myInt;
	int res = darrayCrate(&myDarr, 100);
	printf("%d\n", res);
}

int main()
{
	testFunc();
	return 0;
}