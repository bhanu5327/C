




















/*

Given a Binary Search Tree ,with two misplaced Node .Find those nodes and fix them .

Do not create a new tree ,Modify the original tree
Ex : In the below tree 3 and 30 is misplaced .

  5
 / \
2   3
 \
  30
When fixed 30 will be right node of 5 , and 3 will be right node of 2 .

Ex :In the below tree 1 and 20 are misplaced

         9
        / \
       4   1
      /     \
    20      30
Nodes 1 and 20 need to be fixed here .

*/
#include <stdio.h>
#include <stdlib.h>


struct node{
	struct node * left;
	int data;
	struct node *right;
};

void inorder1(struct node* root, int *arr, int *p,int x,int y,int t)
{
	if (root != NULL)
	{
		inorder1(root->left, arr, p,x,y,t);

		if (t == 0)
		{
			arr[(*p)++] = root->data;
		}
		else
		{
			if (root->data == x) root->data = y;
			else if (root->data == y)root->data = x;
		}

		inorder1(root->right, arr, p,x,y,t);

	}
}
void fix_bst(struct node *root)
{
	int l = 0, i,j, k = 0, m = 0, x=0, y=0,t=0;
	int *arr = (int*)malloc(256 * sizeof(int));

	if (root != NULL)
	{
		inorder1(root, arr, &l,x,y,t);
		/*for (i = 0; i < l; i++)
		{
			if (i == 0 && arr[i] > arr[i + 1])
			{
				x = arr[i]; k++; m++;
			}
			else if (i == l - 1 && arr[i - 1] > arr[i])
			{
				y = arr[i]; m++;
			}
			if (i == 0){}
			else if (arr[i - 1]<arr[i] && arr[i] >arr[i + 1] && k == 0)
			{
				x = arr[i]; k++;
			}
			else if (arr[i - 1] > arr[i] && arr[i] < arr[i + 1])
			{
				if (m == 1)
				{
					y = arr[i]; m++;
				}
				m++;
			}
		}*/
		for (i = 0; i < l - 1; i++)
		{
			if (i == 0 && arr[i] > arr[i + 1])
			{
				x = arr[i]; break;
			}
			else if (arr[i - 1]<arr[i] && arr[i] >arr[i + 1] && k == 0)
			{
				x = arr[i]; break;
			}
		}
		for (j = i; j < l; j++)
		{
	 if (j == l - 1 && arr[j - 1] > arr[j])
	{
		y = arr[j]; m++;
	}
	 else if (arr[j - 1] > arr[j] && arr[j] < arr[j + 1])
	 {
		
			 y = arr[j]; 
		
	 }
		}
		t = 1;
		inorder1(root, arr, &l, x, y, t);

	}
}
