#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pip pair<int, pii>
#define F first
#define S second
#define MAX 10010

class Union_Find
{
	int parent[MAX], sz[MAX];
	public:
		Union_Find(int n)
		{
			for(int i = 0; i <= n; i++)
			{
				parent[i] = i;
				sz[i] = 1;
			}
		}

		int root(int i)
		{
			while(i != parent[i])
			{
				parent[i] = parent[parent[i]];
				i = parent[i];
			}
			return i;
		}

		int find(int p, int q)
		{
			return root(p) == root(q);
		}

		int unite(int p, int q)
		{
			int i = root(p);
			int j = root(q);
			
			if(sz[i] < sz[j])
			{
				parent[i] = parent[j];
				sz[j] += sz[i];
			}
			else
			{
				parent[j] = parent[i];
				sz[i] += sz[j];
			}
		}


};

vector< pip > graph;
int nodes, edges;

void view()
{
	int sz = graph.size();
	for(int i = 0; i< sz; i++)
	{
		printf("%d ---%d--->> %d\n",graph[i].S.F, graph[i].F, graph[i].S.S);
	}
}

long long Kruskal_MST()
{
	Union_Find UF(nodes+1);
	long long T = 0;
	int u, v;

	for(int i = 0; i < edges; i++)
	{
		u = graph[i].S.F;
		v = graph[i].S.S;
		if(!UF.find(u,v ))	
		{
			UF.unite(u, v);
			T += graph[i].F;
		}
	}
	return T;
}

int main()
{
	int u, v, wt;
	scanf("%d %d",&nodes, &edges);

	for(int i = 0;i < edges; i++)
	{
		scanf("%d %d %d",&u, &v, &wt);
		graph.push_back(pip(wt, pii(u,v)));
	}
	sort(graph.begin(), graph.end());

	view();

	long long ans = Kruskal_MST();
	printf("Length of MST is %lld\n",ans);
	return 0;
}
