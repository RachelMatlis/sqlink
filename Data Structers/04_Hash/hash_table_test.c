#include<stdio.h>
#include<stdlib.h>
#include"hash_table.h"

static void testFunc();
void freeElemnt(void *elemnt);
int compareElemnts(void *elemnt_A, void* elemnt_B);
hash_size def_hashfunc(void *key);

int main()
{
	testFunc();
	return 0;
}

void testFunc()
{
	int choice=0;
	char data1[] = "Rachel";
	int key1 = 20;

	char data2[] = "lali";
	int key2 = 20;

	HASHTBL *hashtbl = NULL;
	hashtbl = hashtbl_create(3, def_hashfunc, compareElemnts);
	hashtbl_insert(hashtbl, &key1, data1); 
	hashtbl_insert(hashtbl, &key2, data2);

	do
	{
		printf("\nChoose Function:\n");
		printf("1.\n");
		printf("2.\n");
		printf("3.\n");
		printf("4.\n");
		printf("5.Exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			printf("GoodBye!\n");
			break;
		default:
			break;
		}
	} while (choice !=5);

}

void freeElemnt(void *elemnt)
{
	struct hashNode_s *oldnode;
	struct hashNode_s *elemnt1 = (struct hashNode_s*) elemnt;
	char *key = (char*) elemnt1->key;
	char *data = (char*) elemnt1->data;

	free(elemnt1->key);
	oldnode = elemnt1;
	elemnt1 = elemnt1->next;
	free(oldnode);
}

int compareElemnts(void *elemnt_A, void* elemnt_B)
{
	char* str1 = (char*) elemnt_A;
	char* str2 = (char*) elemnt_B;

	if (!strcmp(str1, str2)) 
	{
			return 0;
	}

	return -1;
}

hash_size def_hashfunc(void *key) 
{
	hash_size hash = 0;
	char* myKey = (char*) key;
	while (*myKey) 
	{
		hash += (char)*myKey++; /*take asci code for evry letter and sum*/
	}
	return hash;
}
