#include<bits/stdc++.h>
#define rep(i, x, n) for(int i = x, _n = n; i < _n; i++)
#define sd(n) scanf("%d", &n)
#define VI vector<int>
#define pb push_back
#define SET(n) memset(n, -1, sizeof(n))
#define CLR(n) memset(n, 0, sizeof(n))
using namespace std;

const int MAX = 100010;
int n, e;
vector<VI> graph;
int low[MAX], arrTime[MAX], parent[MAX];
bool visited[MAX];

void bridge(int u)
{
	static int time = 0;
	visited[u] = 1;

	arrTime[u] = low[u] = time++;

	for(VI::iterator it = graph[u].begin(); it != graph[u].end(); it++)
	{
		int v = *it;	//v is adjacent to u

		if(!visited[v])
		{
			parent[v] = u;
			bridge(v);

			low[u] = min(low[u], low[v]);

			if(low[v] > arrTime[u])	//u, v is bridge edge
			{
				cout << u << " -> " << v << " is a bridge\n";
			}
		}
		else if(v != parent[u])
			low[u] = min(low[u], arrTime[v]);
	}
}

int main()
{
	sd(n);	//get number of nodes
	sd(e);	//get number of edges
	graph = vector<VI> (n);	//initialize graph

	int x, y;
	rep(i, 0, e)
	{
		sd(x);
		sd(y);	
		//it is assumed that nodes are indexed from 0
		graph[x].pb(y);
		graph[y].pb(x);
	}	

	//clear the required arrays
	CLR(arrTime);
	CLR(low);
	CLR(visited);
	SET(parent);

	bridge(0);	//call the bridge procedure

	return 0;
}
