

















/*

Given a Binary Search Tree ,Calculate its Inorder ,Postorder and PreOrder

Input : A BST
Output : Copy Inorder/Postorder/Preorder into the array specified .

Note : Memory for the Array is already allocated ,Dont allocate it again using malloc
->Take help of helper functions which are actually solving the problem .
->Dont Process Invalid Inputs

Bonus Task : 
->Go to the BSTTransversals Spec File ,We have left a custom test case for you ,Try to fill
it and understand how testing works .
*/

#include <stdio.h>

struct node{
	struct node * left;
	int data;
	struct node *right;
};
void insert(struct node* root, int * arr)
{
	int *p;
}
void inorder1(struct node* root, int *arr, int *p)
{
	if (root != NULL)
	{
		inorder1(root->left, arr,p);
		
		
			arr[(*p)++] = root->data;
			//arr = arr + 1;
		
		inorder1(root->right, arr,p);

	}
}

void inorder(struct node *root, int *arr)
{
	
	int l = 0;
	if (arr!=NULL)
	inorder1(root, arr, &l);

}void preorder1(struct node*root, int* arr, int *p)
{
	if (root != NULL)
	{

		arr[(*p)++] = root->data;
		preorder1(root->left, arr,p);
		preorder1(root->right, arr,p);
	}
}
void preorder(struct node *root, int *arr)
{
	int l = 0;
	if (arr!=NULL)
	preorder1(root, arr,&l);
	}
void postorder1(struct node* root, int *arr, int *p)
{
	if (root != NULL)
	{

		postorder1(root->left, arr,p);
		postorder1(root->right, arr,p);

		arr[(*p)++] = root->data;
		

	}
}
void postorder(struct node *root, int *arr)
{
	int l = 0;
	if (arr!=NULL)
	postorder1(root, arr, &l);
	
}

