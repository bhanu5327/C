/*
OVERVIEW: 
1)Write a function which takes a decimal number as input and returns the octal number for decimalToOctal().
E.g.: decimalToOctal(10) returns 12.

2)Write a function which takes a fractional decimal number as input and returns the octal number for decimalToOctalFraction()
until precision two
E.g.: decimalToOctal(6.06) returns 6.03

INPUTS: Single decimal number num;

OUTPUT: Octal value of the Decimal Number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>

int decimalToOctal(int num)
{
	int	k = 0, t, x, y, z = 0, p; int a[100];
	if (num <=0)
		return 0;
	else
	{
		while (num != 0)
		{
			t = num % 8;
			num = num / 8;
			a[k] = t; k++;
		}
		x = 0; y = k - 1; p = 0;
		while (y != -1)
		{
			t = a[y];
			p++;
			for (x = k; x > p; x--)
				t = t * 10;
			z = z + t;
			y--;
		}
		return z;
	}
}

float decimalToOctalFraction(float numb)
{
	int num, y, z,l=0; float x,m=0;
	num =(int) numb;
	x = numb - num;
	z=decimalToOctal(num);
	do{
		l++;
		x = x * 8;
		y =(int) x;
		m = m*10 + y;
	} while (l != 2);
	m = m / 100;
	m = m + z;
	return m;
}

