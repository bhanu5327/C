





















/*
Write a program to generate elements of a matrix in spiral order.
Store the generated elements in single dimensional array and return that array.

Directions for Spiral are : Go Right ,Go Down ,Go Left, Go Up
Ex:

Matrix:
1	2	3
4	5	6
7	8	9

Spiral order:
1	2	3	6	9	8	7	4	5

Given matrix is a two dimensional array(input_array) with dimensions rows, columns.
If rows, columns are invalid then return NULL.
If input_array is NULL then return NULL.

Example Input :
int board[2][3]={
				 {4,6,7},
				 {1,3,8}
				};
spiral(2,2,(int **)board); // Rows followed by columns followed by board

Example Output : Return an array consisting of {4,6,7,8,3,1};

Note : Check the function Parameters ,Its a double pointer .

*/


#include "stdafx.h"
#include<stdlib.h>

int *spiral(int rows, int columns, int **input_array)
{
	if (input_array == NULL || rows <= 0 || columns <= 0) return NULL;
	int i;
	static int n = rows*columns, k = 0, p = 0, m1 = columns - 1, m2 = rows - 1, m3 = 0, p1 = 0, p2 = columns - 1, q1 = 1, q2 = rows - 2, r1 = columns - 1, r2 = 0, s1 = rows - 2, s2 = 1;
	static int*a; int* b;
	if (k == 0)
	{
	 n = rows*columns, k = 0, p = 0, m1 = columns - 1, m2 = rows - 1, m3 = 0, p1 = 0, p2 = columns - 1, q1 = 1, q2 = rows - 2, r1 = columns - 1, r2 = 0, s1 = rows - 2, s2 = 1;

		a = (int*)malloc(n*sizeof(int));

	}
	
	if (k == n)
	{
		k = 0;

		return a;
	}

	if (p == 0)
	{
		for (i = p1; i <= p2; i++)
		{
			a[k++] = input_array[p1][i];
		}
		p1++; p2--;
	}
	else if (p == 1)
	{
		for (i = q1; i <= q2; i++)
		{
			a[k++] = input_array[i][m1];
		}
		q1++; q2--; m1--;
	}
	else if (p == 2)
	{
		for (i = r1; i >= r2; i--)
		{
			a[k++] = input_array[m2][i];
		}
		r1--; r2++; m2--;
	}
	else if (p == 3)
	{
		for (i = s1; i >=s2; i--)
		{
			a[k++] = input_array[i][m3];
		}
		s1--; s2++; m3++;
	}
	if (p == 3) p = -1;
	p++;
	b=spiral(rows, columns, input_array);
	return a;
}
