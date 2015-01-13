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

int LCS(string a, string b)	//O(n^2) implementation of LCS
{
    int m = a.size(), n = b.size();
    int dp[m+1][n+1];

    for (int i = 0; i <= m; ++i)
    {
        for (int j = 0; j <= n; ++j)
        {
            if(i == 0 || j == 0)
                dp[i][j] = 0;
            else if(a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    return dp[m][n];

}

int main()
{
	string a = "abcdef", b = "bde";
	cout << LCS(a, b) << endl;
	return 0;
}    



