#include<bits/stdc++.h>
using namespace std;

int kadane(int *a, int n)
{
	/*
		returns the maximum sum subArray
		Complexity: O(n)
	*/
	int max_ending_here = a[0], max_so_far = a[0];
	for(int i = 1; i < n; i++)
	{
		max_ending_here = max(a[i], max_ending_here + a[i]);
		max_so_far = max(max_so_far, max_ending_here);
	}
	return max_so_far;
		
}

int main()
{
	int a[] = {2, -2, -1, 4, 0, -7, 8};
	int n = sizeof(a)/sizeof(int);
	int maxSumSubarray = kadane(a, n);
	cout << maxSumSubarray << endl;
	return 0;
}
