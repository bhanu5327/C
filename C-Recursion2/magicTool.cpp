













/*

	Given a matrix nxn and a starting point (p,q), 
	Output all the points in the matrix which are identical to the starting point in the fashion similar to magic tool in Adobe photoshop.
	Eg:
	(p,q) : (0,3)
	1 2 3 3
	3 2 3 3
	5 3 3 3
	4 5 1 4
	o/p : [ (0,2) (0,3) (1,2) (1,3) (2,2) (2,3) (2,1) ]

	Use 2 structures provided to solve the problem.
	
	struct point -> contains x, y corresponding to point on matrix.
	struct result -> contains 3 fields
						1. selected -> contains all the final points after the selecting process.
						2. size -> number of the selected points.
						3. visited -> utility variable to note the visited points on matrix during recursion.
	
	In error cases return a emply structures
		size = 0;
		selected = {};
		visited = {};

NOTE : Donot use any Global Variables
*/
#include <malloc.h>
#include<stdlib.h>
struct Point {
	int x;
	int y;
};


struct result {
	Point* selected;
	bool *visited;
	int size;
};


void select(char *pixels, int m, int n, struct Point pivot,int p,int q, result* res,int *i,int s,int t,int a,int b,char d) {
	// feel free to change this function parameters
	/*if (p >= 0 && p <= m &&q >= 0 && q <= n)
	{
		


		if ( d== *(pixels + (p*(n+1)) + q))
		{
			*(pixels + (p*(n+1)) + q) = '.';
			//if ((*i) != 0)
			//{
				//s = a; t = b;
			//}
			a = p;
			res->selected[(*i)++] = { p, q };

			res->visited[p*n + q] = true;
			res->size = *i;

			select(pixels, m, n, pivot, p - 1, q, res, i,s,t,a,d);
			select(pixels, m, n, pivot, p, q + 1, res,i,s,t,a,d);
			select(pixels, m, n, pivot, p + 1, q, res,i,s,t,a,d);
			select(pixels, m, n, pivot, p, q - 1, res, i,s,t,a,d);
		}
	}*/
	if ((p >= 0 && p <= m &&q >= 0 && q <= n)&&(s!=p||t!=q))
	{



	if ( d== *(pixels + (p*(n+1)) + q))
	{
	if ((*i) != 0)
	{
	s = a; t = b;
}
	a = p; b = q;
	res->selected[(*i)++] = { p, q };

	res->visited[p*n + q] = true;
	res->size = *i;

	select(pixels, m, n, pivot, p - 1, q, res, i,s,t,a,b,d);
	select(pixels, m, n, pivot, p, q + 1, res,i,s,t,a,b,d);
	select(pixels, m, n, pivot, p + 1, q, res,i,s,t,a,b,d);
	select(pixels, m, n, pivot, p, q - 1, res, i,s,t,a,b,d);
	}
	}
}

struct result select_wrapper(char* pixels, int m, int n, struct Point pivot) {
	result *res=(result*)malloc(sizeof(result));
	res->selected = (Point*)malloc((m+1)*(n+1)*sizeof(Point));
	res->visited = (bool*)malloc((m + 1)*(n + 1)*sizeof(bool));
	res->size = 0;
	int p = pivot.x; int q = pivot.y,i=0;
	if (pixels == NULL) return *res;
	char d = *(pixels + ((pivot.x)*(n+1)) + pivot.y);
	select(pixels, m, n, pivot, p , q, res, &i,-1,-1,0,0,d);
	return *res;
}


