#include "functions.h"
#include <stdio.h>
#include<stdlib.h>
#include<string.h>


 void decToBinary(char c) 
{ 
	int i=0;
	 for (i = 0; i < 8; i++) {
      printf("%d", !!((c << i) & 0x80));
  }
} 

int packWithoutBitField(char *s) /*1*/
{
	int i= 0, j=0;
	char c;
	
	printf("Without Bit Field\n");
	for(i; i< strlen(s)-1;i++)
	{	
		s[i] = (s[j] - 'a') << 4;
		s[i] |= s[i+1];
		j+=2;
		
		decToBinary(s[i]);
		printf("\n");
	}
		
	return 1;
}


int packWithBitField(char *s) 
{
	int i=0, j=1;
	union un Union;
	
	printf("\nWith Bit Field\n");
	for(i; i<strlen(s)-1;i++)
	{
		Union.lr.left = (s[i] - 'a');
		Union.lr.right = (s[j] - 'a');
		s[i]= Union.c;
		j++;
		
		decToBinary(s[i]);
		printf("\n");
	}
	
}




