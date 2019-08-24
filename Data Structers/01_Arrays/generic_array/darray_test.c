#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"darray_generic.h"

typedef struct {
	int x;
	int y;
}Vector;

void vectorDestroy(void* , void* );
int vectorsCompare(void*, void*);
void testFunc();

int main()
{
	testFunc();
	return 0;
}

void vectorDestroy(void *vectorP, void *fileP)
{
	if (vectorP)
	{
		Vector* vectorElemnt = (Vector*) vectorP;

		if (fileP)
		{
			FILE *f = (FILE*) fileP;
			fprintf(f, "Vector <%d,%d> Deleted\n", vectorElemnt->x, vectorElemnt->y);

		}

		free(vectorElemnt);
	}
}

int vectorsCompare(void* _elemA, void* _elemB)
{
	Vector* vec1 = (Vector*)_elemA;
	Vector* vec2 = (Vector*)_elemB;

	return ((vec1->x + vec1->y) - (vec2->x + vec2->y));

}

void testFunc()
{
	int res =0;
	char fileName[] = "vectors.txt";
	darray *myDarr =NULL;
	FILE* fp = NULL;
	Vector *v =NULL;

	fp = fopen(fileName, "w");

	res = darrayCreate(&myDarr, 100);
	printf("%d\n", res);

	v = malloc(sizeof(Vector));
	v->x = 5;
	v->y = 6;
	darrayAdd(myDarr, v);
	vectorsCompare(v, v);

	darrayDestroy(myDarr, vectorDestroy, fp);

	fclose(fp);
}