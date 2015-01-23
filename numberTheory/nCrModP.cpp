#include<bits/stdc++.h>
#define lli long long
using namespace std;

const int MOD = 1e9+7;
const int MAX = 200010;

lli mod_expo(lli a, lli b)
{
	lli x = 1, y = a;
	while(b > 0)
	{
		if(b&1) x = (x*y)%MOD;
		y = (y*y)%MOD;
		b >>= 1;
	}
	return x;
}

lli fact[MAX], modFact[MAX];

void pre()	//calculates nCr mod P where P is prime(1e9+7) and P>n, in O(n) time
{
	fact[0] = 1;
	for(int i = 1 ; i <= MAX; i++)
		fact[i] = (i*fact[i-1])%MOD;
	
	
	modFact[0] = 1;
	
	for(int i = 1; i <= MAX; i++)
		modFact[i] = mod_expo(fact[i], MOD-2);
}

int main()
{	
	pre();	//do the MATH

	int n, r;
	scanf("%d %d", &n , &r);
	lli ans = fact[n];	
	ans = (ans*modFact[r])%MOD;
	ans = (ans*modFact[n-r])%MOD;
	printf("(%dC%d)%%%d is %lld\n", n, r,MOD, ans);

	return 0;
}
