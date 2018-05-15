/*
OVERVIEW: Given an unsorted single linked list, sort the linked list without using extra array or linked list.
E.g.: 4->2->1->5->3, output is 1->2->3->4->5.

INPUTS: An unsorted single linked list.

OUTPUT: Sort the linked list.

ERROR CASES: Return NULL for error cases.

NOTES: Without using extra array or linked list.

*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
}*temp1, *n1;

struct node * sortLinkedList(struct node *head) {
	int i = 0,g; temp1 = head;
	if (head == NULL) return NULL;
	while (temp1->next != NULL)
	{
		n1 = temp1->next; 
		while (n1 != NULL)
		{

			if (temp1->num>n1->num)
			{
				g = temp1->num;
				temp1->num = n1->num;
				n1->num = g;
				
			}
			
			n1 = n1->next;
		}
	
		temp1 = temp1->next;


	}

	return head;
}