#include<bits/stdc++.h>
using namespace std;

int kadane(int *a, int *start, int *end, int n)
{
	int maxSum = INT_MIN, sum = 0;
	*end = -1;
	int local_start = 0;
	for(int i = 0; i < n; i++)
	{
		//sum = max(0, sum + a[i]);
		//maxSum = max(maxSum, sum);
		sum += a[i];
		if(sum < 0)
		{
			sum = 0;
			local_start = i + 1;
		}
		else if(sum > maxSum)
		{
			maxSum = sum;
			*start = local_start;
			*end = i;
		}
	}
	if(*end != -1)
		return maxSum;
}

int main()
{
	int start, end;
	int a[] = {-1, -2, -3};
	int ans = kadane(a, &start, &end, 3 );
	cout << ans << endl;
	cout << start << " " << end << endl; 
	return 0;
}
