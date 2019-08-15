#include "functions.h"
#include <stdio.h>
#include<stdlib.h>


/*return the index of array that contain the bit number */
static int findIndexOfBitInArray(int bitNum, int size)
{
	int i = 0, index = 0;

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

	if (!bm || bitNum > INT_BITS*bm->m_size) { /*check if null pointer or if bit number is bigger that arrays bits*/
		return -1;
	}

	index = findIndexOfBitInArray(bitNum, bm->m_size);
	leftShiftTimesCount = (INT_BITS * (index +1)) - bitNum; /*find how many time to shift left (num of last bit in arr[index] - bit recieved number)*/

	mask = mask << leftShiftTimesCount;

	return (bm->m_arr[index] | mask);
}

int bitOff(BitMap* bm, int bitNum)
{
	int index = 0, mask = 1,mask2 ,leftShiftTimesCount = 0;
	int res;

	if (!bm || bitNum > INT_BITS*bm->m_size) { /*check if null pointer or if bit number is bigger that arrays bits*/
		return -1;
	}

	index = findIndexOfBitInArray(bitNum, bm->m_size);
	leftShiftTimesCount = (INT_BITS * (index + 1)) - bitNum;

	mask = mask << leftShiftTimesCount;

	return (bm->m_arr[index] & (~mask)); /*not mask & target*/

}

int bitStatus(BitMap* bm, int bitNum)
{
	int index = 0, mask = 1, leftShiftTimesCount = 0;

	if (!bm || bitNum > INT_BITS*bm->m_size) { /*check if null pointer or if bit number is bigger that arrays bits*/
		return -1;
	}

	index = findIndexOfBitInArray(bitNum, bm->m_size);
	leftShiftTimesCount = (INT_BITS * (index + 1)) - bitNum; /*find how many time to shift left (num of last bit in arr[index] - bit recieved number)*/

	mask = mask << leftShiftTimesCount;

	return !(bm->m_arr[index] & mask);
}

void destroyBitMap(BitMap* bm)
{
	int i = 0;
	if (bm)
	{
		if (bm->m_arr)
		{
			for (i; i < bm->m_size; i++)
			{
				free((bm->m_arr[i]));
			}

			free(bm->m_arr);
		}

		free(bm);
	}
}

void printArr(int *arr, int size)
{
	int i = 0;
	for (i; i < size - 1; i++)
	{
		printf("%d, ", arr[i]);
	}

	printf("%d.\n", arr[i]);
}
