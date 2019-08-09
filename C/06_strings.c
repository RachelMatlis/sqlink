#include<stdio.h>
#include <string.h>

void int2Bin();
void bin2Int();
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
	int num, bin;
	int choice;

	do
	{
		printf("\nChoose function or quite:\n");
		printf("1. int2Bin()\n");
		printf("2. bin2Int()\n");
		printf("3. squeeze()\n");
		printf("4. location()\n");
		printf("5. Quite\n");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			int2Bin();
			break;
		case 2:
			bin2Int();
			break;
		case 3:
			printf("string 1: %s\n", s3);
			printf("string 2: %s\n", s4);
			printf("After squeeze: ");
			squeeze(s3, s4);
			break;
		case 4:
			printf("string 1: %s\n", s1);
			printf("string 2: %s\n", s2);
			locationRes = location(s1, s2);
			printf("Index: %d\n", locationRes);
			break;
		case 5:
			printf("Goodbye!\n");
			break;
		default: printf("Wrong Choice. Enter again\n");
			break;
		}

	} while (choice != 5);

	return 0;
}

/*To convert integer to binary,
start with the integer in question and divide it by 2 keeping notice of the quotient and the remainder.
Continue dividing the quotient by 2 until you get a quotient of zero.
Then just write out the remainders in the reverse order.*/
void int2Bin()
{
	int binary[10], decimal, i = 0, size = 0;
	printf("Enter decimal number: ");
	scanf("%d", &decimal);

	while (decimal > 0)
	{
		binary[i] = decimal % 2;
		size++;
		decimal /= 2;
		i++;
	}

	printf("-> Binary: ");
	for (i = size - 1; i >= 0; i--)
	{
		printf("%d", binary[i]);
	}

	printf("\n");
}

/* 1001 -> 2^3 * 1 + 2^2 * 0 + 2^1 * 0 + 2^0 * 1
2^0 is the first wight, 2^1 second..*/
void bin2Int()
{
	int binary;
	int decimal = 0, weight = 1, rem;
	printf("Enter binary number: ");
	scanf("%d", &binary);

	while (binary != 0)
	{
		rem = binary % 10;
		decimal += rem * weight;
		binary /= 10;
		weight *= 2;
	}

	printf("-> Decimal: %d", decimal);
	printf("\n");
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
		printf("\n");
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

				if (s2[j] == '\0') /*all s2 is in s1*/
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
