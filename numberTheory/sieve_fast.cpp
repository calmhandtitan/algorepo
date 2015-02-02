//sieves upto 10^8 in 0.5 sec, on core i5 CPU
//Algo: Sieve of Eratosthenes using bitmasks
#include <bits/stdc++.h>
#define i64 unsigned long long
using namespace std;
#define MAX 100000000
#define LMT 10000

unsigned flag[MAX/64];
unsigned primes[5761460], total;

#define chkC(n) (flag[n>>6] & (1<<((n>>1)&31)))
#define setC(n) (flag[n>>6] |= (1<<((n>>1)&31)))

void sieve()
{
    unsigned i, j, k;
    flag[0]|=0;
    for(i=3;i<LMT;i+=2)
        if(!chkC(i))    //if i is prime
            for(j=i*i,k=i<<1;j<MAX;j+=k)
                setC(j);

    primes[(j=0)++] = 2;
    
    for(i=3;i<MAX;i+=2)
        if(!chkC(i))    //if ith bit is clear/set to 0
            primes[j++] = i;
    total = j;
}

int main()
{
    sieve();
    return 0;
}
