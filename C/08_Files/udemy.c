#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include<conio.h>


/*find total numbers of lines in a text file*/
int countLines(FILE* fptr)
{
	int linesCount = 0;
	char c;
	while ((c = fgetc(fptr)) != EOF)
	{
		if (c == '\n')
			linesCount++;
	}

	printf("Read %d lines\n", ++linesCount);
}

/*convert all file content to upper case chars*/
void convertAllToUpperCase(FILE* fptr)
{
	FILE* fptrTemp = NULL;
	char c=' ';

	//crate temp file
	fptrTemp = fopen("temp.txt", "w");
	if (fptrTemp == NULL)
	{
		perror("Error in open file");
		exit(0);
	}

	while ((c = fgetc(fptr)) != EOF)
	{
		fputc(toupper(c), fptrTemp);
	}

	printf("\n");

	fclose(fptrTemp);
	fptrTemp = NULL;
}

/*print the contents of a file in reverse order*/
void printReverseOrder(FILE* fptr)
{
	int position = 0;
	//move the file pointer to the end of file
	fseek(fptr, 0, SEEK_END);
	//get the position of the file pointer
	position = ftell(fptr);

	//display the file in reverse order
	while (position >=0)
	{
		printf("%c", fgetc(fptr));
		//move the file pointer backwards to the previous block
		fseek(fptr, --position, SEEK_SET);
	}

}

int main()
{
	FILE* fptr = NULL;
	int choice = 0;

	fptr = fopen("test.txt", "r");
	if (fptr == NULL)
	{
		perror("Error in open file");
		exit(0);
	}

	while (choice!= -1)
	{
		rewind(fptr);
		printf("Choose function:\n");
		printf("1. Print total numbers of lines in the text file\n");
		printf("2. Convert all file content to upper case chars\n");
		printf("3. Print the contents the file in reverse order\n");
		printf("-->Press -1 to exit\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			countLines(fptr);
			break;
		case 2:
			convertAllToUpperCase(fptr);
			printf("Crated new file with name temp.txt\n");
			break;
		case 3:
			printReverseOrder(fptr);
			break;
		case -1:
			fclose(fptr);
			fptr = NULL;
			return 0;
			break;
		default:
			printf("Invalid input\n");
			break;
		}

		getch(); // wait for character from the keyboard
		system("cls");// clear the screem
	}

	return 0;
}