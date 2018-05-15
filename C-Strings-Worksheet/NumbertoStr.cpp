/*
OVERVIEW: Given a float number ,Convert it into a string 

INPUTS: A Float,Final string ,How many digits after decimal has to be displayed .
Its zero for integers.


OUTPUT: No need to output anything ,Modify the str in function parameter such that it
now holds the string format of the float number specified

Example : number_to_str(345,str,0);
Should copy "345\0" in the str;
number_to_str(345.342,str,2);
Should copy "345.34" in the str;

NOTES: Don't create new string.

*/

#include <stdio.h>
#include<iostream>
#include<stdlib.h>
void number_to_str(float number, char *str,int afterdecimal){
	int x, i=0, t,l=0; float y; double k = (double)afterdecimal;
	x = (int)number;
	y = number - x;
	if (y < 0) y = -y;
	itoa(x, str, 10);
	while (str[i++] != '\0')
		l++;
	str[i-1] = '.';
	for (i = 0; i < afterdecimal; i++)
	{
		y = y * 10;
		t = y;
		y = y - t;
		l++;
		str[l] = t + '0';
	}
	l++;
	str[l] = '\0';
		
	
	
}
