/*

Here you will be doing the same ArraysQuestion you did before, but now in multiple ways.

OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7]
INPUTS: An Integer N
OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)
ERROR CASES: Return NULL for invalid inputs
Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}

Observations: (Write down what you observed here):

Way 1 :

Way 2 :

Way 3:

Conclusion :
*/

#include <stdio.h>
#include <math.h>
#include<stdlib.h>


/*

Manually loop over every element, Find if its prime or not. Store it in an array.
Write the worst complexity code you can write :D.
*/
int* nPrimeBruteForce(int N)
{
	int i, j, k, l = 0; int *a = (int*)malloc(N*sizeof(int)); int *b;
	for (i = 2; i <= N; i++)
	{
		k = 0;
		for (j = 2; j <= i; j++)
		{
			if (i%j == 0)
				k++;
		}
		if (k == 1)
		{
			
			a[l] = i; l++;
		
		}
	}
	b= (int*)malloc(l*sizeof(int));
	for (i = 0; i < l; i++)
		b[i] = a[i];
	if (l>0)
	return a;
	else return NULL;
}


/*
Remove even numbers, Run it again.
Just remove even numbers. So it should essentially take half of time for function 1, Did it really happened?

*/
int* nPrimeEvenRemoved(int N)
{
	int i, j, k, l = 0; int *a = (int*)malloc(N*sizeof(int)); int *b;
	for (i = 1; i <= N; i=i+2)
	{
		if (i == 3)
			a[l++] = 2;
		k = 0;
		if (i % 2 != 0)
		{
			for (j = 3; j <= i; j+=2)
			{
				if (i%j == 0)
					k++;
			}
		}
		if (k == 1)
		{

			a[l] = i; l++;

		}
	}
	b = (int*)malloc(l*sizeof(int));
	for (i = 0; i < l; i++)
		b[i] = a[i];
	if (l > 0)
		return b;
	else
		return NULL;
}

/*
Do all optimizations you can think of.

Hint : 
A number can be considered a prime, if its not divisible by any of the primes which are less than it.
ie 100 can be considered as a prime, if no prime number which is less than 100 divides 100 (With remainder as 0).
7 is prime as no prime less than it (2,3,5) can divide it. Think proof for this too.

This heavily reduces the number of divisions you do. If you did correctly you should see some heavy difference in timings.

*/
int* nPrimeOptimized(int N)
{
	int i, j = 0,k=0; int *a = (int*)malloc((N+1)* sizeof(int)); int *b = (int*)malloc(N/2 * sizeof(int));
	for (i = 2; i <= N; i++)
	{
		a[i] = 0;
	}
	for (i =2; i <=N; i++)
	{
		if (a[i] == 0)
		{
			for (j = 2 * i; j <=N;)
			{
				a[j] = -1;
				j = j + i;
			}
		}
	}
	for (i = 2; i <=N; i++)
	{
		if (a[i] == 0)
		{
			b[k] = i;
			k++;
		}
	}
	if (k > 0)
		return b;
	else
		return NULL;
}