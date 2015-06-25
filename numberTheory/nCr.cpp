#include<bits/stdc++.h>
#define lli long long
using namespace std;

const int MOD = 1e9+7;
const int MAX = 200010;

//NOTE: factorial(30) doesn't fit in 64bit integer but
//	using below fn we can compute C(61, r) [this is the upperbound]

//IMP: No modulus here else life would have been much easier

lli C(int n, int r)	//calculates nCr in O(r) time 
{
	lli z = 1;
	for(int i = 0; i < r; i++)
		z = z * (n-i)/(i+1);
	return z;
}

int main()
{	
	//no precomputation required
	int n, r;
	scanf("%d %d", &n , &r);
	lli ans = C(n, r);
	printf("(%dC%d) is %lld\n", n, r, ans);

	return 0;
}
