/*
	Finding Strongly Connected Components
	Kosaraju's 2 pass algorithm
	Time Complexity: O(V+E)
	Author: Chandan Mittal
	handle: calmhandtitan
*/

#include<bits/stdc++.h>
#define SZ(c) (int)((c).size())
#define VI vector<int>
#define pb push_back
#define CLR(p) memset(p, 0, sizeof (p))
using namespace std;


const int MAX = 100010;

int n, e;
bool visited[MAX];
vector<VI> g, gr;	//declare 2 graphs
stack<int> s;

void dfs1(int u)	//simple dfs on original graph
{
	visited[u] = 1;
	for(int v = 0; v < SZ(g[u]); v++)
		if(!visited[g[u][v]])
			dfs1(g[u][v]);
			
	s.push(u);	//store the nodes acc to there finish time
}

void dfs2(int u)	//simple dfs on transpose graph
{
	visited[u] = 1;
	printf("%d ", u);	//print the nodes in an SCC
	
	for(int v = 0; v < SZ(gr[u]); v++)
		if(!visited[gr[u][v]])
			dfs2(gr[u][v]);
}

void kosaraju_SCC()	//O(n+e) algo to find SCC's in a graph
{
	//first pass starts here
	CLR(visited);
		
	for(int i = 0; i < n; i++)
		if(!visited[i])
			dfs1(i);
	
	//second pass starts here
	CLR(visited);
	
	while(!s.empty())
	{
		int v = s.top();
		s.pop();
		
		if(!visited[v])
		{
			dfs2(v);
			printf("\n");
		}
	}	
}

int main()
{
	scanf("%d %d", &n, &e);	//get the number of nodes, and edges
	g = vector< VI > (n);
	gr = vector< VI > (n);	//init the transpose graph also
	
	int u, v;
	for(int i = 0; i < e; i++)
	{
		scanf("%d %d", &u, &v);
		u--, v--;	//it is assumed that input nodes are 1-based indexed
		g[u].pb(v);
		gr[v].pb(u);	//create the transpose graph 
	}
	kosaraju_SCC();
	return 0;
}
