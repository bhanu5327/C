

















/*
Given two Binary Search Trees ,Merge Both of them into a Single Binary Search Tree .
The Resultant Binary Search Tree will be BST1 .ie Merge all elements of BST2 into BST1.
	Example 1:

	Input :
	20        25
	/  \      /  \
	5    30   10   35
	Output :

	Bst 1 :
	20
	/   \
	5     30
	\   /  \
	10 25   35

BST 2 can be merged in BST1 sometimes in many number of ways ,
Any 1 of those correct ways would be fine .

Finally All elements of Both Trees should be in BST 1 .Dont process NULL Inputs
If an element of BST2 is already in BST 1, then BST2 node is ignored.

(Both r1 and r2 shouldnt be NULL at the time of Input)
Note : Dont Create Nodes using malloc,or Swap the data values or else your solution would receive 100%
cut in the marks you got for this question .
You need to solve this question only by changing links.
You will also receive Bonus marks for any better optimizations you make .
Difficulty : Medium -Hard

*/
#include <stdlib.h>
#include <stdio.h>

struct BstNode {
	int data;
	struct BstNode *left;
	struct BstNode *right;
}*temp;

void merge(struct BstNode **root1, struct BstNode *root2, struct BstNode *temp, struct BstNode *prev, struct BstNode *prev1,int j)
{
	int i;
	if (root2 != NULL)
	{
		merge(root1, root2->left, temp,prev,root2,0);
		merge(root1, root2->right, temp,prev,root2,1);
		temp = *root1;
		while (temp != NULL)
		{
			if (root2->data < temp->data)
			{
				prev = temp;
				temp = temp->left; i = 0;
			}
			else if (root2->data > temp->data)
			{
				prev = temp;
				temp = temp->right; i = 1;
			}
			else
			{
				i = 2;
				break;
			}
		}
		if (j == 0)
		{
			prev1->left = NULL;
		}
		else if (j == 1)
		{
			prev1->right = NULL;
		}
		if (i == 0)
		{
		
			prev->left = root2;

		}
		else if (i == 1)
		{
			prev->right = root2;

		}
	}
}
void merge_two_bst(struct BstNode **root1, struct BstNode *root2)
{
	
	if (*root1 == NULL)
	{
		*root1 = root2;
		
	}
	else
	{
		struct BstNode *temp=root2, *prev, *prev1; int i, j, k;
		merge(root1, root2, temp, *root1, root2, 0);
	}
	
}