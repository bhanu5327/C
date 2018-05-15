/*

Problem : Return the Last word in a string

Input : I will do this without using String Library
Output : Library

Note:Dont modify original string Neglect Spaces at the right end and at left end if required .
->Create a new string and return it , Use dynamic memory allocation .
*/
#include <stdlib.h>

char * get_last_word(char * str){
	int i = 0, j, k=0, len; char *a;

	if (str != NULL)
	{
		while (str[i++] != '\0')
		{

		}
		len = i;
		for (i = len - 1; i >= 0; i--)
		{
			if (str[i] == ' ')
				break;
		}
		a=(char*)malloc((len-i-1)*sizeof(char));
		for (j = i+1; j < len; j++)
		{
			a[k++] = str[j];
		}
		return a;
	}
	return NULL;
}
