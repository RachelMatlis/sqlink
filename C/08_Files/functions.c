/* In general it's good to include also the header of the current .c,
   to avoid repeating the prototypes */
#include "functions.h"
#include <stdio.h>
#include<stdlib.h>

void printLastN()
{
	
}
void findFreqOfChar(char *fileName)
{
	char c=' ';
	int freq[26] = { 0 };
	int i = 0, isUnique =1;
	FILE* fptr;

	fptr = fopen(fileName, "r");
	if (fptr == NULL) {
		return;
	}

	/* Find total number of occurrences of each character */
	while (!feof(fptr))  /* while not end of file*/
	{
		c = fgetc(fptr);
		if (c >= 'a' && c <= 'z')
		{
			freq[c - 97]++;
		}
		else if (c >= 'A' && c <= 'Z')
		{
			freq[c - 65]++;
		}
	}

	printf("\nFrequency of each char:\n");
	/* Print the frequency of all characters in the string */
	for (i; i<26; i++)
	{
		/* If current character exists in given string */
		if (freq[i] > 0)
		{
			printf("%c  %d\n", (i + 97), freq[i]);
		}
	}

	fclose(fptr);
}

void findFreqOfword(char *fileName)
{
	
}
