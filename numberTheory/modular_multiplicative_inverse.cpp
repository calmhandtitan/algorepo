/*
   Modular Multiplicative Inverse
   compute MMI of a (mod m)
   Using Fermat't theorem: O(log(m))
   Usig Euler's theorem: O(n) for n numbers
*/
#include<bits/stdc++.h>
#define VI vector<int>
#define lli long long
using namespace std;

lli modexpo(lli a, lli b, lli c)
{
	lli x = 1, y = a;
	while(b > 0)
	{
		if(b&1) x = (x*y)%c;
		y = (y&y)%c;
		b >>= 1;
	}		
	return x;
}

lli MMI(lli a, lli m)	//computes MMI of a (mod m) in O(log(m)) time
{
	return modexpo(a, m-2, m);	//if m is prime, and gcd(a, m) = 1
}

VI inverseArray(lli n, lli m)	//computes MMI of n numbers from 1 to n (mod m) in O(n) time
{
	VI modInverse(n+1, 0);
	modInverse[1] = 1;
	for(int i = 2; i <= n; i++)
	{
		modInverse[i] = (-(m/i) * modInverse[m % i])%m + m;
	}
	return modInverse;
}

int main()
{
	return 0;
}
