/*
ProblemCode : STRMATCH
Marks : 10
Difficulty :Easy.

A String(which only has small case a-z letters) is said to be corrupted if some of the charecters are removed and replaced by the number of characters removed .
Like : apple can be converted into a3e (ppl removed), or a4 (pple removed),ap2e (pl removed) .

helloworld can be modified as hello5 , h9 , 9d , etc , There is no limit on the number of characters that can be removed , or number of different times they can be
removed .

Some more examples are ,abcdefghijkl can be modified as a2d2g4l , a10l .
If 2 or more numbers occured consecutively , you should consider them as a whole , like a23re , is not a "2Chars removed" "3Chars Removed" re ,
it is a "23 Chars removed" re .

Your Task is , Given two corrupted Strings , you need to find whether a common word can be formed from those both corrupted strings
, If Yes ,return 1 , If no word can formed return 0 , -1 For invalid inputs .

Ex Input : s1= "a3e" and s2="4e" , Example Output : 1 .

This is because , apple word can be formed from both .

Ex Input 2 : s1= "k2e2f" and s2="k1fr3" , Returns 0 . No common word can be formed from those both Strings .
Ex Input 3: "5e3" and "abcdeej2" returns 1 , where as if s1 is 5e3i and s2 is abcdeekoll returns 0

Constraints :
A String will only have letters from "a-z and 0-9" ;
0<=Len Of Str1,Str2 <=10000
Numbers occuring in the String can be anything from 1 till 999 .

You can implement the helper functions ,if you want ,Although its optional .Dont worry about space for this question .

Note : Only 25% of Cases ,will have numbers >9 in the Strings .
*/
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

int isSTRMatched(char *str1, char *str2){
	int i, j, k, l, m=0, n=0,p,s=1,r=1,q=0,c=0,d=0;
	if (str1!= NULL&&str2 != NULL)
	{
		if (str1 != ""&&str2 != "")
		{
			for (i = 0; i < str1[i] != '\0'; i++)
			{
				k = str1[i];
				if (k >= 48 && k <= 57)
				{
					p = 1;
					while (k >= 48 && k <= 57)
					{
						k = k - 48;
						if (p == 1)
						{
							s = k; p++;
						}
						else
						{
							s = s * 10 + k;
						}
						i++;
						k = str1[i];
					}
					m = m + s; i--;
				}
				else m++;
			}
			s = 1;
			for (i = 0; i < str2[i] != '\0'; i++)
			{
				l = str2[i];
				if (l >= 48 && l <= 57)
				{
					p = 1;
					while (l>= 48 && l<= 57)
					{
						l= l- 48;
						if (p == 1)
						{
							s = l; p++;
						}
						else
						{
							s = s * 10 + l;
						}
						i++;
						l = str2[i];
					}
					n = n + s; i--;
				}
				else n++;
			}
			if (m==n)
			{
				m = 0; n = 0;
				for (i = 0,j=0; str1[i] != '\0',str2[j]!='\0';)
				{
					k = str1[i];
					l = str2[j];
					if (k >= 48 && k <= 57)
					{
						p = 0;
						while (k >= 48 && k <= 57)
						{
							k= k - 48;
							if (p == 0)
							{
								s = k; p++;
							}
							else
							{
								s = s * 10 + k; p++;
							}
							i++;
							k = str1[i];
						}
						m = m + s; i--;
					}
					else m++;
					if (l >= 48 && l <= 57)
					{
						q = 0;
						while (l >= 48 && l <= 57)
						{
							l = l - 48;
							if (q == 0)
							{
								r= l; q++;
							}
							else
							{
								r = r * 10 + l; q++;
							}
							j++;
							l = str2[j];
						}
						n = n + r; j--;
					}
					else n++;
					k = str1[i]; k = str2[j];
					if (m == n)
					{
						if (((65 <= k && k <= 90)|| (97 <= k && k <= 122)) &&( (65 <= l && l<= 90 )|| (97 <= l && l <= 122)))
						{
							if (k != l)
							{
								break;
							}
		
							
						}
						i++; j++;
					}
					else if (m < n)
					{
						i++; n = n - r; j = j - q + 1;
					}
					else
					{
						j++; m = m - s; i = i - p + 1;
					}
					
				}
				if (str1[i] == '\0'&&str2[j] == '\0') return 1;
				else return 0;
			}
			else return 0;

		}
		else
		{
			if (str1 == "" && str2 == "") return 1;
			else
			{
				return 0;
			}
		}
	}
	return -1;
}
