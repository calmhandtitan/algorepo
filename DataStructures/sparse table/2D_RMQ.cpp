/*
	2D Range minimum query using Sparse table
	Time Complexity: <O(N*M*logN*logM), O(1)>
	Space Complexity: O(N*M*logN*logM)	
*/
#include "bits/stdc++.h"
using namespace std;

const int MOD = 1e9+7;
const int MAX = 1<<10;

int a[MAX][MAX];
int table[MAX][10+2][MAX][10+2];	
/*
	table[i][x][j][y] is the minimum value from column j to j+2^y-1 in all rows from i to i+2^x-1
	in other words,
	table[i][x][j][y] is the minimum value in submatrix [ (i, j) to (i+2^x-1, j+2^y-1) ]
*/

/* we have to query submatrix [(x1, y1), (x2, y2)]*/
int query(int x1, int y1, int x2, int y2)
{
	int lenx = x2-x1+1;
	int leny = y2-y1+1;
	int kx = log2(lenx);
	int ky = log2(leny);

	int min_r1 = min(table[x1][kx][y1][ky], table[x1][kx][y2+1-(1<<ky)][ky]);
	int min_r2 = min(table[x2+1-(1<<kx)][kx][y1][ky], table[x2+1-(1<<kx)][kx][y2+1-(1<<ky)][ky]);
	return min(min_r1, min_r2);
}

int main()
{
	int t, n, m, q, x1, x2, y1, y2;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d", &n, &m);

		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				scanf("%d", &a[i][j]);
		

		for(int i = 0; i < n; i++)
		{		
			/* initialize table for submatrix of size 1x1 */
			for(int j = 0; j < m; j++)
				table[i][0][j][0] = a[i][j];	
				
			/* compute sparse table for each row; takes O(N*M*logM) */
			for(int y = 1; y <= log2(m); y++)
				for(int j = 0; j + (1<<(y-1)) < m; j++)
					table[i][0][j][y] = min(table[i][0][j][y-1], table[i][0][j + (1<<(y-1))][y-1]);
		}

		/* now build entire sparse table */
		for(int x = 1; x <= log2(n); x++)
			for(int i = 0; i < n; i++)
				for(int y = 0; y <= log2(m); y++)
					for(int j = 0; j  < m; j++)
						table[i][x][j][y] = min(table[i][x-1][j][y], table[i + (1<<(x-1))][x-1][j][y]);
				

		scanf("%d", &q);		
		while(q--)
		{
			scanf("%d %d", &x1, &y1);	/* we get 1 based indexes here */
			scanf("%d %d", &x2, &y2);
			x1--, y1--, x2--, y2--;		/* so need to decrease it by 1 */
			
			int ans = query(x1, y1, x2, y2);										
			printf("%d\n", ans);
		}	
	}
    return 0;
}    
