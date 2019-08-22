#include<stdio.h>
#include<stdlib.h>
#include"linkedList.h"

void testFunc()
{
	node_t* list = NULL;
	list = createList();
	list = push(list, 2);
	list = push(list, 200);

	printf("%d\n",list->next->next->val );
}

int main()
{
	testFunc();
	return 0;
}