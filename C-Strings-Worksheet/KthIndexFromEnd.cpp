/*
OVERVIEW: Given a string, return the letter at Kth index from the end of the string.
E.g.: Input: "qwertyui", 3. Output: 't' (index starting from zero).

INPUTS: A string and value of K.

OUTPUT: Return the letter at Kth index from the end of the string (index starting from zero).

ERROR CASES: Return '\0' for invalid inputs.

NOTES:
*/
#include<stdio.h>
#include<string.h>
char KthIndexFromEnd(char *str, int K) {
	int l=0,i=0;
	if (str != '\0'&& K >= 0 && str != "")
	{
		l = strlen(str);
		if (K < l)
		{
			while (str[l - 1] != '\0')
			{
				if (i == K)
					break;
				i++; l--;
			}

			return str[l - 1];
		}
		else return NULL;
	}
	else return '\0';
}