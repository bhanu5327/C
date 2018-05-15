/*
Problem Code : ISPRIME

In this lesson you will write 3 ways of how to find a prime number and then note down its performances.

Question : Given a number return 1 if its a prime number ,0 otherwise.

Dont try to over optimize soultion unless asked. Write bad code its okay. The purpose of this lesson is to learn
how bad code effects the time taken for running.

Observations: (Write down what you observed here):

Way 1 :

Way 2 :

Way 3:

Conclusion : 
*/

#include <stdio.h>
#include <math.h>

/*
Divide the number with all elements from  1 to number and check whether its prime number or not. 
Dont do any optimizations. Just write the brute force code.
*/
int isPrimeBruteForce(int number){
	int i, k = 0; 
	for (i = 2; i < number; i++)
	{
		if (number%i == 0)
			k++;

	}
	if (k == 0)
		return 1;
	else
	return 0;
}

/*
Is checking division till number neccesary? 

You can do it just till half of number or even better just square root of n.

Divide the number with all elements from  1 to sqrt(number) and check whether its prime number or not.
Dont do any more optimizations.

Think why is it sufficient to do it till just square root of number.
*/
int isPrimeSquareRoot(int number){
	int i, k = 0;float d = number;
	for (i = 2; i <= sqrt(d); i++)
	{
		if (number%i == 0)
			k++;

	}
	if (k == 0)
		return 1;
	else
		return 0;
}

/*
Add more optimizations you like, 
Like if a number is odd number you need not divide it with even numbers. etc.
*/
int isPrimeOptimized(int number){
	int i, k =0; 
	double d = number;
    if (number == 2) 
		k = 1;
	else if(number % 2 == 1)
	{
		k = 1;
		for (i =3; i <= sqrt(d); i=i+2)
		{
			if (number%i == 0)
			{
				k++; break;
			}

		}
	}
	if (k == 1)
		return 1;
	else
		return 0;
}


