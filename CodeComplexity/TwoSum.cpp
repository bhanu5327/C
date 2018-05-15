/*
Given an array of integers, return the two numbers such that they add up to a specific target.

You may assume that each input will have exactly one solution. Return NULL for invalid inputs

Given nums = [1, 20, 2, 4], target = 24,

Because nums[1] + nums[3] = 20 + 4 = 24,
return [4, 20]. (Always the first number should be less in final answer)

If target is 5 ,Return [1,4]
If target is 22 ,return [2,20]

Note :
Return_Array[0] should always be less than/equal to Return_Array[1]

Constraints :
len <100000
-100000< nums[i] <100000

Question Source Link : https://leetcode.com/problems/two-sum/
We Picked this standard problem from Online , as its a very famous one and you will get habituated on solving on
Leetcode .

You need to solve this question in 3 ways.And measure time for each way.

Observations: (Write down what you observed here):

Way 1 :

Way 2 :

Way 3:

Conclusion :
*/
#include <stdio.h>
#include <stdlib.h>
void merge(int *nums, int low, int high, int len);
void mg(int *nums, int low, int mid, int high);
int *b;

/*
Take each element, Sum with all other elements.
Repeat it with all elements.

What is the complexity of this method ? __________
*/
int* sumoftwoBF(int *nums, int target, int len){
	int i, j; int k = 0;int* a = (int*)malloc(2 * sizeof(int));
	if (nums != NULL&&len>0)
	{
		for (i = 0; i < len; i++)
		{
			for (j = 0; j < len; j++)
			{

				if ((nums[i] + nums[j]) == target)
				{
					k = 1;
					break;
				}
			}
			if (k == 1)
				break;
		}
		if (i < len)
		{
			if (nums[i] < nums[j])
			{
				a[0] = nums[i]; a[1] = nums[j];
			}
			else
			{
				a[0] = nums[j]; a[1] = nums[i];
			}
			return a;
		}
	}
	else
	return NULL;
}

/*
Sort the array first. Preferably using quicksort/mergesort. (nlogn)

Now the array is sorted, Can you do improve the above method.

Hint: 
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11. 

Lets say we added 3+12 first, whats the sum, Its 15 right ? Its greater than 11.So should we next add 
so that total sum will become less. 

What is the complexity of this method ? __________
*/
int* sumoftwoSortAndSearch(int *nums, int target, int len){
	//Sort the array
	int i, j, sum; int *a; a = (int*)malloc(2 * sizeof(int));
	if (nums != NULL&&len > 0)
	{
		b = (int *)malloc(len*sizeof(int));
		merge(nums, 0, len - 1, len);
		for (i = 0, j = len - 1; i <= j; i++, j--)
		{
			sum = nums[i] + nums[j];
			if (sum == target)
			{
				a[0] = nums[i]; a[1] = nums[j]; return a;
			}
			else if (sum > target)
				i--;
			else
				j++;
		}
	}
	else
		return NULL;
	//Do the task
	
}
void merge(int *nums, int low, int high,int len)
{
	int mid;
		if (low < high)
	{
		mid = (low + high) / 2;
		merge(nums, low, mid,len);
		merge(nums, mid + 1, high,len);
		mg(nums, low, mid,high);
	}
}
void mg(int *nums, int low, int mid, int high)
{
  int i = low, j =mid+1;int v = low;
	while (i <=mid &&j <=high)
	{
		if (nums[i] < nums[j])
			b[v++] = nums[i++];
		else
		{
			b[v++] = nums[j++];
		}
	}
	if (i == mid+1)
	{
		while (j <=high)
		{
			b[v++] = nums[j++];
		}
	}
	else  
	{
		while (i <=mid)
		{
			b[v++] = nums[i++];
		}
	}
	for (v = low; v <= high; v++)
	{
		nums[v] = b[v];
	}
}

/*

Array contains only integers from 1-100; Can you use this range restriction and an extra array to 
find 2Sum even more faster

Hint:
Lets say sorted array is [3,4,5,7,10,12] and required sum is 11.

If we are at 3, What number we need to tell that 3 is in final answer? 8 right (11-3 = 8). So some how we need to find a way
to know whether 8 is already in the array or not.As of now we dont know that, we will store 3 somewhere
(Which can be accesible in O(1)) and move to next element. 4 is there, we need to know whether array has 7 or not.(11-4 =7)
We dont know that yet, we move on ...we will store 4 somewhere now.

We go on till 7(4th element). We reach here we require 4 (11-7 = 4) .We already know 4 is present in array. (With O(1)).
We immediately return the answer. Think and discuss with your friends.

You are expected to solve this method in O(n)
*/
int* sumoftwoExtraArray(int *nums, int target, int len) {
	//Initialise the array
	//Do the task
	int a[101] = { 0 }; int i, j, k; int *c = (int*)malloc(2 * sizeof(int));
	if (nums != NULL&&len > 0)
	{
		for (i = 0; i < len; i++)
		{
			j = nums[i];
			if (j <= target)
			{
				a[j] = nums[i];
				k = target - nums[i];
				if (k > 0)
				{
					if (a[k] != 0)
						break;
				}
			}
			

		}
		if (i < len)
		{
			if (nums[i] < k)
			{
				c[0] = nums[i]; c[1] = k;
			}
			else
			{
				c[0] = k; c[1] = nums[i];
			}
			return c;
		}
		else return NULL;
	}
	else
	return NULL;
}


