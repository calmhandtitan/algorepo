#include "bits/stdc++.h"
using namespace std;
#define VI vector<int>

const int MAXN = 1024;
int n;
vector< VI > graph;
bool visited[MAXN];
int parent[MAXN], Level[MAXN];
int P[MAXN][10];	//MAXN*log2(MAXN)

void bfs(int v)
{
	queue< int > Q;
	Q.push(v);
	parent[v] = v;
	Level[v] = 0;

	while(!Q.empty())
	{
		int cur = Q.front();
		Q.pop();
		visited[cur] = true;

		for (VI::iterator it = graph[cur].begin(); it != graph[cur].end(); ++it)
		{
			if(!visited[*it])
			{
				Q.push(*it);
				parent[*it] = cur;
				Level[*it] = Level[cur] + 1;
			}
		}
	}
}

void pre_LCA()
{
	for (int i = 0; i < n; i++)
        for (int j = 0; 1 << j < n; j++)
            P[i][j] = -1;		// Here, P[i][j] is 2j'th ancestor of i

	for (int i = 0; i < n; ++i)
		P[i][0] = parent[i];

	for (int j = 1; 1 << j < n; ++j)
		for (int i = 0; i < n; ++i)
			if(P[i][j-1] != -1)
				P[i][j] = P[P[i][j-1]][j-1];
			
}

int query_LCA(int p, int q)
{
	if(Level[p] < Level[q])
		swap(p, q);

  	int LOG = log2(Level[p]);

  	for (int i = LOG; i >= 0; --i)
  		if(Level[p] - (1<<i) >= Level[q])
  			p = P[p][i];

  	if(p == q)
  		return p;

  	for (int i = LOG; i >= 0; --i)
  		if(P[p][i] != -1 && P[p][i] != P[q][i])
  			p = P[p][i], q = P[q][i];
  		
  	return parent[p];
}

int main()
{
	int k, x, y;
	scanf("%d", &n);
	graph = vector< VI > (n);
	for (int i = 0; i < n-1; ++i)
	{
		scanf("%d %d", &x, &y);
		x--, y--;
		graph[x].push_back(y);
	}
	bfs(0);
	pre_LCA();

	
	scanf("%d", &k);	//no of queries
	while(k--)
	{
		scanf("%d %d", &x, &y);
		x--, y--;
		int ans = query_LCA(x, y);
		printf("%d\n", ans + 1);
	}

	return 0;
}