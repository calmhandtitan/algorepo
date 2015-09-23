/*
	Inversion Count
	Algo: Binary Indexed Tree
	Time Complexity: O(NlogN)
	handle: calmhandtitan
*/
#include "bits/stdc++.h"
#define sd(n) scanf("%d", &(n))
#define rep(i, x, n) for (int i = x, _n = (n); i < _n; ++i)
#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
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
#define debug 0
using namespace std;

const int MOD = 1e9+7;
const int MAX = 100010;

int n, a[MAX], b[MAX];
lli BIT[MAX];

void update(int x, int v)
{
	while(x <= n)
	{
		BIT[x] += v;
		x += x & (-x);
	}
}

lli read(int x)
{
	lli s = 0;
	while(x > 0)
	{
		s += BIT[x];
		x -= x & (-x);
	}
	return s;
}

int main()
{
	ios_base::sync_with_stdio(0);
	sd(n);
	
	rep(i, 0, n)
	{
		sd(a[i]);
		b[i] = a[i];
	}
	sort(b, b+n);
	rep(i, 0, n)
	{
		int id = lower_bound(b, b+n, a[i]) - b;
		a[i] = id+1;
	}
	CLR(BIT);
	lli ans = 0;
	for(int i = n-1; i >= 0; --i)
	{
		ans += read(a[i]-1);
		update(a[i], 1);
	}
	printf("%d\n", ans);
    return 0;
}    
