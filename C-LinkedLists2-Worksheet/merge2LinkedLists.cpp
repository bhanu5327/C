/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<stdlib.h>
struct node {
	int num;
	struct node *next;
};

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	if (head1 == NULL) return head2;
	if (head2 == NULL) return head1;
	struct node* temp1; struct node* head;
	struct node* temp2; struct node* n=(struct node*)malloc(sizeof(struct node*));
	struct node* nex1; struct node* nex2;
	n->num = 1;
	n->next = NULL;
	head = n;
	temp1 = head1; temp2 = head2;
	while (temp1 != NULL&&temp2 != NULL)
	{
		nex1 = temp1->next; nex2 = temp2->next;
		if (temp1->num < temp2->num)
		{
			n->next = temp1; n = n->next; temp1 = temp1->next;
		}
		else
		{
			n->next = temp2; n = n->next; temp2 = temp2->next;
		}
	}
	if (temp1 == NULL)
	{
		while (temp2 != NULL)
		{
			n->next = temp2; n = n->next; temp2 = temp2->next;
		}
	}
	else
	{
		while (temp1 != NULL)
		{
			n->next = temp1; n = n->next; temp1 = temp1->next;
		}
	}
	head = head->next;
	return head;
}
