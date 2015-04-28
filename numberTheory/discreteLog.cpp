/*
	Discrete Logarithm
		Given a, b, m and gcd(a, m) = 1
		find solutions to a^x = b (mod m)

	Algo: Baby Step Giant Step, meet in the middle
	Complexity: O(root(m) * log(m))
	Author: Chandan Mittal
*/
#include<bits/stdc++.h>
#define lli long long
using namespace std;

lli modexpo(lli a, lli b, lli m)
{
	lli x = 1, y = a;
	while(b > 0)
	{
		if(b&1) 
			x = (x * y) % m;
		y = (y * y) % m
		b >>= 1;
	}
	return x % m;
}


VI solve(lli a, lli b, lli m)
{
	vector<lli> ans;
	lli n = (lli) sqrt(m + .0) + 1;
	map<lli, lli > vals;

	for(lli p = n; p >= 1; --p)
		vals[ modexpo(a, n * p, m) ] = p;
	for(lli q = 0; q <= n; q++)
	{
		lli cur = (modexpo(a, q, m) * b) % m;
		if(vals.cout(cur))
		{
			lli tmp = n * vals[cur] - q;
			if(tmp < m)
				ans.pb(tmp);
		}
	}
	return ans;
}


int main()
{
	
	return 0;
}
