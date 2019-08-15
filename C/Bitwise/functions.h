#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#define INT_SIZE sizeof(int)        /* Size of int in bytes*/
#define INT_BITS (sizeof(int) * 8)    /* Size of int in bits - 1*/

typedef struct {
	int m_nf; /*number of featurs*/
	int* m_arr;
	int m_size;
} BitMap;


int bitOn(BitMap*, int);
int bitOff(BitMap* , int);
int bitStatus(BitMap*, int);

BitMap* crateBitMap(int);
void destroyBitMap(BitMap*);

void printArr(int*, int);

#endif
