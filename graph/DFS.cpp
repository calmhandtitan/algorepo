#include<bits/stdc++.h>
using namespace std;
#define VI vector<int>

const int MAX = 1000;	// maximum no of nodes in a graph

vector< VI > graph;
int visited[MAX];
int n, e;


void DFS(int v)
{
	visited[v] = 1;

	stack<int> S;
	S.push(v);
	
	while(!S.empty())
	{
		int cur = S.top();
		S.pop();
		printf("%d -> ",cur+1);
	
		for(VI::iterator it = graph[cur].begin(); it != graph[cur].end(); it++)
		{
			if(!visited[*it])
			{
				visited[*it] = 1;
				S.push(*it);
			}	
		}
	}
	printf("\n");
}


int main()
{
	int x, y;
	scanf("%d %d",&n, &e);
	graph = vector< VI > (n);
	for(int i = 0; i < e; i++)
	{
		scanf("%d %d",&x, &y);
		x--,y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	DFS(0);
	return 0;
}
