/*
OVERVIEW: Given an Integer Array return the count of one's and two's in a new array of length two.
Ex: input: [1,2,2,1,2,1,2] 
	output: [3,4]
	where 3 is the count of 1's and 4 is the count of 2's

INPUTS: An Integer Array and length of the array 

OUTPUT: An Array with 1's count and 2's count

ERROR CASES: Return NULL for invalid inputs

Difficulty : Very Easy
*/
#include<stdlib.h>
#include <stdio.h>
int* oneTwoCount(int* input, int length)
{
	int i, k = 0, l = 0; int *a = (int *)malloc(2 * sizeof(int));
	if (length > 0)
	{
		for (i = 0; i < length; i++)
		{
			if (input[i] == 1)
				l++;
			if (input[i] == 2)
				k++;
		}
		a[0] = l; a[1] = k;
		return a;
	}
	else
	return NULL;
}