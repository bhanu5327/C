
















/*

Problem Code: IdentifyKid

There are three types of Guys,
'A' - Ambitious Boy 
'B' - Brilliant Boy
'C' - Creative Boy

The first generation guy is 'A'
each guy will have 3 kids 'A','B','C' , but the order will be different

'A' children will be  A ,B, C
'B' children will be  B ,C, A
'C' children will be  C ,A, B    ( rotations of “ABC”)


So basically , if it was represented in the form of a tree


1st  Generation -	                                   A
Index -                                                1
                                 /                     |                   \
2nd Generation -	            A                      B                    C
Index -			                1                      2                    3
                           /    |    \            /    |    \           /   |   \
3rd Generation -          A     B     C          B     C     A         C    A    B
Index-                    1     2     3          4     5     6         7    8     9

Given the N,K which represents the Nth generation and Kth index
You need to identify the type of the kid present there.

Note : If there is No Guy present there, return '\0'

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void f(int N, int K, int i,int *j ,char *p,char s,int *w)
{
	if (*w == 1)
	{
		if (i == N&&*j == K)
		{
			*p = s; *w = 0;
		}
		else if (i == N)
		{

		}
		else
		{
			if (s == 'A')
			{
				if (i < N) i++;
			
				f(N, K, i, j, p, 'A', w);
				(*j)++;
				
				f(N, K, i, j, p, 'B', w);
				(*j)++;
			
				f(N, K, i, j, p, 'C', w);

			}
			if (s == 'B')
			{
				
				if (i < N) i++;
				f(N, K, i, j, p, 'B', w);
				(*j)++;
				
				f(N, K, i, j, p, 'C', w);
				(*j)++;
				
				f(N, K, i, j, p, 'A', w);

			}
			if (s == 'C')
			{
				
				if (i < N) i++;
				f(N, K, i, j, p, 'C', w);
				(*j)++;
				
				f(N, K, i, j, p, 'A', w);
				(*j)++;
				
				f(N, K, i, j, p, 'B', w);

			}
		}
	
	}
}
char identifyKid(int N, int K) {
	if (N <= 0 || K <= 0) return '\0';
	long int z = 1; int i;
	for ( i = 1; i <= N; i++)
	{
		z = z * 3;
		if (K <= z) break;

	}
	if (i==N+1) return '\0';
	char* a = (char*)malloc(9 * sizeof(char)); char k = '\0'; int w = 1,j=1;

/*	a[0] = 'A'; a[1] = 'B'; a[2] = 'C';
	a[3] = 'B'; a[4] = 'C'; a[5] = 'A';
	a[6] = 'C'; a[7] = 'A'; a[8] = 'B';
	int p = (K - 1) % 9;
	k = a[p];*/
	f(N, K, 1,&j,&k,'A',&w);
	return k;
}