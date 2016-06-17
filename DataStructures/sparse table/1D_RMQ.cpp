/*
	1D Range minimum query using Sparse table
	Time Complexity: <O(NlogN), O(1)>
	Space Complexity: O(NLogN)	
*/
#include "bits/stdc++.h"
using namespace std;

const int MOD = 1e9+7;
const int MAX = 100010;

int a[MAX];
int table[1<<20][20];	/* table[i][j] is the index of minimum value in sub array starting at i having length 2^j */

int main()
{
	int t, n, q, x, y;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d", &n);
		scanf("%d", &q);
		for(int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		
		/* initialize table for interval with length 1 */
		for(int i = 0; i < n; i++)
			table[i][0] = i;	
		/* compute values from smaller to bigger intervals */
		for(int j = 1; (1<<j) <= n; j++)
		{
			for(int i = 0; i + (1<<j) - 1 < n; i++)
			{
				if(a[table[i][j-1]] < a[table[i + (1 << (j-1))][j-1]])
					table[i][j] = table[i][j-1];
				else
					table[i][j] = table[i + (1 << (j-1))][j-1];
			}
		}
		while(q--)
		{
			scanf("%d", &x);	/* we get 1 based indexes here */
			scanf("%d", &y);
			x--, y--;		/* so need to decrease it by 1 */
			
			int len = y-x+1;
			int k = log2(len);	/* remember log is taken in base 2*/
			
			/*	int k = 31 - __builtin_clz(j-i+1);	
				31 - leading_zeros in binary of (j-i+1)
				does the same job as log2(j-i+1)
			*/
			
			/* for query we select 2 blocks that entirely cover the interval [i..j] */
			int ansIdx = min(table[x][k], table[y + 1 - (1<<k)][k]);
							
			printf("%d\n", a[ansIdx]);
		}	
	}
    return 0;
}    
