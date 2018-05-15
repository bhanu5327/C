/*
OVERVIEW:  Given a single linked list (two digits as a node).Convert that to number


INPUTS:  SLL head pointer

OUTPUT: Create a number from the linked list given ,In each node there are two numbers ,digit1 and digit1 ,
So if the nodes are 12->34->56->78 , Final number would be 12345678 ( Integer)

ERROR CASES:

NOTES: Only Postive Numbers
*/

#include <stdio.h>
#include <malloc.h>

struct twoDigitNode {
	int digit1;
	int digit2;
	struct twoDigitNode *next;
}*temp;

int convert_sll_2digit_to_int(struct twoDigitNode *head){
	int i, j=100, k=0;
	temp = head;
	while (temp != NULL)
	{
		i = temp->digit1;
		i = 10 * i + temp->digit2;
		k = k*j + i;
		temp = temp->next;
	}
	
	
	return k;
}
