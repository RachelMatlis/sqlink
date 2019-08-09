#include<stdio.h>
#include <string.h>

void myStrcpy(char*, char*);
void myStrcat(char*, char*);
int myStrcmp(char*, char*);

void printString(char *str);

int main()
{
	char s1[30] = "Rachel";
	char s2[30] = "Matlis";
	char s3[30] = "Rachel";
	char s4[30] = "Matlis";
	char s5[30] = "Rachel";
	char s6[30] = "Rachel";
	int strcmpRes;


	printf("Strcpy(%s, %s)= ", s1, s2);
	myStrcpy(s1, s2);

	printf("\nStrcat(%s, %s)= ", s3, s4);
	myStrcat(s3, s4);

	printf("\nStrcmp(%s, %s)= ", s5, s6);
	strcmpRes = myStrcmp(s5, s6);
	printf("%d", strcmpRes);

	printf("\n");
}

/*Copies the string pointed by s1 into the array pointed by s2, including the terminating null character (and stopping at that point).*/
void myStrcpy(char * s1, char *s2)
{
	int i = 0;
	for (i; i< strlen(s2); i++)
	{
		s1[i] = s2[i];
	}

	s1[i] = '\0';
	i = strlen(s2) + 1;

	for (i; i< strlen(s1); i++)
	{
		s1[i] = 0;
	}

	printString(s1);
}

/*Appends a copy of the source string to the destination string. The terminating null character in destination is overwritten by the first character of source, and a null-character is included at the end of the new string formed by the concatenation of both in destination.*/
void myStrcat(char* s1, char* s2)
{
	int i  = (strlen(s1)) + 1; /*s1 end index*/
	int j = 0; /*s2 start index*/

	s1[i - 1] = ' ';

	while (s2[j] != '\0')
	{
		s1[i++] = s2[j++];
	}

	s1[i] = '\0';

	printString(s1);

}

/*Compares the C string str1 to the C string str2.
This function starts comparing the first character of each string. If they are equal to each other, it continues with the following pairs until the characters differ or until a terminating null-character is reached.*/
int myStrcmp(char* s1, char* s2)
{
	int i = 0;

	for (i; strlen(s1); i++)
	{
		if (s1[i] != s2[i])
		{
			if (s1[i] < s2[i])
			{
				return -1;
			}
			else
			{
				return 1;
			}
		}

		if (s1[i] == '\0' && s2[i] == '\0')
		{
			return 0;
		}
	}
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
