#include<bits/stdc++.h>
#define VI vector<int>
#define all(c) c.begin(), c.end()
#define lli long long int
#define CLR(p) memset(p, 0, sizeof(p))
#define SET(p) memset(p, -1, sizeof(p))
using namespace std;

const int MAX = 3001;
int n;
vector< VI> graph;
int color[MAX], arr_time[MAX], LOW[MAX], pred[MAX];
int tym = 0;
bool art[MAX];

int Art_point(int src)
{
//    printf("doing dfs for %d\n",src );
    color[src] = 1;     //color gray

    LOW[src] = arr_time[src] = ++tym;

    for (int i = 0; i < graph[src].size(); ++i)
    {
        int w = graph[src][i];
        if(!color[w]) //if color is white or it is unvisited yet
        {
            pred[w] = src;
            Art_point(w);

            if(pred[src] == -1)
            {
                //v has no predecessor, so v is the root
                if(i >= 1)  //if 'w' is src's 2nd child or more, src is cut-vertex
                    art[src] = true;

            }
            else if(LOW[w] >= arr_time[src])
                art[src] = true;

            LOW[src] = min(LOW[src], LOW[w]);
        }
        else if(w != pred[src])
        {
            //(src,w) is a back-edge
            LOW[src] = min(LOW[src], arr_time[w]);
        }

    }
    color[src] = 2;
}

int main()
{
    int e, x, y;
    printf("Enter no of nodes(<100) and no of edges>>");
	scanf("%d %d",&n,&e);
    graph = vector<VI> (n);
    for (int i = 0; i < e; ++i)
    {
        scanf("%d %d",&x,&y);
        graph[x].push_back(y);
        graph[y].push_back(x);  //undirected graph
    }
    
    SET(pred);  //initialize pred array with -1
    
    memset(art, false, sizeof(art));

    Art_point(0);
/*
    printf("\n");
    printf("printing LOW array \n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ",LOW[i] );
    }
    printf("\n");


    printf("printing Arrival time array \n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ",arr_time[i] );
    }
    printf("\n");
*/
    printf("printing Art_point array \n");
    for (int i = 0; i < n; ++i)
    {
        printf("%d ",art[i]?1:0 );
    }
    printf("\n");
	return 0;
}    
