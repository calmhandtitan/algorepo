/*
	check if an edge is bridge or not in unidrected graph
	Complexity: O(V + E) per query
	handle: calmhandtitan	
*/
#include "bits/stdc++.h"
#define sd(n) scanf("%d", &(n))
#define rep(i, x, n) for (int i = x, _n = (n); i < _n; ++i)
#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
#define pra(v) repi(it, v) cout << *it << " "; cout << endl;
#define SZ(c) (int)(c).size()
#define lcm(a,b) (a*(b/__gcd(a,b)))
#define VI vector<int>
#define all(c) (c).begin(), (c).end()
#define allr(c) (c).rbegin(), (c).rend()
#define pb push_back
#define mii map<int, int>
#define pii pair<int, int>
#define pip pair<int, pii>
#define F first
#define S second
#define mp make_pair
#define lli long long int
#define llu unsigned long long
#define CLR(p) memset(p, 0, sizeof(p))
#define SET(p) memset(p, -1, sizeof(p))
#define INF 0x3f3f3f3f
#define pi 3.141592653589793
#define debug 0
using namespace std;

const int MOD = 1e9+7;
const int MAX = 1010;
const double eps = -1e8;

int n, m, x, y, q, g[MAX][MAX];
bool vis[MAX];

void dfs(int x)
{
	vis[x] = 1;
	rep(i, 0, n)
		if(g[x][i] and !vis[i])
			dfs(i);
}

int get(int x)
{
	dfs(x);
	int cnt = 0;
	rep(i, 0, n)
		if(vis[i]) cnt++;
	return cnt;
}

int main()
{
	ios_base::sync_with_stdio(0);
	sd(n);
	sd(m);
	rep(i, 0, m)
	{
		sd(x);
		sd(y);
		x--, y--;
		g[x][y] = g[y][x] = 1;
	}
	sd(q);
	while(q--)
	{
		sd(x);
		sd(y);
		x--, y--;	//check if edge x-y is bridge or not
		
		CLR(vis);
		int cnt1 = get(x);		//find number of vertices reachable from x
		g[x][y]--, g[y][x]--;	//delete edge x--y
		CLR(vis);
		int cnt2 = get(x);		//find number of vertices reachable from x
		g[x][y]++, g[y][x]++;	//recover
		
		if(cnt1 == cnt2)		//if no of vertices reachable reamins same
			printf("edge %d -- %d is not a bridge edge\n", x+1, y+1);
		else
			printf("edge %d -- %d is a bridge edge\n", x+1, y+1);
	}
    return 0;
}    
