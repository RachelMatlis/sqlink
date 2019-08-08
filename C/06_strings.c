#include<stdio.h>
#include <string.h>

long int2Bin(int);
int Bin2Int(long);
void squeeze(char*, char*);
int location(char*, char*);

void printString(char*);
void removeChar(char*, char);

int main()
{
	char s1[20] = "ABCDAB";
	char s2[20] = "DA";
	char s3[20] = "BBCDEK";
	char s4[20] = "BKE";
	int locationRes;

	printf("--- Q2 ---\n");
	printf("string 1: %s\n", s3);
	printf("string 2: %s\n", s4);
	printf("After squeeze: ");
	squeeze(s3 , s4);
	printf("\n");

	printf("--- Q3 ---\n");
	printf("string 1: %s\n", s1);
	printf("string 2: %s\n", s2);
	locationRes = location(s1, s2);
	printf("Index: %d", locationRes);

	printf("\n");

	return 0;

}

long int2Bin(int num)
{

}
int Bin2Int(long binNum)
{

}

void squeeze(char* s1, char* s2)
{
	int i = 0;
	char charToDelte;
	if (s1 != NULL && s2 != NULL)
	{
		while (s2[i] != '\0')
		{
			charToDelte = s2[i];
			removeChar(s1, charToDelte);
			i++;
		}

		printString(s1);
	}	
}

void removeChar(char *s, char c)
{
	int i = 0, j = 0;
	for (i; i<strlen(s); i++)
	{
		if (s[i] != c)
		{
			s[j] = s[i];
			j++; 
		}
	}

	s[j] = '\0';
}

int location(char* s1, char* s2)
{
	int i = 0, j = 0, returendIndex = -1;

	if (s1 != NULL && s2 != NULL)
	{
		for (i; i<strlen(s1); i++)
		{
			if (s1[i] == s2[j])
			{
				returendIndex = i;

				while (s1[i] == s2[j]) /*checks if all s2 is in s1*/
				{
					i++;
					j++;
				}

				if (s2[j] == '\0') /*s2 is in s1*/
				{
					break;
				}
				else /*not all s2 is in s1*/
				{
					j = 0;
					returendIndex = -1;
				}
			}
		}
	}

	return returendIndex;
}

void printString(char* str)
{
	int i = 0;
	int size = strlen(str);
	for (i; i<size; i++)
	{
		printf("%c", str[i]);
	}
}
