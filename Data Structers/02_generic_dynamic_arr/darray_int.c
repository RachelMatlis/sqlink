#include<stdio.h>
#include<stdlib.h>
#include"darray_int.h"

struct darray{
	void **arr; 
	int index;
	int capacity; 
};

/* Create a new dynamic array. Return its address in d_arr.
   The initial capacity is the number of items that can be stored
   before a new allocation is needed. */
AdtStatus darrayCreate(darray **dArr, size_t initial_capacity)
{

	(*dArr) =  malloc(sizeof(darray *));
	if(*dArr)
	{
		(*dArr)->arr = (void**)malloc(sizeof(void*) * initial_capacity);
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

AdtStatus darrayDestroy(darray *dArr, elementDestroy destroyFunc, void *context)
{
	int i;
	if(dArr)
	{
		for(i=0;i< dArr->index;i++)
		{
			destroyFunc( dArr->arr[i], context);
		}

		free(dArr->arr);
		free(dArr);

		return OK;
	}

	return AllocationError;
}

/* Add number to the end. */
AdtStatus darrayAdd(darray *dArr,  void*  _item)
{
	if(dArr)
	{
		if(dArr->capacity  > dArr->index)
		{
			dArr->arr[dArr->index] = _item;
			dArr->index++;
		}
		else
		{
			dArr->arr = realloc(dArr->arr,sizeof(int) *2 *dArr->capacity);
			dArr->arr[dArr->index] = _item;
			dArr->index++;
			dArr->capacity*=2;
		}
		
		return OK;
	}

	return AllocationError;
}

/* Delete number from the end. */
AdtStatus darrayDelete(darray *dArr,  void** _item)
{
	return OK;
}

AdtStatus darrayGet(darray *dArr, size_t _index, void **_item)
{
	if(dArr)
	{
		if(_index < dArr->index)
		{
			(*_item) =dArr->arr[_index];
			return OK;
		}
	}

	return AllocationError;
}

AdtStatus darraySet(darray *dArr, size_t _index, void  *_item)
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

AdtStatus darrayItemsNum(darray *dArr, int*  _numOfItems)
{
	if(dArr)
	{
		(*_numOfItems) = dArr->index;
		return OK;
	}

	return AllocationError;
}

/* in place (ascending) sorting an array of size arraySize */
AdtStatus darraySort(darray *dArr)
{
	/*bubble sort*/
	return OK;
}