/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SAP
*/

#include <stdio.h>

void * sortedArrayPositionsChange(int *Arr, int len)
{
	int i, j=0, k,p; int a[2];
	if (len > 0 && Arr != NULL)
	{
		for (i = 0; i < len-1; i++)
		{
			if (i == 0)
			{
				if (Arr[i]>Arr[len-1])
				{
					a[0] = 0; a[1] = len - 1; j = 2; break;
				}

			}
			else if ((Arr[i] > Arr[i + 1] && Arr[i]>Arr[i - 1]&&j==0) ||( Arr[i] < Arr[i + 1] && Arr[i]<Arr[i - 1]&&j!=0)||(i==0&&Arr[i]>Arr[i+1]))
			{
  				a[j] = i; j++;
			}

		}
		if (j == 1) a[1] = len - 1;
		i = a[0]; k = a[1];
		if (j != 0)
		{
			p = Arr[i];
			Arr[i] = Arr[k];
			Arr[k] = p;
			
		}
		return Arr;
	}
	else
	return NULL;
}