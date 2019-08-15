#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

typedef struct{
	int m_nf; /*number of fichers*/
	int* m_arr;
} BitMap;


int bitOn(BitMap* bm, int n);
int bitOf(BitMap* bm, int n);
int bitOStatus(BitMap* bm, int n);

BitMap* crateBitMap(int nf);
void destroyBitMap(BitMap* bm);

void bin2Int(int);
void int2Bin(int);

#endif

