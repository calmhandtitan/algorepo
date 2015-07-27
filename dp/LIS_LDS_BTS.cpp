//amazing takes time, legendary requires patience
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
const int MAX = 1010;

int a[MAX], dp1[MAX], dp2[MAX];
//dp1[i]  is the longest increasing subsequence till index i
//dp2[i]  is the longest decreasing subsequence till index i
int n;

int main()
{
	ios_base::sync_with_stdio(0);
	int t;
	sd(t);
	while(t--)
	{
		sd(n);
		rep(i, 1, n+1)
			sd(a[i]);
			
		rep(i, 1, n+1)
			dp1[i] = dp2[i] = 1;
			
		rep(i, 1, n+1)
			rep(j, i+1, n+1)
				if(a[j] > a[i])	//note it is strictly increasing 
					dp1[j] = max(dp1[j], dp1[i]+1);
					
					
		for(int i = n; i >= 1; --i)		//notice both the loops are iterated backwards
			for(int j = i-1; j >= 1; --j)	
				if(a[j] > a[i])	//condition remains the same, note it is strictly decreasing 
					dp2[j] = max(dp2[j], dp2[i]+1);			
					
		int ans = 1;
		rep(i, 1, n+1)
			ans = max(ans, dp1[i] + dp2[i] - 1);	//find longest bitonic sequence
		cout << ans << endl;
	}
    return 0;
}    
