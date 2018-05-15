/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
	EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
	EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci() 
		 nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/

int nthFibonacci(int n)
{
	int fib1, fib2, fib,a=2;
	fib1 = 0; fib2 = 1;
	if (n <= 0)
		return -1;
	else if (n == 1)
		return fib1;
	else if (n == 2)
		return fib2;
	else{
		do
		{
			a++;
			fib = fib1 + fib2;
			fib1 = fib2;
			fib2 = fib;
		} while (a != n);
		return fib;
	}
}

int nthPrime(int num)
{
	int i = 2, j, k, l = 0;
	if (num <= 0)
		return -1;
	else

	{
		while (1)
		{
			k = 0;
			for (j = 1; j <= i; j++)
				if (i%j == 0)
					k++;
			if (k == 2)
				l++;
			if (l == num)
				break;
			i++;
		}
		return i;
	}
}