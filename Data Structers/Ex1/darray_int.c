#include<stdio.h>
#include<stdlib.h>

struct darray{
	int *arr; 
	int index;
	int capacity; 
};


/* Create a new dynamic array. Return its address in d_arr.
   The initial capacity is the number of items that can be stored
   before a new allocation is needed. */
AdtStatus DarrayCreate(darray **dArr, size_t initial_capacity)
{

	(*dArr) = (*darray)malloc(sizeof(darray));
	if(*dArr)
	{
		(*dArr)->arr = (int*)malloc(sizeof(int) * initial_capacity);
		if(!(*dArr)->arr )
		{
			free(*dArr);
			return AllocationError;
		}

		(*dArr)->capacity = initial_capacity;
		(*dArr)->index = 0;
	}
	else
	{
		return AllocationError;
	}

	return OK;
}

AdtStatus DarrayDestroy(darray *dArr)
{
	if(dArr)
	{
		if(dArr->arr)
		{

			free(dArr->arr);
		}

		free(dArr);
		return OK;
	}

	return AllocationError;
}

/* Add number to the end. */
AdtStatus DarrayAdd(darray *dArr,  int  _item)
{
	if(dArr)
	{
		if(dArr->capacity  > dArr->index)
		{
			dArr->arr[index] = _item;
			dArr->index++;
		}
		else
		{
			dArr->arr = realloc(dArr->arr,sizeof(int) *2 *dArr->capacity);
			dArr->arr[index] = _item;
			dArr->index++;
			dArr->capacity*=2;
		}
		
		return OK;
	}

	return AllocationError;
}

/* Delete number from the end. */
AdtStatus DarrayDelete(darray *dArr,  int* _item)
{
	if(dArr)
	{

	}
}

AdtStatus DarrayGet(darray *dArr, size_t _index, int *_item)
{
	if(dArr)
	{
		if(_index < dArr->index)
		{
			_item =dArr->arr[_index];
			return OK;
		}
	}

	return AllocationError;
}

AdtStatus DarraySet(darray *dArr, size_t _index, int  _item)
{
	if(dArr)
	{
		if(_index <= dArr->index)
		{
			dArr->arr[_index] = _item;
			return OK;
		}
	}

	return AllocationError;
}

AdtStatus DarrayItemsNum(darray *dArr, int*  _numOfItems)
{
	if(dArr)
	{
		_numOfItems = dArr->index;
		return OK;
	}

	return AllocationError;
}

/* in place (ascending) sorting an array of size arraySize */
AdtStatus DarraySort(darray *dArr, size_t arraySize)
{
	/*bubble sort*/
}