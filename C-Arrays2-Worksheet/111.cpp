#define _CRT_NO_SECURITY_WARNINGS
#include<malloc.h>
#include <stdio.h>
#include<conio.h>
int* getSquareLeaderArray(int *arr, int len, int *leadersArrayLen);
int main()
{
	int *a = (int *)malloc(1 * sizeof(int)); a[1] = 20254;
	int len = 1; int l = 0;
	getSquareLeaderArray(a, len, &l);
	printf("yes-%ld", l);
	SYSTEM("pause");
	return 0;
}

int* getSquareLeaderArray(int *arr, int len, int *leadersArrayLen){
	int i, j, k, n, x, v, sum = 0, p = 0, count = 0;
	int *z; int *b = (int*)malloc(len*sizeof(int));
	int *c = (int*)malloc(2000 * sizeof(int));
	for (i = 0; i < len; i++)
	{
		b[i] = 0; c[i] = 0;
	}
	if (arr != NULL && 0 < len < 10000)
	{
		for (i = 0; i < len; i++)
		{
			n = arr[i]; v = 0; c[0] = 0;
			while (sum!=1)
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
	
						for (x = 0; x <=v; x++)
						{
							if (c[x] == sum) break;
							else if (x == v)
							{
								c[x] = sum; v++;
							}
						}

				}
				if (c[x]==sum) break;
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
