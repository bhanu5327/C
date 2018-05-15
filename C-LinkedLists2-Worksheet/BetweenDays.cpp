/*
Q4: Two dates are given in a 8 node single linked list form,where each node
has one digit only, dates 01-31, months 01-12, year 0000-9999.

Find the number of days in between those two dates .[Exclusive]

Ex : Date1:  0->1->0->1->2->0->0->4 .
     Date2 : 0->5->0->1->2->0->0->4 should return 3 .
As there are 3 days between Jan1st 2004 and Jan 5th 2004.

Ex 2 : Date1 : 3->1->1->2->2->0->1->2.
       Date2 : 0->2->0->1->2->0->1->3 should return 1 .
(There is only one day between 31st Dec 2012 and 2nd  Jan 2013 .)

Note : Consecutive Days and Same Days should return 0;
->Return -1 for NULL Inputs .
->Between Days have to be calculated by not including start and end date .
->The SLL will have 8 Nodes in all cases . Year 999 will be represented as 0999.

Difficulty : Hard 
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

struct node{
	int data;
	struct node *next;
};

int between_days(struct node *date1head, struct node *date2head){
	struct node* temp1; struct node* temp2; int i=1,j,k,d1 = 0,p=1, m1 = 0, y1 = 0, d2 = 0, m2 = 0, y2 = 0,n1,n2,z1=0,z2=0;
	int a[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	temp1 = date1head; temp2 = date2head;
	if (date1head == NULL&&date2head == NULL) return -1;
	while (temp1 != NULL)
	{
		if (i <= 2)
		{
			d1 = d1 * 10 + temp1->data; d2 = d2 * 10 + temp2->data;
		}
		else if (i <= 4)
		{
			m1 = m1 * 10 + temp1->data; m2 = m2 * 10 + temp2->data;
		}
		else
		{
			y1 = y1 * 10 + temp1->data; y2 = y2 * 10 + temp2->data;
		}
		i++;
		temp1 = temp1->next;
		temp2 = temp2->next;
	}
	j = (y1-1) / 4 - (y1-1) / 100 + (y1-1) / 400;
	k = (y2-1) / 4 - (y2-1) / 100 + (y2-1) / 400;
	i = 1;
	while (m1 - 1 >= i)
	{
		z1 = z1 + a[i-1];i++;
	}
	
	i = 1;
	while (m2 - 1 >= i)
	{
		z2 = z2 + a[i-1]; i++;
	} 
	n1 = (y1 * 365) + z1 + d1 + j;
	n2 = (y2 * 365) + z2 + d2 + k;
	if ((y1) % 4 == 0&&y1%100!=0)
	{
		if (m1 > 2) n1++;
	}
	if ((y2) % 4 == 0&&y2%100!=0)
	{
		if (m2 > 2) n2++;
	}
	
	if (n1 == n2) return 0;
	
	if (n1 > n2)
		return n1 - n2-1;
	else
		return n2 - n1-1;
}