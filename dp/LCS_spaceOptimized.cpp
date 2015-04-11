/*
	Longest Common Subsequence of 2 strings
*/

#include "bits/stdc++.h"
#define sd(n) scanf("%d", &(n))
#define rep(i, x, n) for (size_t i = x, _n = (n); i < _n; ++i)
#define SZ(c) (int)(c).size()
#define lcm(a,b) (a*(b/__gcd(a,b)))
#define VI vector<int>
#define all(c) ((c).begin(), (c).end())
#define pb push_back
#define pii pair<int, int>
#define pip pair<int, pii>
#define F first
#define S second
#define mp make_pair
#define lli long long int
#define CLR(p) memset(p, 0, sizeof(p))
#define SET(p) memset(p, -1, sizeof(p))
#define INF 0x3f3f3f3f
using namespace std;

const int MOD = 1e9+7;
const int MAX = 100010;

int dp[2][MAX];	//space required is 2 x N only

int LCS(string a, string b)	//an O(n^2) implementation
{
	int n = SZ(a);	
	int m = SZ(b);

	int k = 1;

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i-1] == b[j-1])
				dp[k][j] = 1 + dp[1-k][j-1];
			else
				dp[k][j] = max(dp[1-k][j], dp[k][j-1]);
		}
		k = 1 - k;
	}
	return dp[1-k][m];
}

int main()
{
	string a = "abcdef", b = "bde";
	cout << LCS(a, b) << endl;
	return 0;
}    



