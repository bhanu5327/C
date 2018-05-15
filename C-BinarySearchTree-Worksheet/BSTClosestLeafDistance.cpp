





















/*
Given a Binary Search Tree and a Node(temp).Find the Closest Distance from the Node to 
any leaf of the Tree.
(Least number of Edges needed to be travelled to go to the Node )

Ex : Consider the below tree .
      2
     / \
,   1   3
         \
         14
For 3 ,Output is 1 . As its closest leaf is 14 and 3 is at a distance of 1 to 14 .

Ex 2: Consider the below tree .
    2
   / \
  1   3
       \
        14
        / \
       9   20
      /      \
     6       25
For 3 ,Output is now 2 . As closest leaf to 3 is 1 and 3 is at a distance of 2 to 1 .
(through root 2 )

For 14 ,O/P : 2
For 2 , O/P : 1

Return -1 ,for Invalid Inputs
*/

#include <stdlib.h>
#include <stdio.h>

struct node{
  struct node * left;
  int data;
  struct node *right;
};
void leaf1(struct node *root, int *h, int k)
{
	
	if (root->left!=NULL||root->right!=NULL)
	{
		k++;
		if (root->left!=NULL)
		leaf1(root->left, h, k);
		if (root->right!=NULL)
		leaf1(root->right, h, k);
	}
	else if (root->left==NULL&&root->right==NULL)
	{
		if (k < *h || *h == 0) *h = k;
	}
}


int get_closest_leaf_distance(struct node *root, struct node *temp)
{
	if (root == NULL || temp == NULL) return -1;
	int i, j, k,h=0,s1=0,s2=0,p=0;
	struct node *temp1;
	leaf1(temp,&h,0);
	
	while (root != temp)
	{
		
		j = root->data;
		if (temp->data > j)
		{
			if (root->left != NULL)
			{
				s1 = 0;
				leaf1(root->left, &s1, 0);
				s1++;
				
			}
			temp1 = root;
			root = root->right;
		}
		else
		{
			if (root->right != NULL)
			{
				s1 = 0;
				leaf1(root->right, &s1, 0);
				s1++;
				
			}
			temp1 = root;
			root = root->left;
		}
		k = 0;
		while (temp1 != temp)
		{
			if (temp1->data < temp->data)
				temp1 = temp1->right;
			else
				temp1 = temp1->left;
			k++;
		}
		s2 = s1 + k;
		if (p == 0 || p > s2) p = s2;
	}
	if (p < h) return p;
	else return h;
	
}