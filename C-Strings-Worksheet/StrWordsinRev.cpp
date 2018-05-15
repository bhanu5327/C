/*
OVERVIEW: Given a string, reverse all the words not the string.

E.g.: Input: "i like coding". Output: "coding like i"

INPUTS: A string.

OUTPUT: Modify the string according to the logic.

NOTES: Don't create new string.
*/
#include <stdio.h>
#include <string.h>

void str_words_in_rev(char *input, int len){
	int i = 0, j,p,k,v; char temp;
	_strrev(input);
	p = 0;
	for (i = 0; i < len; i++)
	{
		k = 1;
		if (input[i] == ' '|| input[i+1]=='\0')
		{
			
			if (i != 0 && input[i - 1] != ' ')
			{
				
				v = i - 1;
				if (i == len - 1) v = len - 1;
				for (j = p; j <v; j++,v--)
				{
					temp = input[j]; input[j] = input[v]; input[v] = temp;
				}
			}
			p = i + 1;
		}
		

	}

	
}
