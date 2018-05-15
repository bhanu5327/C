
/*
OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1) 

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:
*/

#include <stdio.h>

int maxPosNegSum(int* input,int length)
{
	int i = 0,x=0,k=0,y,l=0;
	if (length <= 0)
		return 0;
	else
	{
		for (i = 0; i < length; i++)
		{
			
			if (input[i] >= 0)
			{
				l++;
				if (l==1 || input[i] > x)
					x= input[i];
			}
		}
		for (i = 0; i < length; i++)
		{
			if (input[i] < 0)
			{
				k++;
				if (k == 1 || input[i] > y)
					y = input[i];
			}
		}
		if (k >0&&l>0)
			return x + y;
		else
			return 0;
	}
	}