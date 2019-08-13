#include <stdio.h>
#include <string.h>


void findFreqOfChar(char *fileName);
void findFreqOfword(char *fileName);

int main()
{

	int choice = 0;
	char fileName[100];

	do
	{
		printf("\nChoose function or quite:\n");
		printf("1. printLastN()()\n");
		printf("2. findFreqOfChar()\n");
		printf("3. findFreqOfword()\n");
		printf("4. Quite\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			break;
		case 2:
			printf("Enter file name: ");
			scanf("%s", fileName);
			findFreqOfChar(fileName);
			break;
		case 3:
			printf("Enter file name: ");
			scanf("%s", fileName);
			findFreqOfword(fileName);
			break;
		case 4:
			printf("Goodbye!\n");
			break;
		default: printf("Wrong Choice. Enter again\n");
			break;
		}

	} while (choice != 4);
	

	return 0;

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

	//* Find total number of occurrences of each character */
	while (!feof(fptr))  // while not end of file
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
	FILE *fptr = NULL;
	int i=0, index=0, isUnique=1;

	/* List of distinct words*/
	char words[50][50];
	char word[50] = {0};

	/* Count of distinct words*/
	int  count[50];

	fptr = fopen(fileName, "r");
	if (fptr == NULL){
		return;
	}

	while (fscanf(fptr, "%s", word) != EOF)
	{
		/* Convert word to lowercase*/
		strlwr(word);

		/* Check if word exits in list of all diffrent words*/
		isUnique = 1;
		for (i ; i<index && isUnique; i++)
		{
			if (strcmp(words[i], word) == 0)
				isUnique = 0;
		}

		/* If word is unique then add it to distinct words list
		   and increment index. Otherwise increment occurrence
		   count of current word. */
		if (isUnique)
		{
			strcpy(words[index], word);
			count[index]++;

			index++;
		}
		else
		{
			count[i - 1]++;
		}
	}

	printf("\nOccurrences of all diffrent words in file: \n");
	for (i = 0; i<index; i++)
	{
		printf("%-15s  %d\n", words[i], count[i]);
	}

	fclose(fptr);
}
