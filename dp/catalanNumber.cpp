#include<stdio.h>

int CatalanNum_Recur(int n)	//A O(4^n) naive algorithm
{
	printf("n is %d\n",n);
	if(n == 0)
		return 1;
	int count = 0;
	for(int i = 1 ; i <= n ; i++)
		count += CatalanNum_Recur(i-1) * CatalanNum_Recur(n-i);

	return count;
}

const int MAX = 1024;
int dp[MAX];

int CatalanNum_DP(int n)	//A O(n^2) algorithm
{
	printf("n is %d\n",n);
//	if(n == 1)
//		return 1;
	if(dp[n] != 1)
		return dp[n];
	dp[n] = 0;
	for(int i = 1 ; i <= n ; i++)
		dp[n] += CatalanNum_DP(i - 1) * CatalanNum_DP(n - i);
	return dp[n];
}

int main()
{
/*
	printf("Printing Catalan Number using Recursion\n");
	for(int i = 1; i <= 50; i++)
		printf("%d ",CatalanNum_Recur(i));
	printf("\n");

*/
	for(int i = 0; i < MAX; i++)
		dp[i] = 1;

//	for(int i = 0 ; i < 100 ; i++)
//		printf("%d ",dp[i]);
//	printf("\n");

//	printf("Printing Catalan Number using DP\n");
//	for(int i = 1; i <= 50; i++)
//		printf("%d ",CatalanNum_DP(i));
//	printf("\n");
	printf("Cat(2) is %d\n",CatalanNum_DP(2));

	return 0;
}
