/*
	All pair shortest path 
	Flloyd Warshall Algorithm
	Time Complexity: O(V^3)

	NOTE: 	works for both positive and negative edge wwights,
		but fails for negative cycles

*/
#include<bits/stdc++.h>
using namespace std;

const int MAX = 210;
const int INF = 1<<20;

int dist[MAX][MAX];	//dist matrix is n*n matrix
int n, e;	//n is no of nodes, e is no of edges


void init()
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i == j)
				dist[i][j] = 0;	//since there can't be self loops
			else
				dist[i][j] = INF;	//set all distances to INF
}	

void fWarshall()
{
	for(int k = 0; k < n; k++)
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);

}

void view()
{
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
			if(dist[i][j] == INF)
				printf("INF\t");
			else
				printf("%d\t", dist[i][j]);
		printf("\n");
	}
}


int main()
{
	scanf("%d %d", &n, &e);

	init();	//initialize distance matrix

	int u, v, wt;
	for(int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &u, &v, &wt);
		u--, v--;	//it is assumed that input nodes are 1-based indexed
		dist[u][v] = wt;
	}

	fWarshall();	//run flloydWarshall that takes O(n^3) time

	view();


	return 0;
}
