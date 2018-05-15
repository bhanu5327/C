/*

ProblemCODE : BINARYSTROP
Difficulty : Medium
Marks : 15

Given two binary numbers in form of strings and
a string representing "AND", "OR", "NOR" or "XOR". Return the output string which forms by doing the specified operation on those 2 strings .


Ex:	Input: "101", "111", op =  "OR"
Output: "111"


Ex:	Input: "10101", "1111", op =  "AND"
Output: "00101"

Ex:	Input: "0111", "1010", op =  "XOR"
Output: "0010"

Ex:	Input: "0011", "1010", op =  "NOR"
Output: "0100"

Note :
In the above representations ,Write those strings on a paper ,you will understand them better . [Align them to the Right]
If 1 string length is less than other ,you need to consider missing letters as 0's ie "1111" AND "1" is same as "1111" AND "0001".
Ie if a String is "" ,you should consider it as All 0's .This dosent not apply if String is NULL.

Reference : http://www.bristolwatch.com/pport/pics/logic_table.gif [For AND,OR,XOR]
For NOR : http://www.circuitstoday.com/wp-content/uploads/2010/04/2-Input-NOR-Gate-Truth-Table.jpg

Contraints :
String length < 50.
For 50% of TestCases ,only AND/OR operations will be given .

Difficulty : Medium

*/

#include <stdio.h>
#include <stdlib.h>


char *performOperation(char *str1, char *str2, char *operation){
	int i, j, k, m, n,p,h,g,x=0,y=0; char *a,*b,*c;
	if (str1 != NULL&&str2 != NULL)
	{
		for (i = 0;str1[i] != '\0'; i++)
		{ }
			for (j = 0; str2[j]!='\0'; j++)
			{ }
				if (i>j) k = i;
				else k = j;
				a = (char*)malloc(k*sizeof(char));
				b = (char*)malloc(k*sizeof(char));
				c = (char*)malloc((k+1)*sizeof(char));
				for (p = 0; p< k; p++)
				{
					a[p] = (char)48;
				}
				for (p = 0; p< k; p++)
				{
					b[p] = (char)48;
				}
				for (p =k-i,x=0 ; p<k;x++, p++)
				{
					a[p] = str1[x];
				}
				for (p =k - j,y=0; p<k; y++,p++)
				{
					b[p] = str2[y];
				}
		switch (operation[0])
		{
		case 'O':for (i = 0; i < k; i++)
		{
			h = a[i] - 48; g = b[i] - 48;
			c[i] = (char)((h|g) + 48);
			
		}
				 c[k] = '\0';
				 break;
		case 'A':for (i = 0; i < k; i++)
		{
			h = a[i] - 48; g = b[i] - 48;
			c[i] = (char)((h&g) + 48);
		
		}c[k] = '\0';
				 break;

		case 'X':
			for (i = 0; i < k; i++)
			{
				h = a[i] - 48; g = b[i] - 48;
				c[i] = (char)((h^g) + 48);
			} 
			c[k] = '\0';
			break;
			
		case 'N':
			for (i = 0; i < k; i++)
			{
				h = a[i] - 48; g = b[i] - 48;
				m = (h|g);
				if (m == 1) m = 0;
				else m = 1;
				c[i] = (char)( m+ 48);
			}
			c[k] = '\0';
			break;
		}
		return c;
	}
	return NULL;
}








