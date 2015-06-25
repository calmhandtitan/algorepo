#include<bits/stdc++.h>
#define lli long long
using namespace std;

const int MOD = 1e9+7;
const int MAX = 1010;

lli c[MAX][MAX];
void pre()	//calculates nCr % P using pascals triangle in O(n^2) time 
{
	c[0][0] = 1;
	for(int i = 1; i < MAX; i++)
	{
		c[i][0] = 1;
		for(int j = 1; j <= i; j++)
			c[i][j] = (c[i-1][j-1] + c[i-1][j]) % MOD;
	}
}

int main()
{	
	pre();	//do the MATH

	int n, r;
	scanf("%d %d", &n , &r);
	
	printf("(%dC%d)%%%d is %lld\n", n, r,MOD, c[n][r]);

	return 0;
}
