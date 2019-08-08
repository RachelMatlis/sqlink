#include<stdio.h>
#include <string.h>

void myStrcpy(char*, char* );
void myStrcat(char* , char* );
void myStrcmp();

void printString(char *str);




int main()
{
	char s1[20]= "Rachel 455 ";
	char s2[20] = "Matlis";
	
	myStrcpy(s1, s2);
}

/*Copies the string pointed by s1 into the array pointed by s2, including the terminating null character (and stopping at that point).*/
void myStrcpy(char * s1, char *s2)
{
	int i=0;
	
	for(i; i< strlen(s2) ; i++)
	{
		s1[i] = s2[i]; 
	}
	
	s1[i] = '\0';
	i= strlen(s2) + 1;
	
	for(i; i< strlen(s1); i++)
	{
		s1[i] = 0;
	}
	
	printString(s1);
}

/*Appends a copy of the source string to the destination string. The terminating null character in destination is overwritten by the first character of source, and a null-character is included at the end of the new string formed by the concatenation of both in destination.*/
void myStrcat(char* s1, char* s2 )
{
	
}

void printString(char* str)
{
	int i = 0;
	int size = strlen(str); 
	for (i; i<size ; i++)
	{
		printf("%c", str[i]);
	}
}










