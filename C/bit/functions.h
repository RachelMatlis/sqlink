#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#define INT_SIZE sizeof(int)        // Size of int in bytes
#define INT_BITS (sizeof(int) * 8)    // Size of int in bits - 1

typedef struct {
	int m_nf; /*number of featurs*/
	int* m_arr;
	int m_size;
} BitMap;


int bitOn(BitMap* bm, int n);
int bitOf(BitMap* bm, int n);
int bitOStatus(BitMap* bm, int n);

BitMap* crateBitMap(int nf);
void destroyBitMap(BitMap* bm);

void bin2Int(int);
void int2Bin(int);

#endif
