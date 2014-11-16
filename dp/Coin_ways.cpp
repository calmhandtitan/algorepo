#include<bits/stdc++.h>
using namespace std;
#define MAXV 100000
/*
	Given n denominations of coins, tell
	the number of ways of paying any amount V,
	using different combinations of coin denominations
	Each query can be answered in O(1) after preprocessing

*/

long long ways[MAXV];
int Count_ways(int *coins, int n)
{
	//ways[i] is number of ways of paying amount 'i 

	fill(ways, ways + MAXV, 0);
	ways[0] = 1;	//# of ways of paying 0 dollar is 1

	for(int i = 0; i < n; i++)
		for(int j = 0; j < MAXV; j++)
			if( j >= coins[i])
				ways[j] += ways[j - coins[i]];
}

int main()
{
	int deno[] = {5, 10, 20, 50}; 
	int n = sizeof(deno)/sizeof(int);
	Count_ways(deno, n);

	int value;
	cin >> value;
	cout << ways[value] << endl;

	return 0;
}
