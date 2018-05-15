/*
OVERVIEW: Given a string, Count the number of consonants and vowels and copy them to 'consonants' and 'vowels' respectively
Notes : Neglect Space and Other Symbols .Consider Capital Letters too

E.g.: Input: "aB c" , Output: consonants should contain 2 and vowels 1

INPUTS: A string and two int pointers

OUTPUT: Modify the consonants and vowels pointers accordingly with their counts (*consonants=?? ;*vowels=??)

INPUT2: Dont Forget they are pointers ;consonants and vowels are addresses of two variables .

Output: consonants should be ??,vowels should be ??

??:Count them :)

NOTES: Don't create new string , Dont return anything ,you have been given two pointers ,copy values into those .
*/

#include <stddef.h>

void count_vowels_and_consonants(char *str, int *consonants, int *vowels){
	int i=0, len=0, k=0,p;
	if (str != NULL)
	{
		while (str[i] != '\0')
		{
			 p = str[i];
			 if ((65 <=p&&p<= 90) || (97 <=p&&p<= 122))
			 {
				 len++;
				 switch (str[i])
				 {
				 case 'a':k++; break;
				 case 'e':k++; break;
				 case 'i':k++; break;
				 case 'o':k++; break;
				 case 'u':k++; break;
				 case 'A':k++; break;
				 case 'E':k++; break;
				 case 'I':k++; break;
				 case 'O':k++; break;
				 case 'U':k++; break;
				 }
			 }
			i++;

		}
	}
	*consonants = len - k;
	*vowels = k;
}
