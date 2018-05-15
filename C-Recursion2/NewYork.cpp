





















/*

Problem Code : New York

Count the number of ways of reaching top left cell (0,0) to right bottom cell (n-1,m-1) of a 2d matrix.

You have to change the direction "exactly 'k' times", you can change to any direction top,down,left,right.

You can start with any direction (initially at (0,0) only right and down are possible).

For Example :
N = 3, m = 4 , k = 1
These are the two sequences , change in direction is indicated by *

(1,1) -->  (2,1) -->  (3,1) -->  (3,2)* -->  (3,3) --> (3,4)
(1,1) -->  (1,2) -->  (1,3) -->  (1,4) --> (2,4)* -->  (3,4)

N = 3, m = 4, k = 2

(1,1) --> (2,1) --> (2,2)* --> (2,3) -->  (2,4) -->  (3,4)*
(1,1) --> (1,2) -->  (2,2)* --> (3,2) -->  (3,3)* --> (3,4)
(1,1) --> (1,2) -->  (1,3) -->  (2,3)* -->  (3,3) -->  (3,4)*

Return 0 for invalid cases
*/

#include <stdio.h>
#include <stdlib.h>

void newyork_recur(int n, int m, int x, int y, int K, int dir, int *count, int s, int t, int a, int b, int *d,int dir1,int dir2) {
	
	if (dir <= K)
	{
		
		
		if ((x >= 0 && y >= 0 && x <= n-1&&y <= m-1))
		{
			if (dir1 == dir2 || dir1 <= 0 || dir2 <= 0)
			{

			}
			else
			{
				dir++;
			}
			if (x == n-1&&y == m-1&&K == dir)
			{
				(*count)++;
			}
			else if (x == n - 1 && y == m - 1)
			{
				int g = 0;
				g++;
			}
			else
			{
				if (*d != 0)
				{
					s = a; t = b;
				}
				a = x; b = y; *d = 1;
				dir1 = dir2;

				

				newyork_recur(n, m, x, y + 1, K, dir, count, s, t, a, b, d, dir1, 2);

				newyork_recur(n, m, x + 1, y, K, dir, count, s, t, a, b, d, dir1, 3);

				newyork_recur(n, m, x, y - 1, K, dir, count, s, t, a, b, d, dir1, 4);
				newyork_recur(n, m, x - 1, y, K, dir, count, s, t, a, b, d, dir1, 1);

			}
		}
	}
	
}

int NewYork(int n, int m, int k){
	int count = 0,d=0;
	newyork_recur(n, m, 0, 0, k , 0, &count,-1,-1,0,0,&d,-1,-1);
	return count;
}