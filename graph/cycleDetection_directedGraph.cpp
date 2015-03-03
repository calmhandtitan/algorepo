#include<bits/stdc++.h>
#define sd(n) scanf("%d", &(n));
#define SZ(s) (int)(s.size())
#define rep(i, x, n) for(int i = x, _n = n; i < _n; i++)
#define VI vector<int>
#define pb push_back
using namespace std;

const int MAX = 1010;

vector< VI > g;
bool visited[MAX], used[MAX], hasCycle;
int n, e;

void dfs(int v)
{
	visited[v] = used[v] = 1;	//push node v in recursion stack

	rep(i, 0, SZ(g[v]))
	{
		if(used[g[v][i]])	//if we encounter a node which is already in stack
		{
			hasCycle = 1;
			return;	
		}
		else if(!visited[g[v][i]]);
			dfs(g[v][i]);
	}
	used[v] = 0;	//pop node v from stack as it's DFS is over
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
		g[u].pb(v);	//directed graph it is
	}

	rep(i, 0, n)
	{
		if(!visited[i])
		{
			dfs(i);
			if(hasCycle)
				break;
		}
	}

	if(hasCycle)
		printf("given directed graph HAS A CYCLE\n");
	else
		printf("given directed graph DOES NOT have any cycle\n");
	return 0;
}
