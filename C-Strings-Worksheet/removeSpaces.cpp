/*
OVERVIEW: Given a string, remove all spaces in it.
E.g.: Input: "abd scd". Output: "abdscd"

INPUTS: A string.

OUTPUT: Return string after removing spaces.

ERROR CASES: Return '\0' for invalid inputs.

NOTES: Don't create new string.
*/
#include<string.h>
char removeSpaces(char *str) {
	int i = 0,l;
	if (str != '\0')
	{
		while (str[i] != '\0')
		{
			if (str[i] == ' ')
			{
				l = i;
				while (str[l] != '\0')
				{
					str[l] = str[l + 1]; l++;
				}
			}
			else
				i++;
		}
		return *str;
	}
	else
		return NULL;
}