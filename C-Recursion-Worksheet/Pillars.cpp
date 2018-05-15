





















/*
Some where in MissionRnD world ,there is a large plot of empty Rectangular land ,divided into Blocks of
equal size . A Land of N Blocks at length and M Blocks at Breadth will have total of N x M Blocks .

Each Block has a pillar of Height H .[0 <= H <=100000] .A Pillar is said to be a Leader if there are no more
neighbouring pillars (East ,West ,Noth and South) whose height is greater than current one .
And excatly opposite ,A pillar is said to be a Looser if there are no more neighbouring pillars
whose height is less than the current pillar height

If a block has 0 specified ,It has No pillar and No person can be on that block.In the below example
1,2,4... are heights of pillars at that block.Do not consider 0 while calculating Leaders or Loosers .
Example :

1 2 0 1 0
0 0 0 9 0
0 0 0 8 0
0 1 4 6 5
0 0 2 3 4

Here a[0][1] ie 2 ,and a[1][3] ie 9 are leaders ,as all their neighbouring elements are less or equal than it .
Here a[0][0] ie 1 ,and a[0][3] ie 1 and a[3][1] ie 1 and a[4][2] ie 2 are Loose Pillars ,as all their
neighbouring pillars height are greater or equal than it .

Now there is a child who likes to jump from one pillar to another ,He starts at a looser Pillar and jumps to
a nearby pillar (4 Directions) ,if the nearby pillar height is "strictly greater" than curernt pillar height .
So he can jump from 1 to 3 ,or 3 to 7 but not 4 to 1 and 5 to 5 .[all these are heights]
He continues jumping until he reaches a LeaderPillar .

As he likes jumping ,He would like to know the Path which starts at a Looser Pillar and ends at a Leader Pillar
that involves maximum jumps ,Can you help the child solve his Task ?

In the above example :
1-2 Path , requires only 1 jump
1-4-6-8-9 requires 4 jumps
2-3-4-5-6-8-9 requires 6 jumps
1-9 requires only 1 jump.
So in the above example you need to return [2,3,4,5,6,8,9] and copy 6 in jumps_count

Input :
A 2D Array (passed as Single pointer,First element Address) ,N (number of Cols), M(number of rows),
jumps_count (Pointer to an Integer)
Output :
Return the Max Jumps path  ,and copy number of max jumps into jumps_count .

Constraints :
0<=N<=10000
0<=M<=10000
Note : If there is no such path ,Copy 0 in jumps_count and return NULL,(Same for Invalid Inputs too)
Examples :
-----
2 1 7
3 0 4   ->Max Path : [1,2,3,5,6] ,jumps_count =4 [Here both 4's are looser elements]
5 6 4
--------
5 8 9 10
4 3 1 0
3 0 0 3   ->Max Path is [1,2,3,4,5,8,9,10] , jumps_count =8
2 1 1 1
---------
0 0 0
0 4 0  ->Max Path is [4] ,jumps_count=0;
0 0 0
Note : There will be only One Maximum Jumps path .[If there are multiple ,Return any 1 path]
*/
#include <stdlib.h>
#include <stdio.h>
int response(int **a, int rows, int cols, int i, int j)
{
	int p1 = 0, p2 = 0;	if (i < 0 || j < 0 || i >= rows || j >= cols)  return 0;
	if (i < rows - 1 && j>0 && j<cols - 1)
	{
		if (a[i][j] == a[i][j + 1] && a[i][j] < a[i][j - 1] && a[i][j] == a[i + 1][j])
		{
			return 1;
		}
	}
	//if (a[i - 1][j] == 0 && a[i + 1][j] == 0 && a[i][j+1] == 0 && a[i][j-1] == 0) return 0;
	if (i - 1 >= 0)
	{
		if (a[i - 1][j] == 0){ p1++; p2++; }
		else if (a[i - 1][j] > a[i][j] ) p1++;
		else p2++;
	}
	else
	{
		p1++; p2++;
	}
	if (j - 1 >= 0)
	{
		if (a[i][j - 1] == 0){ p1++; p2++; }
		else if (a[i][j - 1] > a[i][j]) p1++;
		else p2++;
	}
	else
	{
		p1++; p2++;
	}
	if (i + 1 < rows)
	{
		if (a[i + 1][j] == 0) {
			p1++; p2++;
		}
	else if(a[i + 1][j] > a[i][j] ) p1++;
		else p2++;
	}
	else
	{
		p1++; p2++;
	}
	if (j + 1 < cols)
	{
		if (a[i][j + 1] == 0){ p1++; p2++; }
	else if (a[i][j + 1] > a[i][j] ) p1++;
		else p2++;
	}
	else
	{
		p1++; p2++;
	}
	if (p2 == 4) return 2;
	else if (p1 == 4) return 1;
	else return 3;

}
int pillar1(int **a,int rows,int cols, int* count1,int* count2, int i, int j,int* l1,int l,int*p,int q)
{
	int k, t,e,f; int *count;
	//if (i == &&j == ) return 1;
	
	k=response(a, rows,cols,i, j);
	if (k == 0) return 0;
	if (i == 4 && j == 4)
	{
		i = 4;
	}
	
		if ((k == 3&&a[i][j]>q)||(k==1&& q==0))
		{
			
			q = a[i][j];
			count2[l++] = q;
			
			t = pillar1(a, rows, cols, count1, count2, i - 1, j, l1, l, p, q);
			//if (t == 1) { goto l1; };
			q = a[i][j];
			t = pillar1(a, rows, cols, count1, count2, i, j - 1, l1, l, p, q);
			//if (t == 1) { goto l1; };
			q = a[i][j];
			t = pillar1(a, rows, cols, count1, count2, i, j + 1, l1, l, p, q);
			//if (t == 1) { goto l1; };
			q = a[i][j];
			t = pillar1(a, rows, cols, count1, count2, i + 1, j, l1, l, p, q);
			//if (t == 1) { goto l1; };
		}
		else if (k == 2)
		{
			count2[l++] = a[i][j];
			if (*l1 < l)
			{
				for (int w = 0; w < l; w++)
				{
					count1[w] = count2[w];
				}
				*l1 = l;
				
			}

			
			//*l = 0; *p = 0;
			
		}
		
		return 0;
	

}
int * pillars_max_jumps(int *blocks, int n, int m, int *jumps_count){
	if (blocks == NULL || n <= 0 || m <= 0)
	{
		*jumps_count = 0;
		return NULL;
	}
	int i, j,u,b=0, k = 0,x=0,y=0,e=0,f=0; int * count,*p,q;
	
	int * count1 = (int*)calloc((m*n),sizeof(int)); int * count2 = (int*)calloc((m*n),sizeof(int));
	int ** a = (int**)malloc(n*sizeof(int*)); int *l1,l2=0; int t;
	for (i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(m*sizeof(int));
	}
	for ( i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] =blocks[k++];
		}
	}
	k = 0; p = &x;  l1 = &e; 
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			if (a[i][j] != 0)
			{
				k = response(a, n, m, i, j);
				if (k == 1)
				{
				
					q = 0;
					t = pillar1(a, n, m, count1, count2, i, j, l1, l2, p, q);
				}
				
			}
		}
	}
	
	if (*l1 == 0)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < m; j++)
			{
				if (a[i][j] != 0)
				{
					k = response(a, m, n, i, j);
					if (k == 2)
					{
						count1[0] = a[i][j];
						*jumps_count = 0;
						return count1;
					}
					
				
			     }
				else
				{
					return NULL;
				}
			}
		}
		
			*jumps_count = 0;
			return NULL;
		
	}
	count = (int*)malloc((*l1)*sizeof(int));
	*jumps_count = *l1 - 1;
	 for(i = 0; i < *l1; i++)
	 {
		 count[i] = count1[i];
	 }
	 return count;
}