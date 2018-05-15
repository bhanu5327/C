/*
OVERVIEW: Given an array where every element occurs three times, except one element which occurs only
once. Find the element that occurs once.
E.g.: Input: arr = 12, 1, 12, 3, 12, 1, 1, 2, 3, 3
ouput: 2

INPUTS: Integer array and length of the array.

OUTPUT: Element that occurs only once.

ERROR CASES: Return -1 for invalid inputs.

NOTES:
There are better ways of solving the problem than a brute-force solution which is of O(n^2)
complexity .
*/

#include<stdio.h>
#include <stdlib.h>
void merge(int *A, int low, int high, int len);
void mg(int *A, int low, int mid, int high);
int *b;
int findSingleOccurenceNumber(int *A, int len) {
	int i;
	if (A != NULL)
	{
		b = (int*)malloc(len*sizeof(int));
		merge(A, 0, len - 1, len);
		for (i = 0; i < len; i++)
		{
			if (i == 0)
			{
				if (A[i] != A[i + 1])
					break;
			}
			else if (i == len - 1)
			{
				break;
			}
			else
			{
				if (A[i] != A[i - 1] && A[i] != A[i + 1])
					break;
			}
		}
		
		return A[i];
	}
	else return -1;
}
void merge(int *A, int low, int high, int len)
{
	int mid;
	if (low < high)
	{
		mid = (low + high) / 2;
		merge(A, low, mid, len);
		merge(A, mid + 1, high, len);
		mg(A, low, mid, high);
	}
}
void mg(int *A, int low, int mid, int high)
{
	int i = low, j = mid + 1; int v = low;
	while (i <= mid &&j <= high)
	{
		if (A[i] < A[j])
			b[v++] = A[i++];
		else
		{
			b[v++] = A[j++];
		}
	}
	if (i == mid + 1)
	{
		while (j <= high)
		{
			b[v++] = A[j++];
		}
	}
	else
	{
		while (i <= mid)
		{
			b[v++] = A[i++];
		}
	}
	for (v = low; v <= high; v++)
	{
		A[v] = b[v];
	}
}
