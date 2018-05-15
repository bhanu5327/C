/*
OVERVIEW: You are given a bank statement where transactions are ordered by date. Write a function that finds the number of transactions in that statement after a given date.
-- find the count of numbers greater than a given number in a sorted array.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
date = "19-10-2004"
Output: 1 (as there is only one transaction { 30, "03-03-2005", "Third" })

INPUTS: One bank statement (array of transactions) and date.

OUTPUT: Return the number of transactions in that statement after a given date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include<stdio.h>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

int countGreaterNumbers(struct transaction *Arr, int len, char *date) {
	int i, k,m,n,count=0;
	if (Arr != NULL&&date != NULL)
	{
		for (i = 0; i < len; i++)
		{
			for (k = 6; k < 10; k++)
			{
				m = Arr[i].date[k]; n = date[k];
				if (m != n) break;
				if (k == 9) k = 2;
				else if (k == 4) k = -1;
				else if (k == 2) k = 9;
			}
			if (m>n) break;
				
			}
		if (i<len)
			return len-i;
		else return 0;
	}
	else
	return -1;
}
