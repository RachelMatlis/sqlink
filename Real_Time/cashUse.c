#include<iostream>
#include<time.h>

using namespace std;


void window(int *arr, int size);
void noWindow(int *arr, int size);

int main()
{
	int size = (4096*4096);
	int *arr = new int[size];

	for(int i=0; i<size; i++)
	{ 
        arr[i] = (rand()%1000000)+1; 
    }

  	/*for(int i=0; i< size; i++)
	{
		arr[i]++;
		arr[i]/=2;
		arr[i]*= arr[i];
	}*/

	int window= 10000; 
	int j=0, k=0;

	for(int i=0 ;i< size; i+=size)
	{
		j=0;
		for(j=0; j< window;j++ )
		{
			arr[k]++;
			arr[k]/=2;
			arr[k]*= arr[i];
			k++;
		}
	}

	return 0;
}


