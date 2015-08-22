//SPOJ BUGLIGE solution
//check if given graph is bipartite or not
#include "stdio.h"
#include "queue"
#include "algorithm"
#include "string.h"
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define VI vector<int>
using namespace std;

vector<VI> graph;
VI colorArr;

int inline inp()
{
    int n=0;
    char c=getchar_unlocked();
    while(c < '0' || c >'9') {c=getchar_unlocked();}
    while(c>='0' && c<='9')
    {
        n=(n<<3)+(n<<1)+c-'0';
        c=getchar_unlocked();
    }
    return n;
}

bool check_bipartite(int src,int n)
{
//	printf("here\n");
	queue<int> Q;
	Q.push(src);
	
	
//	int colorArr[n];
	//value -1 of colorArr is used to indicate that no color is assigned yet
//	memset(colorArr, -1, sizeof(colorArr));
	colorArr[src] = 1;	//assign first color to source

	while(!Q.empty())
	{
		int i = Q.front(); //dequeue a vertex from queue
		Q.pop();

		for (VI::iterator it = graph[i].begin(); it != graph[i].end(); ++it)
		{
			if(colorArr[*it] == -1)
			{
				colorArr[*it] = 1 - colorArr[i];
				Q.push(*it);
			}
			else if(colorArr[*it] == colorArr[i])
				return false;
		}
	}
	return true;
}


int main()
{
	int n,m,p,q,t,iter=0;
	t = inp();
	while(t--)
	{
		n = inp();
		m = inp();

		graph = vector<VI> (n);
		colorArr = VI (n,-1);
		for (int i = 0; i < m; ++i)
		{
			p = inp();
			q = inp();
			p--;q--;
			graph[p].pb(q);
			graph[q].pb(p);
		}
		printf("Scenario #%d:\n",++iter);
		int j;
		for (j = 0; j < n; ++j)
		{
			if(colorArr[j] == -1)
				if(!check_bipartite(j,n))
				{
					printf("Suspicious bugs found!\n");
					break;
				}
		}
		if(j == n)
			printf("No suspicious bugs found!\n");	
/*		
		for (int i = 0; i < n; ++i)
		{
			printf("%d ",colorArr[i] );
		}
		printf("\n");
*/
	}
	
	return 0;
}
