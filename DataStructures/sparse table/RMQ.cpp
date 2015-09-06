/*
	Range minimum query
	Sparse table
	Time Complexity: <O(NlogN), O(1)>
	Space Complexity: O(NLogN)	
*/
#include "bits/stdc++.h"
#define sd(n) scanf("%d", &(n))
#define rep(i, x, n) for (int i = x, _n = (n); i < _n; ++i)
#define repV(i, v) for (i = v.begin(); i != v.end(); i++)
#define SZ(c) (int)(c).size()
#define lcm(a,b) (a*(b/__gcd(a,b)))
#define VI vector<int>
#define all(c) (c).begin(), (c).end()
#define pb push_back
#define mii map<int, int>
#define pii pair<int, int>
#define pip pair<int, pii>
#define F first
#define S second
#define mp make_pair
#define lli long long int
#define CLR(p) memset(p, 0, sizeof(p))
#define SET(p) memset(p, -1, sizeof(p))
#define INF 0x3f3f3f3f
#define pi 3.14159265358979
using namespace std;

const int MOD = 1e9+7;
const int MAX = 100010;

int a[MAX];
int m[1<<20][20];

int main()
{
	ios_base::sync_with_stdio(0);
	int t, ts = 0, n, q;
	sd(t);
	while(t--)
	{
		ts++;
		sd(n);
		sd(q);
		rep(i, 0, n)
			sd(a[i]);
		
		//m[i][j] is the index of minimum value in sub array starting at i having length 2^j
		//initialize m for interval with length 1
		rep(i, 0, n)
			m[i][0] = i;	
		//compute values from smaller to bigger intervals
		for(int j = 1; (1<<j) <= n; j++)
		{
			for(int i = 0; i + (1<<j) - 1 < n; i++)
			{
				if(a[m[i][j-1]] < a[m[i + (1 << (j-1))][j-1]])
					m[i][j] = m[i][j-1];
				else
					m[i][j] = m[i + (1 << (j-1))][j-1];
			}
		}
		printf("Scenario #%d:\n", ts);
		int i, j;
		while(q--)
		{
			sd(i);	//we get 1 based indexes here
			sd(j);
			i--, j--;	//so need to decrease it by 1
			
			int k = log2(j-i+1);	//remember log is taken in base 2
//			int k = 31 - __builtin_clz(j-i+1);	//31 - leading_zeros in binary of (j-i+1)
			//does the same job as log2(j-i+1)
			
			//for query we select 2 blocks that entirely cover the interval [i..j]
			int ans;
			if(a[m[i][k]] <= a[m[j - (1<<k) + 1][k]])
				ans = m[i][k];
			else
				ans = m[j - (1<<k) + 1][k];
							
			printf("%d\n", a[ans]);
		}	
	}
	
    return 0;
}    
