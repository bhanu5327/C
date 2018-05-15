/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for 
  octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for 
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/

#include<stdlib.h>
#include<math.h>
int octalToHexadecimal(long int num)
{
	long int n = num, z = 0, s = 0; int i, c, j, o=0,l = 0; int	k = 0, t, x, y, p; int a[100];
	
	
	if (num>0)
	{
		while (n != 0)
		{
			c = 1;
			i = n % 10;
			for (j = l; j > 0; j--)
			{
				c = c * 8;
			}
			i = i*c;
			s = s + i;
			n = n / 10;
			l++;
		}

		while (s != 0)
		{
			t = s % 16;
			s = s / 16;
			if (t >= 10 && t <= 15)
				o++;
			a[k] = t ; k++;
		}
	x = 0; y = k - 1; p = 0;
			while (y != -1)
			{
			t = a[y];
			p++;
			for (x = k+o; x > p; x--)
			t = t * 10;
			z = z + t;
			if(10<=a[y]&&a[y]<=15)
			p++;
			y--;
			}
		return z;
	}
	else 
		return 0;
}



float octalToHexadecimalFraction(float num)
{
	return 0.0;
}