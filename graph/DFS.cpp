/*
	Depth First Search
	Time complexity: O(V + E)
	handle: calmhandtitan
*/
#include<bits/stdc++.h>
using namespace std;
#define VI vector<int>
#define pb push_back
#define SZ(v) (v).size()

const int MAX = 1e5;	// maximum no of nodes in a graph

VI g[MAX];
bool vis[MAX];
int n, e;

void dfs(int u)
{
	vis[u] = 1;
	for(int i = 0; i < SZ(g[u]); i++)
	{
		int v = g[u][i];
		if(!vis[v])
			dfs(v);
	}
}

int main()
{
	int x, y;
	scanf("%d %d",&n, &e);	//get number of nodes and number of edges
	for(int i = 0; i < e; i++)
	{
		scanf("%d %d",&x, &y);
		x--,y--;
		g[x].pb(y);
		g[y].pb(x);		//make undirected graph
	}
	
	for(int i = 0; i < n; i++)
		if(!vis[i])		//graph may be disconnected
			dfs(i);
	return 0;
}
