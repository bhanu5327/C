/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use memory allocation techniques to allocate memory.

ProblemCode :SAIN
*/

#include <stdio.h>
#include <malloc.h>

int * sortedArrayInsertNumber(int *Arr, int len, int num)
{
	int i, j=0, k=0,p=len+1; int *a ;
	if (len > 0&& Arr!=NULL)
	{
		a = (int *)malloc(p * sizeof(int));
		for (i = 0; i < len; i++)
		{
			if (Arr[i] >= num)
			{
				a[k] = num; k++; j = 1;
			}
			a[k] = Arr[i];
			k++;
		}
		if (j == 0)
			a[k] = num;
		return a;
	}
	else
	return NULL;
}