/* In general it's good to include also the header of the current .c,
   to avoid repeating the prototypes */
#include "functions.h"
#include <stdio.h>
#include<stdlib.h>

BitMap* crateBitMap(int nf)
{
/*add +1 if not % ==0*/
	int np, size;
	BitMap* bm =(BitMap*)malloc(sizeof(BitMap));
	
	if(!bm){
		return NULL;
	}
	
	bm->m_nf= nf;
	
	size = nf/sizeof(int);
	bm->m_arr= (int*)calloc(bm->m_arr,sizeof(int)*size);
	if(!(bm->m_arr)){
		return NULL;
	}
	
		
	return bm;
}

int bitOn(BitMap* bm, int n)
{
	int i=0;
	int *a;
	int c = 1;
	int res;
	int loc_byt1 = 0;
	int loc_bit2 ;
	int result = -1;

	int num, num1;

	if(n% sizeof(int)*8 == 0)
	{
		num1 = n/ sizeof(int)*8;
	}
	else
	{
		num1 = n/ (sizeof(int)*8)+1;	
	}

	int arrayOfBits = bm->m_arr[num];

	num = num1 << n%(sizeof(int)*8); 
	

	res = num | bm->m_arr[num1];
	

	int2Bin(res);
			
}

int bitOf(BitMap* bm, int n)
{
	
}

int bitOStatus(BitMap* bm, int n)
{
	
}

void destroyBitMap(BitMap* bm)
{
	
}

void bin2Int(int binary)
{
	int decimal = 0, weight = 1, rem;
	
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

void int2Bin(int decimal)
{
	int binary[33], i = 0, size = 0;

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






