/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

//Use this function , Dont create any new function with name createNode or createList
struct node * createNodeDummy(int num) {
	struct node *newNode = (struct node *)malloc(sizeof(struct node));
	newNode->num = num;
	newNode->next = NULL;
	return newNode;
}

struct node * insertAtEveryKthNode(struct node *head, int K) {
	int n = 1;
	struct node* latest;
	struct node* temp;
	struct node* nex;
	if (head == NULL||K<=0) return NULL;
	temp = head;
	
	while (temp != NULL)
	{
		nex = temp->next;
		if (n%K == 0)
		{
			 latest= createNodeDummy(K);
			 temp->next = latest;
			 latest->next = nex;

		}
		
			temp = nex;
			 n++;
		
	}
	return head;
}
