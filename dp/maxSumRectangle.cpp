#include<bits/stdc++.h>
using namespace std;
#define MAXROW 4
#define MAXCOL 5

int kadane(int *a, int n)
{
	/*
		returns the maximum sum subArray
		Complexity: O(n)
	*/
	int max_ending_here = a[0], max_so_far = a[0];
	for(int i = 0; i < n; i++)
	{
		max_ending_here = max(a[i], max_ending_here + a[i]);
		max_so_far = max(max_so_far, max_ending_here);
	}
	return max_so_far;
}
int M[MAXROW][MAXCOL];

int maxSumRect(int ROW, int COL)
{
	/*
		returns the maximum Sum Rectangle in a 2-D Matrix M
		Complexity:	O(n^3)
	*/
	int maxSum = 0;
	int temp[ROW];
	for(int left = 0; left < COL; left++)
	{
		fill(temp, temp + ROW, 0);
		for(int right = left; right < COL; right++)
		{
			for(int i = 0; i < ROW; i++)
				temp[i] += M[i][right];

			int sum = kadane(temp, ROW);
			maxSum = max(sum, maxSum);
		}
	}
	return maxSum;
}

int main()
{
	int ROW = 4, COL = 5;
	for(int i = 0; i < ROW; i++)
		for(int j = 0; j < COL; j++)
			scanf("%d ", &M[i][j]);
	int ans = maxSumRect(ROW, COL);
	printf("%d\n", ans);
	return 0;
}
