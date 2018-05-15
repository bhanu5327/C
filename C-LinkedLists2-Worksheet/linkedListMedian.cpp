/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	struct node* temp;
	int n = 0,k=0,sum=0;
	temp = head;
	if (head == NULL) return -1;
	while (temp != NULL)
	{
		n++; temp = temp->next;
	}
	temp = head;
	k = 1;
	while (k != n / 2 && n!=1)
	{
		temp = temp->next; k++;
	}
	if (n == 1)
	{
		sum = temp->num;
		return sum;
	}

	if (n % 2 == 1)
	{
		sum = temp->next->num;
		
	}
	else
	{
		sum = temp->num;
		sum = sum + temp->next->num;
		sum = sum / 2;
	}
	return sum;
}
