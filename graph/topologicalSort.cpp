//Topological Sort in DAG
#include<stdio.h>
#include<vector>
#include<string.h>
#include<stack>
using namespace std;
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define CLRB(p)	memset(p , false, sizeof(p))

vector< vector<int> > graph;
const int MAX = 100;
int topo[200], dep_time[MAX], arr_time[MAX], tym;
bool visited[MAX];

void DFS_stack(int v)
{
	visited[v] = true;
	stack<int> S;
	S.push(v);

	while(!S.empty())
	{
		int cur = S.top();
		S.pop();
		
		printf("doing dfs for %d\n",cur);
		arr_time[cur] = tym++;
		for(vector<int>::iterator it = graph[cur].begin(); it != graph[cur].end(); it++ )
		{
			if(!visited[*it])
			{
				S.push(*it);
				visited[*it] = true;
			}
		}
		topo[tym] = cur;
		dep_time[cur] = tym++;
	}
}

void DFS_recur(int v)
{
//	printf("doing dfs for %d\n",v);
	arr_time[v] = tym++;
	visited[v] = true;
	for(vector<int>::iterator it = graph[v].begin(); it != graph[v].end(); it++)
	{
		if(!visited[*it])
		{
			DFS_recur(*it);
		}
	}
	topo[tym] = v;
	dep_time[v] = tym++;
}

int main()
{
	int n, m, x, y;
	scanf("%d %d",&n,&m);
	graph = vector<vector< int> > (n);
	for(int i = 0; i < m; i++)
	{
		scanf("%d %d",&x,&y);
		graph[x].push_back(y);
	}
//	printf("here\n");
	tym = 0;
	for(int i = 0; i <= 2*n; i++)
		topo[i] = -1;
//	DFS_stack(0);
	DFS_recur(0);
/*
	printf("printing departure time\n");
	for(int i = 0 ; i< n;i++)
	{
		printf("%d ",dep_time[i]);
	}
	printf("\n");
*/	
	printf("printing topo sort\n");
	for(int i = 2*n ; i > 0 ; i--)
	{
		if(topo[i] != -1)
		{
			printf("%d ",topo[i]);
		}
	}
	printf("\n");
	return 0;
}
