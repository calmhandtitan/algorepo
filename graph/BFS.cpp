/*
	Breadth First Search
	Time complexity: O(V + E)
	handle: calmhandtitan
*/
#include<bits/stdc++.h>
using namespace std;
#define VI vector< int >
#define pb push_back
#define SZ(v) (v).size()

const int MAX = 1e5;	//maximum no of nodes graph can have

int n, e;
bool vis[MAX];
VI g[MAX];

void bfs(int s)
{
	vis[s] = 1;
	queue<int> q;
	q.push(s);
	
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
			
		for(int i = 0; i < SZ(g[u]); i++)
		{
			int v = g[u][i];
			if(!vis[v])
			{
				vis[v] = 1;
				q.push(v);
			}
		}
	}
}

int main()
{
	int x, y;
	scanf("%d %d", &n, &e);			//get number of nodes and edges
	for(int i = 0; i < e; i++)
	{
		scanf("%d %d", &x, &y);		//read edges
		x--, y--;
		g[x].pb(y);
		g[y].pb(x);					//make undirected graph
	}
	for(int i = 0; i < n; i++)		//graph may be disconnected
		if(!vis[i])
			bfs(i);

	return 0;
}
