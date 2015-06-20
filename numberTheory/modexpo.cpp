/*
	Modular Exponention
	https://en.wikipedia.org/wiki/Modular_exponentiation
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
const int MAX = 100;

lli modexpo(lli a, lli b)
{
	lli x = 1, y = a;
	while(b > 0)
	{
		if(b&1) x = (x*y)%MOD;
		y = (y*y)%MOD;
		b >>= 1;
	}
	return x;
}

int main()
{	
	cout << modexpo(2, 16) << endl;	//this prints (2^16) % MOD where MOD is 1e9+7
	return 0;
}
