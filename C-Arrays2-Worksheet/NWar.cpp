//#define _CRT_NO_SECURITY_WARNINGS
#include<malloc.h>
#include <stdio.h>
#include<conio.h>


int* getSquareLeaderArray(int *arr, int len, int *leadersArrayLen){
	int i, j, k, n, x, v, sum = 0, p = 0, count = 0, k1;
	int *z; int *b = (int*)malloc(len*sizeof(int));
	int *c = (int*)malloc(2000 * sizeof(int));
	for (i = 0; i < len; i++)
	{
		b[i] = 0;
	}
	if (arr != NULL && 0 < len < 10000)
	{
		for (i = 0; i < len; i++)
		{
			
			n = arr[i]; v = 0; sum = 0;
			while (1)
			{
				sum = 0;
				while (n != 0)
				{
					k = n % 10;
					sum = sum + (k*k);
					n = n / 10;
				}
				if (sum == 1)
				{
					count++; break;
				}
				else
				{
					n = sum;
					k1 = 0;
					for (x = 0; x < v; x++)
					{
						
						/* if (x == v)
						{
							c[x] = sum;
						}
						 else if (c[x] == sum) break;*/
						if (c[x] == sum)
						{
							k1 = 1;
							break;
						}
					}
					if (k1 == 0)
					{
						c[v] = sum;
						v++;
					}

				}
				if (k1 == 1)
				{
					break;
				}
				
			}
			if (sum == 1) b[i] = 1;
		}
		z = (int*)malloc(count*sizeof(int));
		for (i = 0; i < len; i++)
		{
			if (b[i] == 1)
				z[p++] = arr[i];
		}
		*leadersArrayLen = count;
		return z;
	}
	return NULL;
}
