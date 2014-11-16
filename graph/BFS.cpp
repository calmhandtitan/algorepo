#include<bits/stdc++.h>
using namespace std;
#define VI vector< int >

const int MAX = 1000;	//maximum no of nodes graph can have

int n, e;
int visited[MAX];
vector< VI > graph;

void BFS(int src)
{
	visited[src] = 1;
	queue< int > Q;
	Q.push(src);
	
	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		cout << cur+1 << " -> ";
			
		for(VI::iterator it = graph[cur].begin(); it != graph[cur].end(); it++)
		{
			if(!visited[*it])
			{
				visited[*it] = 1;
				Q.push(*it);
			}
		}
	}
	cout<<endl;
}

int main()
{
	int x, y;
	cin >> n >> e;
	graph = vector< VI > (n);
	for(int i = 0; i < e; i++)
	{
		cin >> x >> y;
		x--, y--;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	BFS(0);

	return 0;
}
