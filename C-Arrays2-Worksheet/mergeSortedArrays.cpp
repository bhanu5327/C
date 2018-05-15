/*
OVERVIEW: You are given 2 bank statements that are ordered by date - 
Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};



struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i=0,j=0,p=0, k, m, n, count = 0;
	struct transaction *c = (struct transaction*)malloc((ALen + BLen)*sizeof(struct transaction));
	if (A != NULL&&B!= NULL)
	{
		while (i < ALen&&j< BLen)
		{
			for (k = 6; k < 10; k++)
			{
				m = A[i].date[k]; n = B[j].date[k];
				if (m != n) break;
					if (k == 9) k = 2;
					else if (k == 4) k = -1;
					else if (k == 2) k = 9;
			}
			if (m < n)
			{
				c[p++] = A[i];
				i++;
			}
			else
			{
				c[p++] = B[j];
				j++;
			}
		}
		if (i == ALen)
		{
			while (j < BLen)
			{
				c[p++] = B[j++];
			}
		}
		else if (j== BLen)
		{
			while (i < ALen)
			{
				c[p++] = A[i++];
			}
		}
		return c;
		
	}
	
	return NULL;
}