





















/*
Find if there is a connecting path between two given points in the maze.
The maze is a matrix of order MxN, check if there exists a path between (x1,y1) and (x2,y2).
Two points are said to connected if there is a series of 1's non-diagonally.
Example:
Maze of order 4x4:

1	0	1	0
1	1	0	0
0	1	0	1
0	1	1	1

(x1,y1):(0,0)
(x2,y2):(2,3)

In this case, there exists a connected path:
1
1	1
	1		1
	1	1	1

Since there is a connected path, your function has to return 1.
If a path doesn't exist between two co-ordinates then return 0.
If the co-ordinates are invalid or size of the matrix is invalid then return 0.

Function Prototype :path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2) ;
Maze: Pointer to first element of an array .
rows : No of rows
columns : Columns
x1,x2,y1,y2: Co-ordinates

Hint : You can use path_exists as a wrapper function for your original recursive function which might take
more parameters .
*/

#include<stdlib.h>


int path_exists(int *maze, int rows, int columns, int x1, int y1, int x2, int y2)
{
	/*int  k = 0, d, t, w, g, h; static int p = 0, i = -1, j = -1, r, s, z; static int**a;
	
		a = ( int **)malloc(rows*sizeof(int*));
		for (g = 0; g < rows; g++)
		{
			a[g] = (int*)malloc(columns*sizeof(int));
		}
		k = 0;
		for (g = 0; g < rows; g++)
		{
			for (h = 0; h < columns; h++)
			{
				a[g][h] = maze[k++];
			}
		}
	
	if (x1 >= rows || x2 >= rows || y1 >= columns || y2 >= columns || x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0) return 0;
	//if (*(maze +( x1*columns) + y1) == 0) return 0;
	/*w=*(maze + (0*columns) + 0);
	w = *(maze + (0 * columns) + 1);
	w = *(maze + (0 * columns) + 2);
	w = *(maze + (0 * columns) + 3);
	w = *(maze + (0 * columns) + 4);
	w = *(maze + (1 * columns) + 0);
	w = *(maze + (1 * columns) + 1);
	w = *(maze + (1 * columns) + 2);
	w = *(maze + (1 * columns) + 3);
	w = *(maze + (1 * columns) + 4);
	w = *(maze + (2 * columns) + 0);
	w = *(maze + (2 * columns) + 1);
	w = *(maze + (2 * columns) + 2);
	w = *(maze + (2 * columns) + 3);
	w = *(maze + (2 * columns) + 4);
	if (p == 0)
	{
		z = 0;
		w = a[x2][y2];
		if (w == 0) return 0;
	}
	
	p++;
	if (x1 == x2&&y1 == y2) return 1;
	
	if (a[x1][y1] == 1)
	{
		
		while (1)
		{
			r = i; s = j;
			if (i == x1 - 1 && j == y1) break;
			
			i = x1; j = y1;
			t=path_exists(maze, rows, columns, x1 - 1, y1, x2, y2);
			i = r; j = s;
			if (t == 1) z = 1;
			if (t == 0) break;
			
			if (z == 1) goto l;
		}
		while (1)
		{
			r = i; s = j;
			if (i == x1&&j == y1 - 1) break;
			i = x1; j = y1;
			t=path_exists(maze, rows, columns, x1, y1 - 1, x2, y2);
			i = r; j = s;
			if (t == 1) z = 1;
			if (t == 0) break;
			
			if (z == 1) goto l;
		}
		while (1)
		{
			r = i; s = j;
			if (i == x1&&j == y1 + 1) break;
			i = x1; j = y1;
			t=path_exists(maze, rows, columns, x1, y1 + 1, x2, y2);
			i = r; j = s;
			if (t == 1) z = 1;
			if (t == 0) break;
			
			if (z == 1) goto l;
		}
		while (1)
		{
			r = i; s = j;
			if (i == x1 + 1 && j == y1) break;
			i = x1; j = y1;
			t=path_exists(maze, rows, columns, x1 + 1, y1, x2, y2);
			i = r; j = s;
			if (t == 1) z = 1;
			if (t == 0) break;
			
			if (z == 1) goto l;
		}
		return 0;
	}
	else return 0;
	p=0;
		return 0;
	l:p = 0;
	return 1;*/
int  k = 0, d, t, w, g, h; static int p = 0, i = -1, j = -1, r, s, z; 



if (x1 >= rows || x2 >= rows || y1 >= columns || y2 >= columns || x1 < 0 || x2 < 0 || y1 < 0 || y2 < 0) return 0;
//if (*(maze +( x1*columns) + y1) == 0) return 0;
/*w=*(maze + (0*columns) + 0);
w = *(maze + (0 * columns) + 1);
w = *(maze + (0 * columns) + 2);
w = *(maze + (0 * columns) + 3);
w = *(maze + (0 * columns) + 4);
w = *(maze + (1 * columns) + 0);
w = *(maze + (1 * columns) + 1);
w = *(maze + (1 * columns) + 2);
w = *(maze + (1 * columns) + 3);
w = *(maze + (1 * columns) + 4);
w = *(maze + (2 * columns) + 0);
w = *(maze + (2 * columns) + 1);
w = *(maze + (2 * columns) + 2);
w = *(maze + (2 * columns) + 3);
w = *(maze + (2 * columns) + 4);*/
if (p == 0)
{
z = 0;
w =*(maze+(x2*columns)+y2);

if (w == 0) return 0;
}

p++;
if (x1 == x2&&y1 == y2) return 1;

if (*(maze+(x1*columns)+y1) == 1)
{

while (1)
{
r = i; s = j;
if (i == x1 - 1 && j == y1) break;

i = x1; j = y1;
t=path_exists(maze, rows, columns, x1 - 1, y1, x2, y2);
i = r; j = s;
if (t == 1) z = 1;
if (t == 0) break;

if (z == 1) goto l;
}
while (1)
{
r = i; s = j;
if (i == x1&&j == y1 - 1) break;
i = x1; j = y1;
t=path_exists(maze, rows, columns, x1, y1 - 1, x2, y2);
i = r; j = s;
if (t == 1) z = 1;
if (t == 0) break;

if (z == 1) goto l;
}
while (1)
{
r = i; s = j;
if (i == x1&&j == y1 + 1) break;
i = x1; j = y1;
t=path_exists(maze, rows, columns, x1, y1 + 1, x2, y2);
i = r; j = s;
if (t == 1) z = 1;
if (t == 0) break;

if (z == 1) goto l;
}
while (1)
{
r = i; s = j;
if (i == x1 + 1 && j == y1) break;
i = x1; j = y1;
t=path_exists(maze, rows, columns, x1 + 1, y1, x2, y2);
i = r; j = s;
if (t == 1) z = 1;
if (t == 0) break;

if (z == 1) goto l;
}
return 0;
}
else return 0;
p=0;
return 0;
l:p = 0;
return 1;




}
