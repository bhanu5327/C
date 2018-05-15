/*
OVERVIEW: Given a single linked list, remove every Kth node in the linked list.
E.g.: 1->2->3->4->5 and K 2, output is 1->3->5.

INPUTS: A linked list and Value of K.

OUTPUT: Remove every Kth node in the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <stdlib.h>

struct node {
	int num;
	struct node *next;
}*tempt,*previous;

struct node * removeEveryKthNode(struct node *head, int K) {
	int i = 1, j, k;
	tempt = head;
	if (K >1)
	{
		while (tempt != NULL)
		{
			if (i%K == 0)
			{
				if (i == 1)
				{
					head = tempt->next;
				}
				else
				{
					previous->next = tempt->next;
				}
			}
			previous = tempt; i++;
			tempt = tempt->next;
		}
		return head;
	}
	return NULL;
	}
	