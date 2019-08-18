#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_


typedef struct{
   unsigned int left :4;
   unsigned int right: 4;
} LRchar;

union un
{
	char c;
    LRchar lr;
};

int packWithoutBitField(char *s);
int packWithBitField(char *s);

#endif


