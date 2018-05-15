/*
OVERVIEW: Given two strings, find the words that are common to both the strings.
E.g.: Input: "one two three", "two three five".  Output: "two", "three".

INPUTS: Two strings.

OUTPUT: common words in two given strings, return 2D array of strings.

ERROR CASES: Return NULL for invalid inputs.

NOTES: If there are no common words return NULL.
*/

#include <stdio.h>
#include<string.h>
#include <malloc.h>

#define SIZE 31

char ** commonWords(char *str1, char *str2) {
	char**a = (char**)malloc(SIZE*sizeof(char));
	char str3[100][100]; char str4[100][100]; int i, j, m = 0, n = 0,k=0,one,two,l;
	if (str1 == NULL || str2 == NULL)
		return NULL;
	else
	{
		for (i = 0; str1[i] != '\0'; i++)
		{
			if (str1[i] != ' ')
			{
				str3[m][n] = str1[i]; n++;
			}
			else
			{
				str3[m][n] = '\0';
				m++; n = 0;
			}
		}
		one = m;
		l = strlen(str1);
		if (m == l)
		{
			return NULL;
		}
		else
		{
			str3[m][n] = '\0';
			m = 0, n = 0;
			for (i = 0; str2[i] != '\0'; i++)
			{
				if (str2[i] != ' ')
				{
					str4[m][n] = str2[i]; n++;
				}
				else
				{
					str4[m][n] = '\0';
					m++; n = 0;

				}
			}
			str4[m][n] = '\0';
			two = m;
			l = strlen(str2);
			if (l == m)
				return NULL;
			else
			{
				for (i = 0; i <= one; i++)
				{
					for (j = 0; j <= two; j++)
					{
						if (strcmp(str3[i], str4[j]) == 0)
							a[k++] = str3[i];
					}
				}
				if (k != 0)
					return a;
				else
					return NULL;
			}
		}
	}
}
