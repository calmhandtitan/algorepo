/*
	Single Source Shortest Path with negative edge weights
	Bellman Ford Algorithm
	Time Complexity: O(V*E)
	Author: Chandan Mittal
	handle: calmhandtitan
*/

#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define VI vector<int>
#define pii pair<int, int>
#define F first
#define S second
using namespace std;

const int MAX = 1010;
const int INF = 1<<30;

vector< pair<int, pii> > g;	//declare graph made of edges
int dist[MAX];
int n, e;

void printDist(int s)	
{
	printf("distance from vertex %d\n", s);
	for(int i = 0; i < n; i++)
		printf("%d\t%d\n", i, dist[i]);
}

void bFord(int s)
{
	for(int i = 0; i < n; i++)
		dist[i] = INF;
	dist[s] = 0;

	for(int i = 1; i < n; i++)	//loop n-1 times
	{	
		for(int j = 0; j < e; j++)	//loop over all edges
		{
			int u = g[j].S.F;
			int v = g[j].S.S;
			int w = g[j].F;

			if(dist[u]!=INF && dist[u] + w < dist[v])	//relax
				dist[v] = dist[u] + w;
		}
	}

	for(int j = 0; j < e; j++)
	{
		int u = g[j].S.F;
		int v = g[j].S.S;
		int w = g[j].F;

		if(dist[u] != INF && dist[v] > dist[u] + w)
		{
			printf("Graph has negative wt cycle\n");
		}
	}
	printDist(s);
}

int main()
{
	scanf("%d %d", &n, &e);

	//graph is not initialized as in the case of simple DFS or BFS

	int u, v, wt, s;
	for(int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &u, &v, &wt);
		u--, v--;		//assuming input nodes are 1-based indexed
		g.pb(mp(wt, mp(u, v)));	//edges are pushed in graph
	}

	scanf("%d", &s);	//get source vertex
	s--;
	bFord(s);		//call bellman Ford on source vertex

	return 0;
}
