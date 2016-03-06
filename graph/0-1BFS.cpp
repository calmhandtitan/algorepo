/*
	Given a weighted graph G with V vertices and E edges.
	Edge weights can only be 0 and x(x >= 0)
	Find single source shortest path from source vertex.

	Algo: BFS
	Time Complexity: O(E+V)
*/
#include "bits/stdc++.h"
#define sd(n) scanf("%d", &(n))
#define rep(i, x, n) for (int i = x, _n = (n); i < _n; ++i)
#define repi(i, a) for(typeof((a).begin()) i = (a).begin(), _##i = (a).end(); i != _##i; ++i)
#define SZ(c) (int)(c).size()
#define pra(v, n) rep(i, 0, n) cout << v[i] << " "; cout << endl;
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
#define llu unsigned long long
#define CLR(p) memset(p, 0, sizeof(p))
#define SET(p) memset(p, -1, sizeof(p))
#define INF 0x3f3f3f3f
#define pi 3.14159265358979
#define debug 0
using namespace std;

const int MOD = 1e9+7;
const int eps = 1e-8;
const int MAX = 100010;

int n, m;
vector< pii> g[MAX];
int dist[MAX];

void bfs(int src)
{
	rep(i, 0, n)
		dist[i] = INF;
	dist[src] = 0;

	deque<int> d;
	d.push_front(src);

	while(!d.empty())
	{
		int u = d.front();
		d.pop_front();

		rep(i, 0, SZ(g[u]))
		{
			int v = g[u][i].F;
			int w = g[u][i].S;
			if(dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				if(w == 1)			//assuming edge-weights are 0 and 1
					d.push_back(v);
				else
					d.push_front(v);
			}
		}
	}

}

int main()
{
	ios_base::sync_with_stdio(0);
	int a, b, w;
	cin >> n >> m;
	rep(i, 0, m)
	{
		cin >> a >> b >> w;
		a--, b--;			//make nodes 0-based index
		g[a].pb(pii(b, w));
		g[b].pb(pii(a, w));
	}
	int src;
	cin >> src;
	bfs(src-1);

	rep(i, 0, n)
		cout << dist[i] << " ";
	cout << endl;
    return 0;
}    
