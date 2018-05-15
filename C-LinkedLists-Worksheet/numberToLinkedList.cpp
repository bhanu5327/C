/*
OVERVIEW:  Given a number convert that to single linked list (each digit as a node).
E.g.: Input: 234, Output: 2->3->4.

INPUTS:  A number.

OUTPUT: Create linked list from given number, each digit as a node.

ERROR CASES:

NOTES: For negative numbers ignore negative sign.
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
}*head;

struct node * numberToLinkedList(int N) {
	int i,k,l=1;
	k = N;
	if (N < 0)
	{
		N = -N;
	}
	head = NULL;
		do
		{
			struct node *n = (struct node*)malloc(sizeof(struct node)); 
			
			i = N % 10;
			if (head == NULL)
			{
				n->num = i; n->next = NULL; head = n;
			}
			else
			{

				n->num = i;
				n->next = head;
				head = n;
			}
			N = N / 10;
		} while (N != 0);
		return head;
	
}