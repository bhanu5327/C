/*
Given an array which has two arithmetic sequences and
one geometric sequence (in any order).
Copy indexes where each sequence starts and ends into an Array and return it.

Note : Each sequence will be of atleast LENGTH 3,and The sequences can be overlapping

Ex : 1, 3, 5, 7, 2, 4, 8, 16 18 20, output is [0, 3, 7, 9, 4, 7]
Ex : 1 ,2, 4, 8, 12, 16, 21, 26     output is [2, 5, 5, 7, 0, 3]
Ex : 10 15 20 30 50 70 100 200 400 800  output is [0, 2, 3, 5, 6, 9]

The final_arr[0], final_arr[1] values in final array
will be start and end indexes of First A.P in the Original Array

The final_arr[2], final_arr[3] values in final array
will be start and end indexes of Second A.P

The final_arr[4], final_arr[5] values in final array
will be start and end indexes of First  G.P (Only)

Input: Array and Length of Array
Output : New Array which has 6 integers , which denote the (start,end) indexes .

Note : All elements in the array will be part of atleast 1 sequence .
Two A.P cannot start at same index .

Difficulty : Medium
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>


int * find_sequences(int *arr, int len){
	int i, j, k = 0, p = 0, t = 0; int *c = (int *)malloc(6 * sizeof(int));  c[0] = len; c[1] = -1; float z = -1, l =-2;
	c[2] = len; c[3] = -1; c[4] = len; c[5] = -1;
	if (arr != NULL)
	{
		for (i = 0, j = 1; j < len-1; i++, j++)
		{
			z = -0.5; l = 0.5;
			k = arr[i] - arr[i + 1];
			if (arr[i]>arr[i+1]&&arr[i+1]!=0&&arr[i]!=0)
			l = arr[i] / arr[i + 1];
			else if (arr[i]<arr[i + 1] && arr[i] != 0&&arr[i+1]!=0)
			l = arr[i+1] / arr[i];
			if (arr[j] - arr[j + 1] == k)
			{
				p= 1;
				if (c[t] > i)
					c[t] = i;
				if (c[t + 1] < j + 1) c[t + 1] = j + 1;
			}
			else
			{
				if (arr[j] > arr[j + 1] && arr[j + 1] != 0 && arr[j] != 0 && (arr[j] % arr[j + 1]) == 0) z = arr[j] / arr[j + 1];
				else if (arr[j] != 0 && arr[j + 1] != 0 && (arr[j + 1] % arr[j]) == 0) z = arr[j + 1] / arr[j];
	 if (z==l)
	{
		if (c[4] > i)
			c[4] = i;
		if (c[5] <= j + 1) c[5] = j + 1;
	}
	else
	{
		if (p == 1)
		{
			i = j - 1;
			t = 2;
		}
		p = 0;
	}
			}

		}
		return c;
	}
	return NULL;
}