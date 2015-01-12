/*
	Linear Modular Equation
	Given a, b, c find x such that
	ax = b (mod c) and gcd(a, b, c) = 1

	then x = b*(a^phi(c)-1) (mod c)
*/
#include<bits/stdc++.h>
#define rep(i, x, n) for(size_t i = x, _n = n; i < _n; i++)
#define lli long long
using namespace std;

lli modexpo(lli a, lli b, lli c)	//computes a^b (mod c) in log2(b) time
{
	lli x = 1, y = a;
	while(b > 0)
	{
		if(b&1) x = (x*y)%c;
		y = (y*y)%c;
		b >>= 1;
	}	
	return x;
}

lli phi(lli n)
{
	lli result = n;
	for(lli i = 2; i*i <= n; i++)
	{
		if(n%i == 0)
		{
			result -= result/i;
			while(n%i == 0)
				n /= i;
		}
	}	
	if(n > 1)
		result -= result/n;
	return result;
}

int main()
{
	lli a, b, c;
	cin >> a >> b >> c;
	lli fic = phi(c);
	lli x = modexpo(a, fic-1, c);
	x = (x*b)%c;
	cout << x << endl;
	return 0;
}
