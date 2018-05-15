/*
Here you will compare 2 searching algorithms.

LinearSearch and BinarySearch

Question :
Given an Array and its length and a key element, return the index (Where key is found) if key is found in array
or -1 if key is not found.

Sample Input : 
[1,2,3,4,5] Key : 4, Returns 3
[0,49,22] Key : 212, Returns -1

Observations: (Write down what you observed here, Run for various variations):

Linear Search:

Binary Search :

Conclusion :
*/
int bs(int *arr, int low, int high, int key);
int linearSearch(int *arr, int len, int key) {
	int i;
	for ( i = 0; i < len; i++)
	{
		if (arr[i] == key)
			break;
	}
	if (i < len)
		return i;
	else
	return -1;
}



int binarySearch(int *arr, int len, int key) {
	//Use this function as wrapper function,if you are implementing bs recursively.
	int low=0, high=len-1,mid,k;
	k=bs(arr, low, high, key);
	if (k != -1)
		return k;
	else
	return -1;
}

int bs(int *arr, int low, int high, int key)
{
	if (low <= high)
	{
		int mid = (low + high) / 2;
		if (arr[mid] == key)
		{
			return mid;
		}
		else if (arr[mid] > key)
		{
			return bs(arr, low, mid - 1, key);
		}
		else
		{
			return bs(arr, mid + 1, high, key);
		}
	}
	else
		return -1;
}