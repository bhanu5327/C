

















/*
Given a Sorted Array of integers .Create a new Balanced Binary Search Tree from the Array
and return the head of the new BST .

Ex : Input : [1,6,10]
Output : A new BST which structure is as follows 
  6
 / \
1  10

A BST is said to be balanced ,when it satisifes the following property 

Every node's Difference of Left subtree height and right-subtree height is not more than 1 .

Below Tree is Not a Balanced BST ,as 1's left subtree has height of 0 ,but 
right subtree height is 2 
(Diff >1)

  1
   \
    3
   / \
  10  5

Note : Return head of newly created BST
Note : Return Null for invalid Inputs
Note : Donot create a new BST .
*/
#include <stdlib.h>
struct node{
	struct node * left;
	int data;
	struct node *right;
};
struct node* balanced(struct node* root, struct node *temp, int * arr, int len, int low, int high)
{
	int i, j, k, mid;
	i = 1;
	struct node* n = (struct node *)malloc(sizeof(struct node));
	n->left = NULL;
	n->right = NULL;

	mid = (low + high) / 2;
	if (low<=high)
	{
		n->data = arr[mid];
		if (len == low + high + 1)
		{
			
			root = n;
			 temp = root;
			
		}
		else
		{
			root = temp;
			while (1)
			{
				if (n->data < temp->data)
				{
					if (temp->left == NULL)
					{
						temp->left = n;
						break;
					}
					else
						temp = temp->left;
				}
				if (n->data > temp->data)
				{
					if (temp->right== NULL)
					{
						temp->right = n;
						break;
					}
					else
						temp = temp->right;
				}
			}
			
			
		}
		temp=root;
		balanced(root, temp, arr, len, low, mid - 1);

		balanced(root, temp, arr, len, mid + 1,high);

	}
	return root;
}

struct node * convert_array_to_bst(int *arr, int len){
	
	int i = len;
	if (len < 0 || arr == NULL) return NULL; struct node**k;
	struct node*root = (struct node *)malloc(sizeof(struct node));

	struct node* temp = (struct node *)malloc(sizeof(struct node));
	root->left = NULL; root->right = NULL; temp->left = NULL; temp->right = NULL;
	root= balanced(root,temp, arr, len ,0 ,len-1);
	 return root;
}

