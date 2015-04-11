/*
	Gaussian Elimination
	Time Complexity: O(n^3)
	handle: calmhandtitan
*/
#include <bits/stdc++.h>
using namespace std;

const int MAX = 110;

int n;
double a[MAX][MAX];
double x[MAX];

void read_matrix()
{
	scanf("%d", &n);	//get the size of the matrix N x N

	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= (n+1); j++)		//note the indexing is 1-based
			scanf("%lf", &a[i][j]);	//read the augmented matrix
	}
}

void gauss_elim() // complexity: O(n^3)
{
	//generating upper triangular matrix
	for(int j = 1; j <= n ; j++)
	{
		for(int i = 1; i <= n; i++)
		{
			if(i > j)
			{
				double c = a[i][j] / a[j][j];
				for(int k = 1; k <= n+1; k++)
					a[i][k] = a[i][k] - c*a[j][k];
			}
		}
	}
	
	//now doing backward substitution
	x[n] = a[n][n+1] / a[n][n];

	double sum = 0.0;

	for(int i = n-1; i >= 1; --i)
	{
		sum = 0;

		for(int j = i+1; j <= n; j++)
		{
			sum += a[i][j] * x[j];
		}
		x[i] = (a[i][n+1] - sum) / a[i][i];
	}

	printf("soln is: \n");
	for(int i = 1; i <= n; i++)
	{
		printf("x%d = %lf\n", i, x[i]);
	}
	
}

int main()
{
	read_matrix();
	gauss_elim();
}
