/*

Problem : Return the Count of how many times the word occurred in given string in two ways
Way1: Not using Recursion
Way2:Using Recursion [Optional]

Input : "Hello HelloAgain HelloAGAINAGAIN commonItsHelloagain","Hello"
Output : 4

Note: Dont modify original str or word,Just return count ,Spaces can also be part of words like "ab cd" in "ab cd ab cd" returns 2
*/

#include <stdlib.h>

int count_word_in_str_way_1(char *str, char *word){
	int i, j, k=0, p = 0,l=0,g;
	while (word[k] != '\0') k++;
	while (str[p] != '\0')
	{
		i = 0;
		if (str[p] == word[i])
		{
			p++; i++;
			g = p;
			while (word[i] != '\0')
			{
				if (str[p] == word[i])
				{
					p++; i++;
				}
				else break;
			}
			if (i==k)
			{
				l++;
			}
		
			p = g;
		}
		else p++;
	}
	return l;
}

int count_word_int_str_way_2_recursion(char *str, char *word){
	return 0;
}

