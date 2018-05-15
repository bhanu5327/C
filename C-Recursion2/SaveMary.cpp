

















/*

	Raju bhai is a new don in town. He enjoys hanging people every weekend.
	This weekend he assembled N people in a circular manner (1,2,..N,1) and choosen a random integer K. 
	He framed certain rules to hang people.
	
	Rule 1: He skips K-1 persons (inclusive) and hang Kth person.
	Rule 2: He always starts counting from 1st person.
	Rule 3: The last person will be allowed to live for rest of his life.
	
	Sample Case:
		Given N=5, K=2
			Initial state: 1,2,3,4,5
		Step 1: skips 1 and hangs 2
			1,3,4,5
		Step 2: Now skips 3 and hangs 4
			1,3,5
		Step 3: Now skips 5 and hangs 1
			3,5
		Step 4: Now skips 3 and hangs 5
			3
		As 3 is only person, he lets him live.

	Save our friend Mary by choosing correct position in the initial circle.
	You have to return the integer x, such that if mary is positioned at x in [1..N] she
	will not be killed, if no such position exists, return -1
	Fill the below function with code and return the postion.
	Return -1 for error cases
*/
#include<stdio.h>
#include<stdlib.h>
void safeposition(int n, int k, int i,int *a,int count,int l)
{
	int h = 0;
	l = 0;
	for (int p = 0; p < n; p++)
	{
		if (a[p] == 0) l++;
	}
	if (l == 0 || l == 1) goto z;
	
	while (1)
	{
		if (a[i] == 0)
		{

			count++;
		}
		

		if (count == k)
		{
			a[i] = 1; h = 1;
			count = 0;
		}
		i++;
		if (i >= n)
		{
			i = 0;
		}
		if (h == 1) break;
	}
		safeposition(n, k, i, a, count, 0);
	z:;
}
int saveMary(int n, int k){
	int *a = (int*)calloc(n, sizeof(int)); int l=-1,p;
	if (n < 0) return -1;
	safeposition(n, k, 0,a,0,0);
	for (p = 0; p < n; p++)
	{
		if (a[p] == 0) l=p+1;
	}
	return l;
}
