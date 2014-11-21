#include<bits/stdc++.h>
using namespace std;
#define pii pair< int, int>
#define pb push_back
#define INF (1<<20)
#define MAX 100001

vector< vector<pii>  > graph;
int nodes, edges;
int dist[MAX];
bool Finish[MAX];

void Dijikstra(int src)
{
	for(int i = 1; i <= nodes; i++)
		dist[i] = INF;
	dist[src] = 0;
	
	priority_queue< pii, vector< pii>, greater<pii>  > PQ;
	PQ.push(pii(0, src));
	int v, w;	

	while(!PQ.empty())
	{
		int u = (PQ.top()).second;
		PQ.pop();

		if(Finish[u]) 
			continue;

		int sz = graph[u].size();

		for(int i = 0; i < sz; i++)
		{
			v = graph[u][i].first;
			w = graph[u][i].second;
			
			if(!Finish[v] && dist[u] + w < dist[v])
			{
				dist[v] = dist[u] + w;
				PQ.push(pii(dist[v], v));
			}

		}
		Finish[u] = 1;

	}	
}

void view()
{
	for(int i = 0; i < nodes; i++)
	{
		for(int j = 0; j < graph[i].size(); j++)
		{
			printf("%d --- %d --->> %d\n",i, graph[i][j].second, graph[i][j].first);
		}
	}
}

int main()
{
	int x, y, wt, source;
	scanf("%d %d",&nodes, &edges);

	graph = vector< vector< pii >  > (nodes+1);	//initialize n+1 nodes in graph

	for(int i = 0; i < edges; i++)
	{
		scanf("%d %d %d",&x, &y, &wt);
		graph[x].pb( pii(y, wt) );
//		graph[y].pb( pii(x, wt) ); 	//for undirected graphs
	}
//	view();
	scanf("%d",&source);
	Dijikstra(source);
	
	printf("From %d to:\n", source);
	for(int i = 1; i <= nodes; i++)
		printf("Node = %d, min_weight_path = %d\n",i, dist[i]);
	return 0;
}
