

















/*

1)Given a BST ,Find its Maximum Height 

Height of a NULL BST is 0

Height of a BST which has only one node is 1

Ex Input : 

    10 
    /\
   5 80
  /  /
 2  50
  \
   4

Height of above Tree is 4

Ex Output : Return the Height of the Tree , -1 if Invalid

2) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 11
get_sum_left for 80 returns 0
Return -1 for invalid inputs

3) Get Sum of Left subtree gets the sum of all nodes ,in the left subtree of the given node
Ex : get_sum_left for 10 in above Tree ,returns 130
get_sum_left for 80 returns 0
Return -1 for invalid inputs

*/
#include <stdlib.h>
#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};

void height1(struct node *root, int *h,int k)
{
	k++;
	if (root->left != NULL)
	{
		
		height1(root->left,h,k);
	}
	if (root->right != NULL)
	{
		height1(root->right,h,k);
	}
	if (k > *h) *h = k;
}
int get_height(struct node *root)
{
	
	int *h;
	int k=0,l=0;

	if (root != NULL)
	{
		
		height1(root, &l,k);
		return l;
	}
	else
	{
		return 0;
	}
	
}

void sum(struct node* root, int *s)
{
	if (root->left != NULL)
	{
		*s = *s + root->left->data;
		sum(root->left,s);
	}
	if (root->right != NULL)
	{
		*s = *s + root->right->data;
		sum(root->right, s);
	}
}
int get_left_subtree_sum(struct node *root){
	
	int s = 0;
	if (root != NULL)
	{
		if (root->left != NULL)
		{
			s = s + root->left->data;
			sum(root->left, &s);
		}
		return s;
	}
	return 0;
}


int get_right_subtree_sum(struct node *root){
	int s = 0;
	if (root != NULL)
	{
		if (root->right != NULL)
		{
			s = s + root->right->data;

			sum(root->right, &s);
		}
		
		return s;
	}
	return 0;
}

