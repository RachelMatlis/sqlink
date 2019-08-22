#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"darray_int.h"

typedef struct{
	int x;
	int y;
}Vector;

void vectorDestroy(void *_elem, void *context);
int vectorsCompare(void* _elemA, void* _elemB);
void testFunc();



int main()
{
	void testFunc();
	return 0;
}

void vectorDestroy(void *_elem, void *context)
{
	if(_elem)
	{
		Vector* vectorElemnt = (Vector*) _elem;

		if(context)
		{
			FILE *f = (FILE*) context;
			fprintf(f, "Vector <%d,%d> Deleted\n",vectorElemnt->x, vectorElemnt->y );

		}
		
		free(vectorElemnt);	
	}
}

int vectorsCompare(void* _elemA, void* _elemB)
{
	int size1, size2;
	Vector* vectorElemnt1 = (Vector*) _elemA;
	Vector* vectorElemnt2 = (Vector*) _elemB;

	size1 = sqrt(pow((vectorElemnt1->x + vectorElemnt1->y),2));
	size2 = sqrt(pow((vectorElemnt2->x + vectorElemnt2->y),2));

	if(size1 == size2)
	{
		printf("%d", size1-size2);
		return size1-size2;
	}
	else if(size1 > size2)
	{
		printf("%d", size1+size2);
		return size1 + size2;
	}
	else
	{
		printf("%d", size1-size2);
		return size1-size2;
	}
}

void testFunc()
{
	int res;
	darray *myDarr;
	char fileName[]= "vectors.txt";
	FILE* fp = fopen(fileName, "w");
	Vector *v;

	res = darrayCreate(&myDarr, 100);
	printf("%d\n",res);
	
    v= malloc(sizeof(Vector));
	v->x =5;
	v->y= 6;
	darrayAdd(myDarr, v);
	vectorsCompare(v,v);

	darrayDestroy(myDarr, vectorDestroy,fp);
	
	fclose(fp);
}