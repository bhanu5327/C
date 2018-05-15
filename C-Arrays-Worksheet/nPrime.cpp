
/*
OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7] 

INPUTS: An Integer N

OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)

ERROR CASES: Return NULL for invalid inputs

Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}
NOTES:

Try to think of a optimized way , and avoid unnecessary comparisons.
*/
#include<stdlib.h>
#include <stdio.h>
int* nPrime(int N)
{
	int i, j, k,p=0;
	int *a1;
	int *a = (int *)malloc(100 * sizeof(int));
	if (N > 1)
	{
		for (i = 2; i <= N; i++)
		{
			k = 0;
			for (j = 1; j <= i; j++)
			{
				if(i%j==0) k++;
			}
			if (k == 2){
				a[p] = i; p++;
			}
		}
		a1 = (int *)malloc(p * sizeof(int));
		i = 0;
		while (i != p)
		{
			a1[i] = a[i];
			i++;

		}
		
		return a1;
		
	}
	else
	return NULL;
}