#include<bits/stdc++.h>
using namespace std;
#define INF 1<<29
/*
   given infinite supply of some denominations of coins, 
   and a value V to be paid, tell
   the minimum number of coins needed to pay value V
*/


int CoinChange(int *coinValue, int n, int V)
{
	int coins[V+1];
	//coins[j] is the minimum no of coins needed to pay 'j' dollars
	fill(coins, coins + V+1, INF);
	
	coins[0] = 0;
	for(int i = 0; i < n; i++)
		for(int j = coinValue[i]; j <= V; j++)
				coins[j] = min(coins[j], 1 +  coins[j - coinValue[i]]);

	return coins[V];
}

int main()
{
	int coinValue[] = {1, 2, 5, 10};
	int value;
	cin >> value;
	int ans = CoinChange(coinValue, 4, value);
	cout << ans << endl;
	return 0;
}
