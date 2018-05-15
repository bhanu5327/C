

















/*
Given a Binary Search Tree ,Copy All Elements in BST into a Array in horizontal row by row fashion where
each row is copied from Right to Left.

First copy the Frist row ,Next the second row etc .
Ex : If Bst is 
    6                        <-- Copy this first 
   / \
  4  10                      <-- Copy this row next from 10 and next 4 ..
 / \   \
1   5   15                   <-- Order her is 15 ,5 ,1 
          \
          17

Output will be a array consisting of [6,10,4,15,5,1,17];

Input : BST head node ;
Output :Return An array which has All the elements in row by row order (R->L) .

Note : Return -1 for Invalid Cases .
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void bstr2l(struct node *root, int *h, int k,int i,int *arr,int *p)
{
	k++;
		if (root->right != NULL)
		{
			bstr2l(root->right, h, k,i,arr,p);
		}
	if (root->left != NULL)
	{

		bstr2l(root->left, h, k,i,arr,p);
	}
	if (i != -1)

	{
		if (k == i)
		{
			arr[(*p)++] = root->data;
		}
	}
	else
	{
		if (k > *h) *h = k;
	}
}


int* BSTRighttoLeftRows(struct node* root)
{
	if (root == NULL) return NULL;
	int h = 0, l = 0, i, p = 0; int *arr=(int*)malloc(256*sizeof(int));
	i = -1;
	bstr2l(root,&h,0,i,arr,&p);
	for ( i = 1; i <= h; i++)
	{
		bstr2l(root, &h, 0, i,arr,&p);
	}
	return arr;
}
