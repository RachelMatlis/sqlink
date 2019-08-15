#include "functions.h"
#include <stdio.h>
#include<stdlib.h>

BitMap* crateBitMap(int nf)
{
	BitMap* bm = (BitMap*)malloc(sizeof(BitMap));

	if (bm)
	{
		bm->m_nf = nf; /*set num of featurs*/
		bm->m_size = nf%INT_BITS == 0 ? (nf / INT_BITS) : ((nf / INT_BITS) + 1); /*canculate size of array*/
		bm->m_arr = (int*)calloc(bm->m_size, sizeof(int)); /*set array size and initial to 0*/
		if (bm->m_arr) 
		{
			return bm;
		}
	}

	return NULL;
}

int bitOn(BitMap* bm, int bitNum)
{
	int index = 0, mask = 1, leftShiftTimesCount = 0;

	if (!bm || bitNum > INT_BITS*bm->m_size) { /*if null pointer or bit number is bigger that arrays bits*/
		return -1;
	}

	index = findIndexOfBitInArray(bitNum, bm->m_size);
	leftShiftTimesCount = (INT_BITS * (index +1)) - bitNum; /*find how many time to shift left (num of last bit in arr[index] - bit recieved number)*/

	mask = mask << leftShiftTimesCount;

	return (bm->m_arr[index] | mask);
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

/*return the index of array that contain the bit number */
static int findIndexOfBitInArray(int bitNum, int size)
{
	int i = 0, index =0;

	for (i = INT_BITS; i <= (INT_BITS*size); i += INT_BITS)
	{
		if (bitNum > i)
		{
			index++;
		}
		else
		{
			break;
		}

	}

	return index;
}