#include<bits/stdc++.h>
#define sd(n) scanf("%d", &(n));
#define SZ(s) (int)(s.size())
#define rep(i, x, n) for(int i = x, _n = n; i < _n; i++)
#define VI vector<int>
#define pb push_back
using namespace std;

const int MAX = 1010;

vector< VI > g;
bool visited[MAX], hasCycle;
int n, e;

void dfs(int v, int parent)
{
	visited[v] = 1;

	rep(i, 0, SZ(g[v]))
	{
		if(!visited[g[v][i]])
			dfs(g[v][i], v);
		else if(g[v][i] != parent)	//if we see a visited node other than cur node's parent
		{
			hasCycle = true;
			return;
		}
	}
}


int main()
{
	sd(n);	//get number of nodes
	sd(e);	//get number of edges

	g = vector< VI > (n);

	int u, v;
	rep(i, 0, e)
	{
		sd(u);
		sd(v);
		u--, v--;	//it is assumed that nodes entered are 1-based indexed
		g[u].pb(v);
		g[v].pb(u);
	}

	rep(i, 0, n)
	{
		if(!visited[i])
		{
			dfs(i, -1);
			if(hasCycle)
				break;
		}
	}

	if(hasCycle)
		printf("given undirected graph HAS A CYCLE\n");
	else
		printf("given undirected graph DOES NOT have any cycle\n");
	return 0;
}
