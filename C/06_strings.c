#include<stdio.h>
#include <string.h>


long int2Bin(int); 
int Bin2Int(long);
void squeeze(char* , char*);
int location(char* , char*);

void printString(char*);
void removeChar(char*, int);

int main()
{
	char s1[20]= "ABCDAB";
	char s2[20] = "ABX";
	int locationRes;
	
	char s3[20]= "ABCDEF";
	char s4[20] = "BKE";
	
	printf("--- Q2 ---\n");
	printf("string 1: %s\n", s1);
	printf("string 2: %s\n", s2);
	printf("After squeeze: %s\n", s2);
	/*squeeze(s3 , s4);
	printString(s3);
	printf("\n");*/
	
	printf("--- Q3 ---\n");
	printf("string 1: %s\n", s1);
	printf("string 2: %s\n", s2);
	locationRes = location(s1, s2);
	printf("Index: %d", locationRes);
	
}

long int2Bin(int num)
{
	
}
int Bin2Int(long binNum)
{
	
}

void squeeze(char* s1, char* s2)
{
	int i=0, j=0;
	char cToDelte; 
	
	while(s2[i] != '\0')
	{
		cToDelte = s2[i];
		
		for(j; j< strlen(s1) -1; j++)
		{
			removeChar(s1, cToDelte);
		}
		
		j=0;
	}
}

int location(char* s1, char* s2)
{
	int i=0, j=0, returendIndex= -1;
	
	if(s1 != NULL && s2 != NULL)
	{
		for(i; i<strlen(s1) ; i++)
		{
			if(s1[i] == s2[j])
			{
				while(s1[i] == s2[j])
				{
					returendIndex = i-1;
					i++;
					j++;
				}
				
				if(s2[j] == '\0')
				{
					break;
				}
				else
				{
					j=0;
					returendIndex = -1;
				}
			}
		}	
	}
	
	return returendIndex;
}

void removeChar(char *s, int c)
{
	int j=0,i=0, n = strlen(s); 
    for (i=j=0; i<n; i++) 
    {
    	if(s[i] != c)
        {
			s[j++] = s[i]; 
        } 
    }
          
    s[j] = '\0'; 
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










