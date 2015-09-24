/*
	Lowest common ancestor
	Time complexity: <O(NlogN), O(logN)>
	Algo: dfs + ancestor + dep time
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
#define pi 3.14159265358979
#define debug 0
using namespace std;

const int MOD = 1e9+7;
const int MAX = 100010;

VI g[MAX];
int tin[MAX], tout[MAX], timer, dep[MAX];
int up[MAX][20];

void clear()
{
	rep(i, 0, MAX)
		g[i].clear();
	timer = 0;
	CLR(tin);
	CLR(tout);
	CLR(dep);
	CLR(up);
}

void dfs(int s, int p)
{
	tin[s] = timer++;
	up[s][0] = p;
	rep(i, 1, 19)		//up[s][i] is 2^i'th ancestor of s
		up[s][i] = up[up[s][i-1]][i-1];		//precompute ancestors for each node
	rep(i, 0, SZ(g[s]))
	{
		int v = g[s][i];
		if(v == p) continue;
		dep[v] = dep[s] + 1;
		dfs(v, s);
	}
	tout[s] = timer++;
}

bool upper(int a, int b)	//return true if a is ancestor of b
{
	return (tin[a] <= tin[b] and tout[a] >= tout[b]);
}

int lca(int a, int b)	//return lca of a and b
{
	if(upper(a, b))
		return a;
	if(upper(b, a))
		return b;
	for(int i = 18; i >= 0; i--)
		if(!upper(up[a][i], b))
			a = up[a][i];
	return up[a][0];
}

int getdist(int a, int b)	//return distance between 2 nodes a and b
{
	int q = lca(a, b);
	return dep[a] + dep[b] - 2*dep[q];
}

int main()
{
	ios_base::sync_with_stdio(0);
	int n, u, v, q;
	scanf("%d", &n);	//get the number of nodes in tree
	clear();			//clear the arrays
	rep(i, 1, n)		//read the tree edges
	{
		scanf("%d %d", &u, &v);
		u--,v--;
		g[u].pb(v);
		g[v].pb(u);		//make undirected graph
	}
	dfs(0, 0);
	
	scanf("%d", &q);	//read the number of LCA queries
	while(q--)
	{
		scanf("%d %d", &u, &v);	//nodes are 1-based indexed here
		u--, v--;
		printf("LCA of %d and %d is %d\n", u+1, v+1, lca(u, v)+1);
	}
    return 0;
}    
