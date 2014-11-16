#include<bits/stdc++.h>
using namespace std;
#define MAX 100001
#define VI vector< int >

int n, e;
vector< VI > graph;
int color[MAX];
int sets[MAX];
bool visited[MAX];

void color_graph(int src)
{
//	for(int i = 0; i < n; i++)
//		color[i] = sets[i] = -1;
	memset(color, -1, sizeof(color));
	memset(sets, -1, sizeof(sets));
	cout << sets[3] << " " << color[6] << endl;
	color[src] = sets[src] = 1;

	visited[src] = true;
	queue< int > Q;
	Q.push(src);

	while(!Q.empty())
	{
		int v = Q.front();
		Q.pop();

		for(VI::iterator it = graph[v].begin(); it != graph[v].end(); it++)
		{
			color[*it] = color[v]^1;	//just color alternate nodes with same color

			if(!visited[*it])
			{
				Q.push(*it);
				sets[*it] = sets[v]^1;	//put alternate nodes in same set
				visited[*it] = true;
			}
		}
	}
}

bool check_bipartite()
{
	VI V1, V2;
	for(int i = 0; i < n; i++)
	{	
		if(color[i] != sets[i])
			return false;
	}
	return true;
}


int main()
{
	int x, y;
	scanf("%d %d",&n, &e);
	graph = vector< VI > (n);
	for(int i = 0; i < e; i++)
	{
		scanf("%d %d",&x, &y);
		x--, y--;
		graph[x].push_back(y);
	}
	color_graph(0);
	if(check_bipartite())
		printf("graph is bipartite\n");
	else
		printf("graph is NOT bipartite\n");

	return 0;
}
