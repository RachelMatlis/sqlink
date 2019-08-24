#include<stdlib.h>
#include"darray_generic.h"

struct darray {
	void **arr;
	int index;
	int capacity;
	int initial_capacity;
};

static void quicksort(darray * dArr, int first, int last, elementCompare compareFunc) {
	int i, j, pivot;
	void * temp;

	if (first<last) {
		pivot = first;
		i = first;
		j = last;
		while (i<j) {
			while ((compareFunc(dArr->arr[i], dArr->arr[pivot]) <= 0) && (i<last)) {
				i++;
			}

			while ((compareFunc(dArr->arr[j], dArr->arr[pivot])>0)) {
				j--;
			}

			if (i<j) {
				temp = dArr->arr[i];
				dArr->arr[i] = dArr->arr[j];
				dArr->arr[j] = temp;
			}
		}
		temp = dArr->arr[pivot];
		dArr->arr[pivot] = dArr->arr[j];
		dArr->arr[j] = temp;
		quicksort(dArr, first, j - 1, compareFunc);
		quicksort(dArr, j + 1, last, compareFunc);
	}
}

/* Create a new dynamic array. Return its address in d_arr.
The initial capacity is the number of items that can be stored
before a new allocation is needed. */
AdtStatus darrayCreate(darray **dArr, size_t initial_capacity)
{

	(*dArr) = malloc(sizeof(darray *));
	if (*dArr)
	{
		(*dArr)->arr = (void**)malloc(sizeof(void*) * initial_capacity);
		if (!(*dArr)->arr)
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
	int i=0;
	if (dArr)
	{
		for (i = 0; i< dArr->index; i++)
		{
			destroyFunc(dArr->arr[i], context);
		}

		free(dArr->arr);
		free(dArr);

		return OK;
	}

	return AllocationError;
}

/* Add elemnt to the end. */
AdtStatus darrayAdd(darray *dArr, void*  _item)
{
	void ** temp = NULL; 

	if (!dArr) {
		return AllocationError;
	}

	if (dArr->capacity == dArr->index)
	{
		temp = realloc(dArr->arr, sizeof(int) * (dArr->capacity * 2));
		if (temp)
		{
			dArr->arr = temp;
			dArr->capacity *= 2;
		}
		else
		{
			return AllocationError;
		}
	}

	dArr->arr[dArr->index] = _item;
	dArr->index++;
	return OK;
}

/* Delete number from the end. */
AdtStatus darrayDelete(darray *dArr, void** _item)
{
	void** temp;

	if (!dArr){
		return AllocationError;
	}

	dArr->index--;

	if ((dArr->index == (size_t)(((dArr->capacity) / 2)*(0.75))) && ((dArr->capacity)>(dArr->initial_capacity)))
	{
		temp = realloc(dArr->arr, (dArr->capacity / 2) * sizeof(void*));
		if (temp) 
		{
			dArr->arr = temp;
			dArr->capacity = dArr->capacity / 2;
		}
		else 
		{
			return AllocationError;
		}
	}

	*_item = dArr->arr[dArr->index];

	return OK;
}

AdtStatus darrayGet(darray *dArr, size_t _index, void **_item)
{
	if (dArr)
	{
		if (_index < dArr->index)
		{
			(*_item) = dArr->arr[_index];
			return OK;
		}
	}

	return AllocationError;
}

AdtStatus darraySet(darray *dArr, size_t _index, void  *_item)
{
	if (dArr)
	{
		if (_index <= dArr->index)
		{
			free(dArr->arr[_index]);
			dArr->arr[_index] = _item;
			return OK;
		}
	}

	return AllocationError;
}

AdtStatus darrayItemsNum(darray *dArr, int*  _numOfItems)
{
	if (dArr)
	{
		*_numOfItems = dArr->index;
		return OK;
	}

	return AllocationError;
}

/* in place (ascending) sorting an array of size arraySize */
AdtStatus darraySort(darray *dArr, elementCompare compareFunc)
{
	int  j = 0;
	if (!dArr) {
		return AllocationError;
	}

	quicksort(dArr, j, dArr->index - 1, compareFunc);

	return OK;
}